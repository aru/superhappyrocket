/**
 * Level1.h
 *
 * This derived class comes from the base class BaseLevel, it is used
 * to generate the first level used on the Super Happy Rocket project.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details http://www.gnu.org/licenses/.
 */

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
	void HandleCollisions();
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
    assimpMesh* star;
    assimpMesh* star2;
    assimpMesh* star3;
    assimpMesh* star4;
	assimpMesh* building;
	assimpMesh* building2;
	assimpMesh* building3;
	assimpMesh* building4;
	assimpMesh* building5;
	assimpMesh* building6;
	assimpMesh* building7;

    /* This level's EntityManager */
    EntityManager* entityManager;

    bool start;
    float linear;
    float angular;
};

#endif
