#include "CubeMap.h"

CubeMap::CubeMap()
{
}

CubeMap::CubeMap( GLfloat size,
                  const char* f1, const char* f2, const char* f3,
                  const char* f4, const char* f5, const char* f6 )
{

    /* Set the size */
    cubeMapSize = size;
    /* Set the textures we will be using */
    szCubeFaces[0] = f1;
    szCubeFaces[1] = f2;
    szCubeFaces[2] = f3;
    szCubeFaces[3] = f4;
    szCubeFaces[4] = f5;
    szCubeFaces[5] = f6;

    /* Initiazile the cube enums */
    cube[0] = GL_TEXTURE_CUBE_MAP_POSITIVE_X;
    cube[1] = GL_TEXTURE_CUBE_MAP_NEGATIVE_X;
    cube[2] = GL_TEXTURE_CUBE_MAP_POSITIVE_Y;
    cube[3] = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y;
    cube[4] = GL_TEXTURE_CUBE_MAP_POSITIVE_Z;
    cube[5] = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z;
}

CubeMap::~CubeMap()
{
    glDeleteTextures( 1, &textureFile );
}

const int CubeMap::Draw( Camera* camera, GLShaderManager* shaderManager, TextureManager* textureManager, Light* light )
{

    M3DMatrix44f mCameraRotOnly;
    camera->cameraFrame.GetCameraMatrix( mCameraRotOnly, true );

    camera->modelViewMatrix.PushMatrix();

    camera->modelViewMatrix.MultMatrix( mCameraRotOnly );
    camera->modelViewMatrix.MultMatrix( frame );
    glUseProgram( shaderFile );
    glUniformMatrix4fv( locMVPSkyBox, 1, GL_FALSE, camera->transformPipeline.GetModelViewProjectionMatrix() );
    glUniform1i( locCubeMap, 1 );
    batch.Draw();

    camera->modelViewMatrix.PopMatrix();

    return SHR_SUCCESS;
}

const int CubeMap::Initialize( Context* ctx )
{
    // Variable for looping
    int i;

    // Set the cube map in texture unit 1
    glActiveTexture( GL_TEXTURE0 + 1 );
    glGenTextures(1, &textureFile);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureFile);

    /* Set up texture maps */
    glTexParameteri( GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    /* Load Cube Map Images */
    for( i = 0; i < 6; i++ )
    {
        // Load this texture map
        pBytes = gltReadTGABits(szCubeFaces[i], &iWidth, &iHeight, &iComponents, &eFormat);
        glTexImage2D( cube[i], 0, iComponents, iWidth, iHeight, 0, eFormat, GL_UNSIGNED_BYTE, pBytes );
        free(pBytes);
    }
    glGenerateMipmap( GL_TEXTURE_CUBE_MAP );

    gltMakeCube( batch, cubeMapSize );

    shaderFile = ctx->shaderManager->LoadShaderPairWithAttributes( "./../shaders/SkyBox.vp", "./../shaders/SkyBox.fp", 2,
                                                                   GLT_ATTRIBUTE_VERTEX, "vVertex",
                                                                   GLT_ATTRIBUTE_NORMAL, "vNormal" );

    locMVPSkyBox = glGetUniformLocation(shaderFile, "mvpMatrix");
    locCubeMap = glGetUniformLocation(shaderFile, "cubeMap");

    // Revert to texture unit 0
    glActiveTexture( GL_TEXTURE0 );

    return SHR_SUCCESS;
}

const int CubeMap::LoadContent()
{
    return SHR_SUCCESS;
}

const int CubeMap::UnloadContent()
{
    return SHR_SUCCESS;
}
