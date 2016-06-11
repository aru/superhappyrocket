/**
 * EntityManager.h
 *
 * The EntityManager class is the responsible of creating and managing
 * events related to our entity objects, such as collisions and
 * spawning times.
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

#ifndef SHR_ENTITYMANAGER
#define SHR_ENTITYMANAGER

#define MAX_ENTITY_NUMBER 7

/* C++ STD includes */
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>

/* SHR includes */
#include "Context.h"
#include "Entity.h"

using namespace std;

class EntityManager
{
public:
    EntityManager( Context* ctx );
    ~EntityManager();

    const int Update( Uint32 gameTime, Uint32 deltaTicks, BoundingBox* playerMesh);

    /* We need to first create the objects to be managed */
    const bool createObjects( const unsigned int numObjects );

    /* We then need to subscribe them to the level in question */ /* ---> let the level do this */

    /* get the timings from a text file */
    const bool parseFile( const char* file );
    /* calculate when to spawn a particular entity */
    const bool calculateWhenToSpawn( int numEntity );
    /* spawn a particular entity */
    const bool spawnEntity( int numEntity );
    /* check if this entity is colliding with the player */
    const bool entityCollides( int numEntity );

    /**** Member objects ****/

    /* we need a pointer to the player/rocket */
    assimpMesh* player;

    /* we need to declare a cutoff distance in z, after x distance after the player we reset the stars position */
    float cutoffDistance;

    /* Our usual pointer to the context */
    Context* ctxt;

    /* Our usual pointer to the audio manager */
    AudioManager* audio;

    /* An array to a list of spawn points */
    vector<int> spawnTimes;

    /* An array for all of the objects that we will manage */
    vector<Entity*> entities;

    /* We need to know the time when the user pressed enter */
    Uint32 startTime;
};

#endif
