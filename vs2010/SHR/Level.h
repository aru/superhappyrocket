#ifndef SHR_LEVEL
#define SHR_LEVEL

class Level;
#include "SceneManager.h"

class Level
{
public:
	Level();
	~Level();

	vector<char*> songs;
	vector<SimpleObject*> objects;
	vector<GLBatch*> batches;

	// Camera Support
	static CStopWatch    *rotTimer;
	GLFrame              *cameraFrame;
	M3DMatrix44f         *mCamera;
	GLMatrixStack		 *modelViewMatrix;		// Modelview Matrix
	GLMatrixStack		 *projectionMatrix;		// Projection Matrix
	GLFrustum			 *viewFrustum;			// View Frustum
	GLGeometryTransform	 *transformPipeline;		// Geometry Transform Pipeline

};

#endif