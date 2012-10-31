#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cassert>
#include <cmath>

// support for multitexturing
#define GL_TEXTURE0_ARB 0x84C0
#define GL_TEXTURE1_ARB 0x84C1
#define GL_COMBINE 0x8570
#define GL_COMBINE_RGB 0x8571
#define GL_COMBINE_ALPHA 0x8572
#define GL_RGB_SCALE 0x8573
#define GL_INTERPOLATE 0x8575
#define GL_CONSTANT 0x8576
#define GL_PRIMARY_COLOR 0x8577
#define GL_PREVIOUS 0x8578
#define GL_SOURCE0_RGB 0x8580
#define GL_SOURCE1_RGB 0x8581
#define GL_SOURCE2_RGB 0x8582
#define GL_SOURCE0_ALPHA 0x8588
#define GL_SOURCE1_ALPHA 0x8589
#define GL_SOURCE2_ALPHA 0x858A
#define GL_OPERAND0_RGB 0x8590
#define GL_OPERAND1_RGB 0x8591
#define GL_OPERAND2_RGB 0x8592
#define GL_OPERAND0_ALPHA 0x8598
#define GL_OPERAND1_ALPHA 0x8599
#define GL_OPERAND2_ALPHA 0x859A
typedef void (__stdcall *PFNGLCLIENTACTIVETEXTUREARBPROC)(GLenum);
PFNGLCLIENTACTIVETEXTUREARBPROC glClientActiveTextureARB = NULL;
typedef void (__stdcall *PFNGLACTIVETEXTUREARBPROC)(GLenum);
PFNGLACTIVETEXTUREARBPROC glActiveTextureARB = NULL;

// window dimensions
static int gs_iWidth = 640;
static int gs_iHeight = 480;
static HDC gs_hWindowDC = (HDC)0;

// view frustum
static double gs_fLFrustum = -0.5500;
static double gs_fRFrustum = +0.5500;
static double gs_fBFrustum = -0.4125;
static double gs_fTFrustum = +0.4125;
static double gs_fNFrustum = +1.0;
static double gs_fFFrustum = +100.0;

// viewport
static int gs_iXPort = 0;
static int gs_iYPort = 0;
static int gs_iWPort = gs_iWidth;
static int gs_iHPort = gs_iHeight;

// camera world coordinates
static double gs_adEye[3] = { 0.0, 0.0, 4.0 };
static double gs_adDir[3] = { 0.0, 0.0, -1.0 };
static double gs_adUp[3] = { 0.0, 1.0, 0.0 };
static double gs_adRight[3] = { 1.0, 0.0, 0.0 };

// triangle mesh
static int gs_iVQuantity = 0;                 // number of vertices
static float* gs_afVertex = NULL;             // vertex positions
static float* gs_afUV = NULL;                 // shared texture coordinates
static int gs_iImageW0 = 0;                   // primary image width
static int gs_iImageH0 = 0;                   // primary image height
static unsigned char* gs_aucImage0 = NULL;    // primary image (RGB)
static unsigned int gs_uiID0 = 0;             // binding id for graphics card
static int gs_iImageW1 = 0;                   // secondary image width
static int gs_iImageH1 = 0;                   // secondary image height
static unsigned char* gs_aucImage1 = NULL;    // secondary image (RGB)
static unsigned int gs_uiID1 = 0;             // binding id for graphics card
static int gs_iIQuantity = 0;                 // number of indices
static int* gs_aiIndex = NULL;                // index array (triples of int)
static bool gs_bUseSecondaryTexture = true;  // toggle secondary texture

// translation vector for triangle
static float gs_afTranslate[3] =
{
    0.0f, 0.0f, 0.0f
};

// rotation matrix for triangle
static float gs_aafRotate[3][3] =
{
    {1.0f, 0.0f, 0.0f},
    {0.0f, 1.0f, 0.0f},
    {0.0f, 0.0f, 1.0f}
};

// transformation matrix for triangle (in OpenGL format)
static float gs_afMatrix[16] =
{
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

// for incremental translations
static float gs_fDPosition = 0.1f;

// for incremental rotations
static float gs_afAngle = 0.1f;
static float gs_fCos = cosf(gs_afAngle);
static float gs_fSin = sinf(gs_afAngle);

//----------------------------------------------------------------------------
static bool LoadBmp24 (const char* acFilename, int& riWidth, int& riHeight,
    unsigned char*& raucData)
{
    HBITMAP hImage = (HBITMAP) LoadImage(NULL,acFilename,IMAGE_BITMAP,0,0,
        LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    if ( !hImage )
        return false;

    DIBSECTION dibSection;
    GetObject(hImage,sizeof(DIBSECTION),&dibSection);

    riWidth = dibSection.dsBm.bmWidth;
    riHeight = dibSection.dsBm.bmHeight;
    int iQuantity = dibSection.dsBm.bmWidth*dibSection.dsBm.bmHeight;
    if ( dibSection.dsBm.bmBitsPixel != 24 )
        return false;

    // Windows BMP stores BGR, need to invert to RGB.
    unsigned char* aucSrc = (unsigned char*) dibSection.dsBm.bmBits;
    raucData = new unsigned char[3*iQuantity];
    for (int i = 0, i0 = 0, i1 = 1, i2 = 2; i < iQuantity; i++)
    {
        raucData[i0] = aucSrc[i2];
        raucData[i1] = aucSrc[i1];
        raucData[i2] = aucSrc[i0];
        i0 += 3;
        i1 += 3;
        i2 += 3;
    }
    return true;
}
//----------------------------------------------------------------------------
static void CreateModel ()
{
    // generate vertices and texture coordinates
    int iDim = 32;
    gs_iVQuantity = iDim*iDim;
    gs_afVertex = new float[3*gs_iVQuantity];
    gs_afUV = new float[2*gs_iVQuantity];
    float* pfVertex = gs_afVertex;
    float* pfUV = gs_afUV;
    for (int iY = 0, i = 0; iY < iDim; iY++)
    {
        float fY = iY/(float)(iDim-1);
        for (int iX = 0; iX < iDim; iX++)
        {
            float fX = iX/(float)(iDim-1);

            *pfVertex++ = 2.0f*fX-1.0f;
            *pfVertex++ = 2.0f*fY-1.0f;
            *pfVertex++ = 0.1f*rand()/(float)(RAND_MAX);
            *pfUV++ = fX;
            *pfUV++ = fY;
        }
    }

    // generate connectivity
    gs_iIQuantity = 6*(iDim-1)*(iDim-1);
    gs_aiIndex = new int[gs_iIQuantity];
    for (int i1 = 0, i = 0; i1 < iDim - 1; i1++)
    {
        for (int i0 = 0; i0 < iDim - 1; i0++)
        {
            int iV0 = i0 + iDim * i1;
            int iV1 = iV0 + 1;
            int iV2 = iV1 + iDim;
            int iV3 = iV0 + iDim;
            gs_aiIndex[i++] = iV0;
            gs_aiIndex[i++] = iV1;
            gs_aiIndex[i++] = iV2;
            gs_aiIndex[i++] = iV0;
            gs_aiIndex[i++] = iV2;
            gs_aiIndex[i++] = iV3;
        }
    }

    bool bLoaded;

    // primary texture image
    bLoaded = LoadBmp24("mountain.bmp",gs_iImageW0,gs_iImageH0,gs_aucImage0);
    assert( bLoaded );

    // secondary texture image
    bLoaded = LoadBmp24("fog.bmp",gs_iImageW1,gs_iImageH1,gs_aucImage1);
    assert( bLoaded );
}
//----------------------------------------------------------------------------
static void DestroyModel ()
{
    delete[] gs_afVertex;
    delete[] gs_afUV;
    delete[] gs_aucImage0;
    delete[] gs_aucImage1;
    delete[] gs_aiIndex;
}
//----------------------------------------------------------------------------
static void DrawIt ()
{
    // enable depth buffer reads and writes
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDepthMask(GL_TRUE);

    // set the background color, set depth buffer to infinity
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // double-sided triangles
    glDisable(GL_CULL_FACE);

    // enable vertex arrays
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,gs_afVertex);

    // enable texture unit 0
    glClientActiveTextureARB(GL_TEXTURE0_ARB);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY); 
    glTexCoordPointer(2,GL_FLOAT,0,gs_afUV);
    glActiveTextureARB(GL_TEXTURE0_ARB);
    glEnable(GL_TEXTURE_2D);
    if ( gs_uiID0 != 0 )
    {
        glBindTexture(GL_TEXTURE_2D,gs_uiID0);
    }
    else
    {
        glGenTextures(1,&gs_uiID0);
        glBindTexture(GL_TEXTURE_2D,gs_uiID0);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB8,gs_iImageW0,gs_iImageH0,0,GL_RGB,
            GL_UNSIGNED_BYTE,gs_aucImage0);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    }
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);

    if ( gs_bUseSecondaryTexture )
    {
        // enable texture unit 1
        glClientActiveTextureARB(GL_TEXTURE1_ARB);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY); 
        glTexCoordPointer(2,GL_FLOAT,0,gs_afUV);
        glActiveTextureARB(GL_TEXTURE1_ARB);
        glEnable(GL_TEXTURE_2D);
        if ( gs_uiID1 != 0 )
        {
            glBindTexture(GL_TEXTURE_2D,gs_uiID1);
        }
        else
        {
            glGenTextures(1,&gs_uiID1);
            glBindTexture(GL_TEXTURE_2D,gs_uiID1);
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGB8,gs_iImageW1,gs_iImageH1,0,
                GL_RGB,GL_UNSIGNED_BYTE,gs_aucImage1);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        }
        static float s_afWhite[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
        glTexEnvfv(GL_TEXTURE_ENV,GL_TEXTURE_ENV_COLOR,s_afWhite);
        glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
        glTexEnvi(GL_TEXTURE_ENV,GL_COMBINE_RGB,GL_INTERPOLATE);
        glTexEnvi(GL_TEXTURE_ENV,GL_COMBINE_ALPHA,GL_INTERPOLATE);
        glTexEnvi(GL_TEXTURE_ENV,GL_SOURCE0_RGB,GL_CONSTANT);
        glTexEnvi(GL_TEXTURE_ENV,GL_SOURCE0_ALPHA,GL_REPLACE);
        glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND0_RGB,GL_SRC_COLOR);
        glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND0_ALPHA,GL_SRC_COLOR);
        glTexEnvi(GL_TEXTURE_ENV,GL_SOURCE1_RGB,GL_PREVIOUS);
        glTexEnvi(GL_TEXTURE_ENV,GL_SOURCE1_ALPHA,GL_REPLACE);
        glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND1_RGB,GL_SRC_COLOR);
        glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND1_ALPHA,GL_SRC_COLOR);
        glTexEnvi(GL_TEXTURE_ENV,GL_SOURCE2_RGB,GL_TEXTURE);
        glTexEnvi(GL_TEXTURE_ENV,GL_SOURCE2_ALPHA,GL_REPLACE);
        glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND2_RGB,GL_SRC_COLOR);
        glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND2_ALPHA,GL_SRC_COLOR);
        glTexEnvi(GL_TEXTURE_ENV,GL_RGB_SCALE,1);
        glTexEnvi(GL_TEXTURE_ENV,GL_ALPHA_SCALE,1);
    }

    // set the model-to-world transformation
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glMultMatrixf(gs_afMatrix);

    // draw the mesh
    glDrawElements(GL_TRIANGLES,gs_iIQuantity,GL_UNSIGNED_INT,gs_aiIndex);

    // restore the previous transformation
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();

    if ( gs_bUseSecondaryTexture )
    {
        // disable texture unit 1
        glActiveTextureARB(GL_TEXTURE1_ARB);
        glDisable(GL_TEXTURE_2D);
        glClientActiveTextureARB(GL_TEXTURE1_ARB);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }

    // disable texture unit 0
    glActiveTextureARB(GL_TEXTURE0_ARB);
    glDisable(GL_TEXTURE_2D);
    glClientActiveTextureARB(GL_TEXTURE0_ARB);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    // disable vertex arrays
    glDisableClientState(GL_VERTEX_ARRAY);

    // copy the back buffer into the front buffer
    SwapBuffers(gs_hWindowDC);
}
//----------------------------------------------------------------------------
LRESULT CALLBACK WinProc (HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
    switch ( uiMsg ) 
    {
        case WM_CHAR:
        {
            // triangle motion
            float fTmp0, fTmp1;
            int i;

            unsigned char ucKey = (unsigned char)(char)wParam;
            switch ( ucKey )
            {
            // toggle secondary texture
            case 's':
            case 'S':
                gs_bUseSecondaryTexture = !gs_bUseSecondaryTexture;
                return 0;

            // rotations
            case 'r':
                for (i = 0; i < 3; i++)
                {
                    fTmp0 =
                        gs_fCos*gs_aafRotate[1][i] +
                        gs_fSin*gs_aafRotate[2][i];
                    fTmp1 =
                        gs_fCos*gs_aafRotate[2][i] -
                        gs_fSin*gs_aafRotate[1][i];
                    gs_aafRotate[1][i] = fTmp0;
                    gs_aafRotate[2][i] = fTmp1;
                }
                break;
            case 'R':
                for (i = 0; i < 3; i++)
                {
                    fTmp0 =
                        gs_fCos*gs_aafRotate[1][i] -
                        gs_fSin*gs_aafRotate[2][i];
                    fTmp1 =
                        gs_fCos*gs_aafRotate[2][i] +
                        gs_fSin*gs_aafRotate[1][i];
                    gs_aafRotate[1][i] = fTmp0;
                    gs_aafRotate[2][i] = fTmp1;
                }
                break;
            case 'u':
                for (i = 0; i < 3; i++)
                {
                    fTmp0 =
                        gs_fCos*gs_aafRotate[0][i] +
                        gs_fSin*gs_aafRotate[2][i];
                    fTmp1 =
                        gs_fCos*gs_aafRotate[2][i] -
                        gs_fSin*gs_aafRotate[0][i];
                    gs_aafRotate[0][i] = fTmp0;
                    gs_aafRotate[2][i] = fTmp1;
                }
                break;
            case 'U':
                for (i = 0; i < 3; i++)
                {
                    fTmp0 =
                        gs_fCos*gs_aafRotate[0][i] -
                        gs_fSin*gs_aafRotate[2][i];
                    fTmp1 =
                        gs_fCos*gs_aafRotate[2][i] +
                        gs_fSin*gs_aafRotate[0][i];
                    gs_aafRotate[0][i] = fTmp0;
                    gs_aafRotate[2][i] = fTmp1;
                }
                break;
            case 'd':
                for (i = 0; i < 3; i++)
                {
                    fTmp0 =
                        gs_fCos*gs_aafRotate[0][i] +
                        gs_fSin*gs_aafRotate[1][i];
                    fTmp1 =
                        gs_fCos*gs_aafRotate[1][i] -
                        gs_fSin*gs_aafRotate[0][i];
                    gs_aafRotate[0][i] = fTmp0;
                    gs_aafRotate[1][i] = fTmp1;
                }
                break;
            case 'D':
                for (i = 0; i < 3; i++)
                {
                    fTmp0 =
                        gs_fCos*gs_aafRotate[0][i] -
                        gs_fSin*gs_aafRotate[1][i];
                    fTmp1 =
                        gs_fCos*gs_aafRotate[1][i] +
                        gs_fSin*gs_aafRotate[0][i];
                    gs_aafRotate[0][i] = fTmp0;
                    gs_aafRotate[1][i] = fTmp1;
                }
                break;

            // translations
            case 'x':
                gs_afTranslate[0] -= gs_fDPosition;
                break;
            case 'X':
                gs_afTranslate[0] += gs_fDPosition;
                break;
            case 'y':
                gs_afTranslate[1] -= gs_fDPosition;
                break;
            case 'Y':
                gs_afTranslate[1] += gs_fDPosition;
                break;
            case 'z':
                gs_afTranslate[2] -= gs_fDPosition;
                break;
            case 'Z':
                gs_afTranslate[2] += gs_fDPosition;
                break;

            default:
                return 0;
            }

            // update the model-to-world transformation
            gs_afMatrix[ 0] = gs_aafRotate[0][0];
            gs_afMatrix[ 1] = gs_aafRotate[1][0];
            gs_afMatrix[ 2] = gs_aafRotate[2][0];
            gs_afMatrix[ 3] = 0.0f;
            gs_afMatrix[ 4] = gs_aafRotate[0][1];
            gs_afMatrix[ 5] = gs_aafRotate[1][1];
            gs_afMatrix[ 6] = gs_aafRotate[2][1];
            gs_afMatrix[ 7] = 0.0f;
            gs_afMatrix[ 8] = gs_aafRotate[0][2];
            gs_afMatrix[ 9] = gs_aafRotate[1][2];
            gs_afMatrix[10] = gs_aafRotate[2][2];
            gs_afMatrix[11] = 0.0f;
            gs_afMatrix[12] = gs_afTranslate[0];
            gs_afMatrix[13] = gs_afTranslate[1];
            gs_afMatrix[14] = gs_afTranslate[2];
            gs_afMatrix[15] = 1.0f;
            return 0;
        }
        case WM_KEYDOWN:
        {
            // camera motion
            int iVirtKey = int(wParam);
            double adTmp0[3], adTmp1[3];
            int i;

            switch ( iVirtKey )
            {
            case VK_UP:     // up arrow (move forward)
                for (i = 0; i < 3; i++)
                    gs_adEye[i] += gs_fDPosition*gs_adDir[i];
                break;
            case VK_DOWN:   // down arrow (move backward)
                for (i = 0; i < 3; i++)
                    gs_adEye[i] -= gs_fDPosition*gs_adDir[i];
                break;
            case VK_LEFT:   // left arrow (rotate about up - look left)
                for (i = 0; i < 3; i++)
                {
                    adTmp0[i] = gs_fCos*gs_adRight[i] + gs_fSin*gs_adDir[i];
                    adTmp1[i] = gs_fCos*gs_adDir[i] - gs_fSin*gs_adRight[i];
                }
                for (i = 0; i < 3; i++)
                {
                    gs_adRight[i] = adTmp0[i];
                    gs_adDir[i] = adTmp1[i];
                }
                break;
            case VK_RIGHT:  // right arrow (rotate about up - look right)
                for (i = 0; i < 3; i++)
                {
                    adTmp0[i] = gs_fCos*gs_adRight[i] - gs_fSin*gs_adDir[i];
                    adTmp1[i] = gs_fCos*gs_adDir[i] + gs_fSin*gs_adRight[i];
                }
                for (i = 0; i < 3; i++)
                {
                    gs_adRight[i] = adTmp0[i];
                    gs_adDir[i] = adTmp1[i];
                }
                break;
            case VK_PRIOR:  // page up (rotate about right - look up)
                for (i = 0; i < 3; i++)
                {
                    adTmp0[i] = gs_fCos*gs_adDir[i] + gs_fSin*gs_adUp[i];
                    adTmp1[i] = gs_fCos*gs_adUp[i] - gs_fSin*gs_adDir[i];
                }
                for (i = 0; i < 3; i++)
                {
                    gs_adDir[i] = adTmp0[i];
                    gs_adUp[i] = adTmp1[i];
                }
                break;
            case VK_NEXT:   // page down (rotate about right - look down)
                for (i = 0; i < 3; i++)
                {
                    adTmp0[i] = gs_fCos*gs_adDir[i] - gs_fSin*gs_adUp[i];
                    adTmp1[i] = gs_fCos*gs_adUp[i] + gs_fSin*gs_adDir[i];
                }
                for (i = 0; i < 3; i++)
                {
                    gs_adDir[i] = adTmp0[i];
                    gs_adUp[i] = adTmp1[i];
                }
                break;
            case VK_HOME:   // home (rotate about direction - roll left)
                for (i = 0; i < 3; i++)
                {
                    adTmp0[i] = gs_fCos*gs_adRight[i] + gs_fSin*gs_adUp[i];
                    adTmp1[i] = gs_fCos*gs_adUp[i] - gs_fSin*gs_adRight[i];
                }
                for (i = 0; i < 3; i++)
                {
                    gs_adRight[i] = adTmp0[i];
                    gs_adUp[i] = adTmp1[i];
                }
                break;
            case VK_END:    // end (rotate about direction - roll right)
                for (i = 0; i < 3; i++)
                {
                    adTmp0[i] = gs_fCos*gs_adRight[i] - gs_fSin*gs_adUp[i];
                    adTmp1[i] = gs_fCos*gs_adUp[i] + gs_fSin*gs_adRight[i];
                }
                for (i = 0; i < 3; i++)
                {
                    gs_adRight[i] = adTmp0[i];
                    gs_adUp[i] = adTmp1[i];
                }
                break;
            default:
                return 0;
            }

            // set the camera world coordinate system
            double adLookAt[3] =
            {
                gs_adEye[0]+gs_adDir[0],
                gs_adEye[1]+gs_adDir[1],
                gs_adEye[2]+gs_adDir[2]
            };
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(gs_adEye[0],gs_adEye[1],gs_adEye[2],adLookAt[0],
                adLookAt[1],adLookAt[2],gs_adUp[0],gs_adUp[1],gs_adUp[2]);
            return 0;
        }
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
    }

    return DefWindowProc(hWnd,uiMsg,wParam,lParam);
}
//----------------------------------------------------------------------------
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE, LPSTR acArgument, int)
{
    // register the window class
    static char s_acWindowClass[] = "SHRtest2";
    WNDCLASS wc;
    wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    wc.lpfnWndProc   = WinProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL,IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL,IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszClassName = s_acWindowClass;
    wc.lpszMenuName  = NULL;
    RegisterClass(&wc);

    // require the window to have the specified client area
    RECT kRect = { 0, 0, gs_iWidth-1, gs_iHeight-1 };
    AdjustWindowRect(&kRect,WS_OVERLAPPEDWINDOW,false);

    // create the application window
    static char s_acWindowTitle[] = "SHR Test 2";
    int iXPos = 0, iYPos = 0;
    int iWidth = kRect.right - kRect.left + 1;
    int iHeight = kRect.bottom - kRect.top + 1;
    HWND hWnd = CreateWindow(s_acWindowClass,s_acWindowTitle,
        WS_OVERLAPPEDWINDOW,iXPos,iYPos,iWidth,iHeight,(HWND)0,(HMENU)0,
        hInstance,NULL);

    // create a window for rendering
    gs_hWindowDC = GetDC(hWnd);

    // select format for drawing surface
    PIXELFORMATDESCRIPTOR kPFD;
    memset(&kPFD,0,sizeof(PIXELFORMATDESCRIPTOR));
    kPFD.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    kPFD.nVersion = 1;
    kPFD.dwFlags =
        PFD_DRAW_TO_WINDOW |
        PFD_SUPPORT_OPENGL |
        PFD_GENERIC_ACCELERATED |
        PFD_DOUBLEBUFFER;
    kPFD.iPixelType = PFD_TYPE_RGBA;
    kPFD.cColorBits = 24;  // 24-bit colors for front/back buffers
    kPFD.cDepthBits = 16;  // 16-bit depth buffer
    kPFD.cStencilBits = 8; // 8-bit stencil buffer

    // set the pixel format for the rendering context
    int iPixelFormat = ChoosePixelFormat(gs_hWindowDC,&kPFD);
    if ( iPixelFormat == 0 )
    {
        ReleaseDC(hWnd,gs_hWindowDC);
        return -1;
    }

    BOOL bSuccess = SetPixelFormat(gs_hWindowDC,iPixelFormat,&kPFD);
    if ( !bSuccess )
    {
        ReleaseDC(hWnd,gs_hWindowDC);
        return -2;
    }

    // create an OpenGL context
    HGLRC hWindowRC = wglCreateContext(gs_hWindowDC);
    if ( !hWindowRC )
    {
        ReleaseDC(hWnd,gs_hWindowDC);
        return -3;
    }

    bSuccess = wglMakeCurrent(gs_hWindowDC,hWindowRC);
    if ( !bSuccess )
    {
        wglDeleteContext(hWindowRC);
        ReleaseDC(hWnd,gs_hWindowDC);
        return -4;
    }

    glClientActiveTextureARB = (PFNGLCLIENTACTIVETEXTUREARBPROC)
        wglGetProcAddress("glClientActiveTextureARB");
    assert( glClientActiveTextureARB );

    glActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC)
        wglGetProcAddress("glActiveTextureARB");
    assert( glActiveTextureARB );

    // background color is white
    glClearColor(1.0f,1.0f,1.0f,1.0f);

    // set up for perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(gs_fLFrustum,gs_fRFrustum,gs_fBFrustum,gs_fTFrustum,
        gs_fNFrustum,gs_fFFrustum);

    // set the viewport so that the entire screen is drawn to
    glViewport(gs_iXPort,gs_iYPort,gs_iWPort,gs_iHPort);

    // set the camera world coordinate system
    double adLookAt[3] =
    {
        gs_adEye[0]+gs_adDir[0],
        gs_adEye[1]+gs_adDir[1],
        gs_adEye[2]+gs_adDir[2]
    };
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(gs_adEye[0],gs_adEye[1],gs_adEye[2],adLookAt[0],adLookAt[1],
        adLookAt[2],gs_adUp[0],gs_adUp[1],gs_adUp[2]);

    CreateModel();

    // display the window
    ShowWindow(hWnd,SW_SHOW);
    UpdateWindow(hWnd);

    // start the message pump
    MSG kMsg;
    while ( TRUE )
    {
        if ( PeekMessage(&kMsg,(HWND)0,0,0,PM_REMOVE) )
        {
            if ( kMsg.message == WM_QUIT )
                break;

            HACCEL hAccel = (HACCEL)0;
            if ( !TranslateAccelerator(hWnd,hAccel,&kMsg) )
            {
                TranslateMessage(&kMsg);
                DispatchMessage(&kMsg);
            }
        }
        else
        {
            // idle loop
            DrawIt();
        }
    }

    // clean up
    DestroyModel();
    if ( gs_uiID0 > 0 )
        glDeleteTextures((GLsizei)1,(GLuint*)&gs_uiID0);
    if ( gs_uiID1 > 0 )
        glDeleteTextures((GLsizei)1,(GLuint*)&gs_uiID1);
    wglDeleteContext(hWindowRC);
    ReleaseDC(hWnd,gs_hWindowDC);
    return 0;
}
//----------------------------------------------------------------------------
