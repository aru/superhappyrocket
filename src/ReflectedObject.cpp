#include "ReflectedObject.h"

ReflectedObject::ReflectedObject( const char* upperTexture, GLint reflectedText )
	:reflectedTexture( reflectedText )
{
	string temp( upperTexture );
	tFile = temp;
}

ReflectedObject::~ReflectedObject()
{
	glDeleteTextures( 1, &textureFile );
}

const int ReflectedObject::Initialize( Context* ctx )
{

	// Load the texture
	glGenTextures( 1, &textureFile );
	glBindTexture( GL_TEXTURE_2D, textureFile );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	pBytes = gltReadTGABits(tFile.c_str(), &iWidth, &iHeight, &iComponents, &eFormat);
    glTexImage2D(GL_TEXTURE_2D, 0, iComponents, iWidth, iHeight, 0, eFormat, GL_UNSIGNED_BYTE, pBytes);
    free(pBytes);
    glGenerateMipmap(GL_TEXTURE_2D);

	shaderFile = ctx->shaderManager->LoadShaderPairWithAttributes( "./../shaders/Reflection.vp", "./../shaders/Reflection.fp", 3,
																   GLT_ATTRIBUTE_VERTEX, "vVertex",
																   GLT_ATTRIBUTE_NORMAL, "vNormal",
																   GLT_ATTRIBUTE_TEXTURE0, "vTexCoords" );

	locMVPReflect = glGetUniformLocation(shaderFile, "mvpMatrix");
    locMVReflect = glGetUniformLocation(shaderFile, "mvMatrix");
    locNormalReflect = glGetUniformLocation(shaderFile, "normalMatrix");
	locInvertedCamera = glGetUniformLocation(shaderFile, "mInverseCamera");
    locCubeMap = glGetUniformLocation(shaderFile, "cubeMap");
	locTarnishMap = glGetUniformLocation(shaderFile, "tarnishMap");

	return SHR_SUCCESS;
}
const int ReflectedObject::LoadContent()
{
	return SHR_SUCCESS;
}
const int ReflectedObject::Draw( Camera* camera, GLShaderManager* shaderManager, TextureManager* textureManager, Light* light )
{
	// Set the correct texture
	glBindTexture( GL_TEXTURE_2D, textureFile );

	// Matrices needed
	M3DMatrix44f mCamera;
    M3DMatrix44f mCameraRotOnly;
	M3DMatrix44f mInverseCamera;

	// Get the matrices from the camera
	camera->cameraFrame.GetCameraMatrix(mCamera, false);
    camera->cameraFrame.GetCameraMatrix(mCameraRotOnly, true);
	m3dInvertMatrix44(mInverseCamera, mCameraRotOnly);

	camera->modelViewMatrix.PushMatrix();
		//Draw the sphere
		camera->modelViewMatrix.MultMatrix( mCamera );
		camera->modelViewMatrix.MultMatrix( frame );
		glUseProgram( shaderFile );
		glUniformMatrix4fv(locMVPReflect, 1, GL_FALSE, camera->transformPipeline.GetModelViewProjectionMatrix());
        glUniformMatrix4fv(locMVReflect, 1, GL_FALSE, camera->transformPipeline.GetModelViewMatrix());
        glUniformMatrix3fv(locNormalReflect, 1, GL_FALSE, camera->transformPipeline.GetNormalMatrix());
		glUniformMatrix4fv(locInvertedCamera, 1, GL_FALSE, mInverseCamera);
		glUniform1i(locCubeMap, 1);
		glUniform1i(locTarnishMap, 0);

		triBatch.Draw();

	camera->modelViewMatrix.PopMatrix();

	return SHR_SUCCESS;
}
const int ReflectedObject::UnloadContent()
{
	return SHR_SUCCESS;
}

