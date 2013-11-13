#ifndef SHR_ENTITYMANAGER
#define SHR_ENTITYMANAGER

#include <vector>
#include "Context.h"
#include "Star.h"

using namespace std;

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	/* We need to first create the objects to be managed */
	const bool createObjects( int numObjects );

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
};

#endif