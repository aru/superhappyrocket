#ifndef OPENGL_RENDERER
#define OPENGL_RENDERER

#define NO_SDL_GLEXT
//#include "SDL_opengl.h"

#include <stdio.h>
#include <vector>

#include "Context.h"
#include "SimpleObject.h"
#include "GLTools.h"
#include "CameraManager.h"

// Camera Support etc
#include <GLShaderManager.h>
#include <GLFrustum.h>
#include <GLBatch.h>
#include <GLFrame.h>
#include <GLMatrixStack.h>
#include <GLGeometryTransform.h>
#include <StopWatch.h>

// Assimp support
#include "assimp/Importer.hpp"
#include "assimp/cimport.h"
// assimp include files. These three are usually needed.
#include "assimp/PostProcess.h"
#include "assimp/Scene.h"
#include "assimp/DefaultLogger.hpp"
#include "assimp/LogStream.hpp"


using namespace std;

class Renderer{
public:
	Renderer( Context* ctx );
	Renderer();
	~Renderer();
	int Init();
	int Draw();
	int Draw2();
	int Update();
	int Clear();
	int Shutdown();

	int addObject( SimpleObject* obj );
	int addActor( SimpleObject* act );
	int addBatch( GLBatch* bat );
	int addLight( Light* lit );
	int clearObjects();
	int changeSize( int nWidth, int nHeight );

	bool LoadTGATexture(const char *szFileName, GLenum minFilter, GLenum magFilter, GLenum wrapMode);

	Context* ctxt;

	M3DMatrix44f camera;
	vector<SimpleObject*> object;
	vector<SimpleObject*> actor;

	GLShaderManager* shader;
	CameraManager* mCamera;
	vector<GLBatch*> batch;

	// Camera Support
	static CStopWatch    rotTimer;
	GLFrame              *cameraFrame;
	GLMatrixStack		 *modelViewMatrix;		// Modelview Matrix
	GLMatrixStack		 *projectionMatrix;		// Projection Matrix
	GLFrustum			 *viewFrustum;			// View Frustum
	GLGeometryTransform	 *transformPipeline;		// Geometry Transform Pipeline

	GLuint				uiTextures;

	// Light support
	vector<Light*> lights;

};

#endif