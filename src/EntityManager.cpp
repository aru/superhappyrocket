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
		j = rand() % MAX_ENTITY_NUMBER;
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

const int EntityManager::Update( float gameTime )
{
	if( spawnTimes.size() > 0 && gameTime >= spawnTimes.at(0) )
	{
		entities.at(0)->move = true;
		spawnTimes.pop_back();
	}
	return SHR_SUCCESS;
}