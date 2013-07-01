#include "ShrApplicationPCH.h"
#include "ShrWindowApplication.h"
//#include <windows.h>
#include "SDL.h"
//#include "SDL_ttf.h"

using namespace shr;

#ifdef SHR_USE_OPENGL
#include "Renderers/SDLRenderer/ShrSDLRendererInput.h"
#include "Renderers/SDLRenderer/ShrSDLRendererData.h"
#endif

const int WindowApplication::KEY_ESCAPE = SDLK_ESCAPE;
const int WindowApplication::KEY_LEFT_ARROW = SDLK_LEFT;
const int WindowApplication::KEY_RIGHT_ARROW = SDLK_RIGHT;
const int WindowApplication::KEY_UP_ARROW = SDLK_UP;
const int WindowApplication::KEY_DOWN_ARROW = SDLK_DOWN;
const int WindowApplication::KEY_HOME = SDLK_HOME;
const int WindowApplication::KEY_END = SDLK_END;
const int WindowApplication::KEY_PAGE_UP = SDLK_PAGEUP;
const int WindowApplication::KEY_PAGE_DOWN = SDLK_PAGEDOWN;
const int WindowApplication::KEY_INSERT = SDLK_INSERT;
const int WindowApplication::KEY_DELETE = SDLK_DELETE;
const int WindowApplication::KEY_F1 = SDLK_F1;
const int WindowApplication::KEY_F2 = SDLK_F2;
const int WindowApplication::KEY_F3 = SDLK_F3;
const int WindowApplication::KEY_F4 = SDLK_F4;
const int WindowApplication::KEY_F5 = SDLK_F5;
const int WindowApplication::KEY_F6 = SDLK_F6;
const int WindowApplication::KEY_F7 = SDLK_F7;
const int WindowApplication::KEY_F8 = SDLK_F8;
const int WindowApplication::KEY_F9 = SDLK_F9;
const int WindowApplication::KEY_F10 = SDLK_F10;
const int WindowApplication::KEY_F11 = SDLK_F11;
const int WindowApplication::KEY_F12 = SDLK_F12;
const int WindowApplication::KEY_BACKSPACE = SDLK_BACKSPACE;
const int WindowApplication::KEY_TAB = SDLK_TAB;
const int WindowApplication::KEY_ENTER = SDLK_RETURN;
const int WindowApplication::KEY_RETURN = SDLK_RETURN;

const int WindowApplication::KEY_SHIFT = SDLK_LSHIFT;
const int WindowApplication::KEY_CONTROL = SDLK_LCTRL;
const int WindowApplication::KEY_ALT = SDLK_LALT;
const int WindowApplication::KEY_COMMAND = SDLK_MODE;

const int WindowApplication::MOUSE_LEFT_BUTTON = SDL_BUTTON_LEFT;
const int WindowApplication::MOUSE_MIDDLE_BUTTON = SDL_BUTTON_MIDDLE;
const int WindowApplication::MOUSE_RIGHT_BUTTON = SDL_BUTTON_RIGHT;
const int WindowApplication::MOUSE_UP = SDL_BUTTON_WHEELUP;
const int WindowApplication::MOUSE_DOWN = SDL_BUTTON_WHEELDOWN;

const int WindowApplication::MODIFIER_CONTROL = KMOD_CTRL;
const int WindowApplication::MODIFIER_LBUTTON = SDL_BUTTON_LMASK;
const int WindowApplication::MODIFIER_MBUTTON = SDL_BUTTON_MMASK;
const int WindowApplication::MODIFIER_RBUTTON = SDL_BUTTON_RMASK;
const int WindowApplication::MODIFIER_SHIFT = KMOD_SHIFT;

#ifndef WM_MOUSEWHEEL
#define WM_MOUSEWHEEL 0x020A
#endif

#ifndef WHEEL_DELTA
#define WHEEL_DELTA 120
#endif

static bool gsIgnoreWindowDestroy = false;

//----------------------------------------------------------------------------
void WindowApplication::SetMousePosition (int x, int y)
{
	SDL_WarpMouse((Uint16)x, (Uint16)y);
}
//----------------------------------------------------------------------------
void WindowApplication::GetMousePosition (int& x, int& y) const
{
    SDL_GetMouseState( &x, &y );
}
//----------------------------------------------------------------------------
int WindowApplication::GetStringWidth (const char* text) const
{
    if (!text || strlen(text) == 0)
    {
        return 0;
    }

    return (int)8.0f*strlen(text);
}

//----------------------------------------------------------------------------
int WindowApplication::GetCharacterWidth (const char character) const
{
    return (int)8.0f;
}

//----------------------------------------------------------------------------
int WindowApplication::GetFontHeight () const
{
    return (int)13.0f;
}

//----------------------------------------------------------------------------
// Event handler goes here

//----------------------------------------------------------------------------
int WindowApplication::Main (int, char**)
{
    WindowApplication* theApp = (WindowApplication*)TheApplication;
    theApp->KEY_TERMINATE = WindowApplication::KEY_ESCAPE;

#ifdef SHR_USE_DX9
    // DirectX uses a projection matrix for depth in [0,1].
    Camera::SetDefaultDepthType(Camera::PM_DEPTH_ZERO_TO_ONE);
#endif

#ifdef SHR_USE_OPENGL
    // OpenGL uses a projection matrix for depth in [-1,1].
    Camera::SetDefaultDepthType(Camera::PM_DEPTH_MINUS_ONE_TO_ONE);
#endif

    // Allow work to be done before the window is created.
    if (!theApp->OnPrecreate())
    {
        return -1;
    }

    // === Create the window for rendering. ===

	/* Initialize SDL for video output */
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

    // Register the window class.

    // Require the window to have the specified client area.

    // Create the application window.

	/* Create a 800x600 OpenGL screen */
	if ( SDL_SetVideoMode(theApp->GetWidth(), theApp->GetHeight(), 0, SDL_OPENGL) == NULL ) {
		fprintf(stderr, "Unable to create OpenGL screen: %s\n", SDL_GetError());
		SDL_Quit();
		exit(2);
	}

	/* Set the title bar in environments that support it */
	SDL_WM_SetCaption("Thesis! ppl", NULL);
	SDL_WM_SetIcon(SDL_LoadBMP("icon.bmp"), NULL);
	
	// Get the SDL window handle
	/*SDL_SysWMinfo sysInfo; //Will hold our Window information
	SDL_VERSION(&sysInfo.version); //Set SDL version
	if(SDL_GetWMInfo(&sysInfo) <= 0) 
	{
		printf("Unable to get window handle");
		return 0;
	}*/

    // Save the handle as an 'int' for portable handle storage.
    //theApp->SetWindowID(sysInfo.window);

#ifdef SHR_USE_OPENGL
    // The pixelFormat variable is used to support creation of a window that
    // supports multisampling.  This process requires creating a normal window,
    // and then querying whether the renderer supports multisampling.  The
    // renderer creates a device context for the window which we then need to
    // create a second window that supports multisampling.  The device context
    // rendererDC is set by the renderer during the process.
    RendererInput input;
    //input.mWindowHandle = handle;
    //input.mPixelFormat = 0;
    //input.mRendererDC = 0;
    input.mDisableVerticalSync = true;
    mRenderer = new0 Renderer(input, theApp->GetWidth(), theApp->GetHeight(),
        mColorFormat, mDepthStencilFormat, mNumMultisamples);

    // To determine whether multisampling is supported, it is necessary to
    // create a window, an OpenGL context, and query the driver for the
    // multisampling extensions.  If it is, a new window must be created
    // because the renderer creation involves SetPixelFormat(...) that can
    // be called only once for a window.
    //int numMultisamples = mRenderer->GetNumMultisamples();
    //if (numMultisamples > 0)
    //{
    //    int attributes[256], pos = 0;
    //    attributes[pos++] = WGL_SUPPORT_OPENGL_ARB;
    //    attributes[pos++] = 1;
    //    attributes[pos++] = WGL_DRAW_TO_WINDOW_ARB;
    //    attributes[pos++] = 1;
    //    attributes[pos++] = WGL_ACCELERATION_ARB;
    //    attributes[pos++] = WGL_FULL_ACCELERATION_ARB;
    //    attributes[pos++] = WGL_PIXEL_TYPE_ARB;
    //    attributes[pos++] = WGL_TYPE_RGBA_ARB;
    //    attributes[pos++] = WGL_RED_BITS_ARB;
    //    attributes[pos++] = 8;
    //    attributes[pos++] = WGL_GREEN_BITS_ARB;
    //    attributes[pos++] = 8;
    //    attributes[pos++] = WGL_BLUE_BITS_ARB;
    //    attributes[pos++] = 8;
    //    attributes[pos++] = WGL_ALPHA_BITS_ARB;
    //    attributes[pos++] = 8;
    //    attributes[pos++] = WGL_DEPTH_BITS_ARB;
    //    attributes[pos++] = 24;
    //    attributes[pos++] = WGL_STENCIL_BITS_ARB;
    //    attributes[pos++] = 8;
    //    attributes[pos++] = WGL_DOUBLE_BUFFER_ARB;
    //    attributes[pos++] = 1;
    //    attributes[pos++] = WGL_SAMPLE_BUFFERS_ARB;
    //    attributes[pos++] = 1;
    //    attributes[pos++] = WGL_SAMPLES_ARB;
    //    attributes[pos++] = numMultisamples;
    //    attributes[pos++] = 0; // list is zero-terminated

    //    unsigned int numFormats = 0;
    //    BOOL successful = wglChoosePixelFormatARB(input.mRendererDC,
    //        attributes, 0, 1, &input.mPixelFormat, &numFormats);
    //    if (successful && numFormats > 0)
    //    {
    //        // The card supports multisampling with the requested number of
    //        // samples.  Recreate the window and renderer.
    //        delete0(mRenderer);

    //        gsIgnoreWindowDestroy = true;
    //        DestroyWindow(handle);

    //        handle = CreateWindow(sWindowClass, theApp->GetWindowTitle(),
    //            WS_OVERLAPPEDWINDOW, theApp->GetXPosition(),
    //            theApp->GetYPosition(), rect.right - rect.left + 1,
    //            rect.bottom - rect.top + 1, 0, 0, 0, 0);

    //        theApp->SetWindowID(PtrToInt(handle));

    //        input.mWindowHandle = handle;
    //        mRenderer = new0 Renderer(input, theApp->GetWidth(),
    //            theApp->GetHeight(), mColorFormat, mDepthStencilFormat,
    //            mNumMultisamples);
    //    }
    //}
#endif

    if (theApp->OnInitialize())
    {
        // The default OnPreidle() clears the buffers.  Allow the application
        // to fill them before the window is shown and before the event loop
        // starts.
        theApp->OnPreidle();

        // Display the window.

        // Start the message pump.
        bool applicationRunning = true;
        while (applicationRunning)
        {
			theApp->OnIdle();
			// main loop goes here
        }
    }
    theApp->OnTerminate();
    //delete0(mRenderer);

    return 0;
}
//----------------------------------------------------------------------------
