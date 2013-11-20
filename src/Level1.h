#ifndef SHR_LEVEL1
#define SHR_LEVEL1

#include "BaseLevel.h"
#include "EntityManager.h"

class Level1 : public BaseLevel
{
public:
	Level1( Context* ctx );
	~Level1();
	const int Initialize();
	const int LoadContent();
	const int Update( Uint32 gameTime );
	void HandleInput( InputManager* input, Uint32 gameTime );
	void pushEntityManagerObjects();

	/* Level content */
	assimpMesh* rocket;
	M3DVector3f rocketForwardVector;
	M3DVector3f rocketUpVector;
	M3DVector3f rocketOrigin;

	M3DVector3f  cameraForwardVector;
	M3DVector3f  cameraUpVector;
	M3DVector3f  cameraOrigin;
	M3DMatrix44f cameraMatrix;

	assimpMesh* cat;

	/* This level's EntityManager */
	EntityManager* entityManager;

	bool start;
	float linear;
	float angular;
};

#endif