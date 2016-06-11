#include "EntityManager.h"

EntityManager::EntityManager( Context* ctx )
    :ctxt(ctx)
{
}

EntityManager::~EntityManager()
{
    /* Erase all of our memory allocated objects */
    unsigned int i = 0;
    for( i = 0; i < entities.size(); i++ )
    {
        delete entities.at( i );
    }
    entities.clear();
}

const bool EntityManager::createObjects( const unsigned int numObjects )
{
    unsigned int i = 0, j = 0;

    for( i = 0; i < numObjects; i++ )
    {
        /* Do one roll to determine what type of entity this will be
         * Star - 0
         * Buildings - 1-9
         */
        j = i % MAX_ENTITY_NUMBER;
        /* Create an entity of that kind */
        Entity* tmpObj = new Entity( j, ctxt );
        /* Push it into our array */
        entities.push_back( tmpObj );
    }
    return true;
}

const bool EntityManager::parseFile( const char* file )
{
    ifstream theFile;
    int temp;
    theFile.open( file );
    while( !theFile.eof() )
    {
        theFile >> temp;
        spawnTimes.push_back( temp );
    }

    /* Create the objects now that we know how many there are, but don't create too many */
    createObjects( spawnTimes.size() );

    return true;
}

const int EntityManager::Update( Uint32 gameTime, Uint32 deltaTicks, BoundingBox* playerMesh )
{
    /* We need to spawn each entity so that they reach the player when the textFile says
     * it should, for this to happen, we calculate:
     * When to spawnTime = gameTime + timeToReachPlayer
     * where
     * timeToReachPlayer = distanceToPlayer / entitySpeed
     * so in the end we have:
     * whenToSpawn = gameTime + (distanceToPlayer / entitySpeed ) */

    // Get the distance to the player
    float distanceToPlayer;
    /*M3DVector3f playerOrigin, entityOrigin;
      player->frame.GetOrigin( playerOrigin );
      entities.at(0)->mesh->frame.GetOrigin( entityOrigin );*/

    /*distanceToPlayer = m3dGetDistance3( playerOrigin, entityOrigin );*/

    // ^ a bit of wishful thinking, we're just gonna hardcode it right now, haha, got you, real good, didn't I?
    distanceToPlayer = 50.0f;

    // Get the entity speed
    float speed;
    speed = entities.at(0)->speed;

    static unsigned int entityCount = 0;

    if( spawnTimes.size() > 0 && spawnTimes.at(0) <= ( gameTime + (distanceToPlayer / speed) ) )
    {
        /* start moving the desired entity */
        entities.at(entityCount++)->move = true;
        /* pop the spawn time, we don't need it anymore */
        spawnTimes.erase( spawnTimes.begin() );
    }

    /* Update each entity now */
    unsigned int i = 0;

    for( i = 0; i < entities.size(); i++ )
    {
        entities.at(i)->Update( deltaTicks );
		// check for collision with the player
		if (playerMesh->intersectsWith(entities[i]->mesh->collisionMesh)) {
			ctxt->audio->PlaySoundEffect(0,1);
		}
    }

    return SHR_SUCCESS;

}
