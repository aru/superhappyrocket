#ifndef SHR_LEVEL
#define SHR_LEVEL

class Level;
#include "SceneManager.h"
#include "Texture2D.h"
#include "Timer.h"

class Level
{
public:
	Level();
	~Level();
	// Declare and load every asset in this part
	void LoadContent();
	// Set the initial values of things
	void Draw( int GameTimeElapsed );
	// Update the values of everything in the level
	void Update( int GameTimeElapsed );
	// Unload every asset in this part just to be safe
	void UnloadContent();

	vector<char*> songs;
	vector<char*> textures;
	vector<Texture2D*> texts;
	vector<SimpleObject*> objects;
	vector<SimpleObject*> actors;
	vector<GLBatch*> batches;
	vector<Light*> lights;

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