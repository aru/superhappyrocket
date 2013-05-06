#ifndef SHR_CAMERA
#define SHR_CAMERA

#include "Context.h"
#include <GLTools.h>
#include <GLMatrixStack.h>
#include <GLFrame.h>
#include <GLFrustum.h>
#include <GLGeometryTransform.h>

class CameraManager
{
public:
	CameraManager();
	CameraManager( Context* ctx );
	~CameraManager();

	Context * ctxt;
	M3DMatrix44f		 camera;
	GLFrame              *cameraFrame;
	GLMatrixStack		 *modelViewMatrix;		// Modelview Matrix
	GLMatrixStack		 *projectionMatrix;		// Projection Matrix
	GLFrustum			 *viewFrustum;			// View Frustum
	GLGeometryTransform	 *transformPipeline;		// Geometry Transform Pipeline
};

#endif