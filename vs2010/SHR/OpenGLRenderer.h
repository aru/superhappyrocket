#ifndef OPENGL_RENDERER
#define OPENGL_RENDERER

#define NO_SDL_GLEXT
//#include "SDL_opengl.h"

#include <stdio.h>
#include <vector>

#include "Context.h"
#include "SimpleObject.h"
#include "GLTools.h"

// Camera Support etc
#include "GLShaderManager.h"
#include <GLFrustum.h>
#include <GLBatch.h>
#include <GLFrame.h>
#include <GLMatrixStack.h>
#include <GLGeometryTransform.h>
#include <StopWatch.h>

using namespace std;

class Renderer{
public:
	Renderer( Context* ctx );
	Renderer();
	~Renderer();
	int Init();
	int Draw();
	int Update();
	int Clear();
	int Shutdown();

	int addObject( SimpleObject* obj );
	int addBatch( GLBatch* bat );
	int clearObjects();
	int changeSize( int nWidth, int nHeight );

	Context* ctxt;
	vector<SimpleObject*> object;
	GLShaderManager* shader;
	vector<GLBatch*> batch;

	// Camera Support
	static CStopWatch    rotTimer;
	GLFrame              *cameraFrame;
	GLMatrixStack		 *modelViewMatrix;		// Modelview Matrix
	GLMatrixStack		 *projectionMatrix;		// Projection Matrix
	GLFrustum			 *viewFrustum;			// View Frustum
	GLGeometryTransform	 *transformPipeline;		// Geometry Transform Pipeline

};

#endif