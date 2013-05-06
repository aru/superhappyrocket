#include "CameraManager.h"

CameraManager::CameraManager()
{
	cameraFrame = new GLFrame();
	modelViewMatrix = new GLMatrixStack();
	projectionMatrix = new GLMatrixStack();
	viewFrustum = new GLFrustum();
	transformPipeline = new GLGeometryTransform();
}

CameraManager::CameraManager( Context* ctx )
	:ctxt(ctx)
{
	cameraFrame = new GLFrame();
	modelViewMatrix = new GLMatrixStack();
	projectionMatrix = new GLMatrixStack();
	viewFrustum = new GLFrustum();
	transformPipeline = new GLGeometryTransform();
}

CameraManager::~CameraManager()
{
}

