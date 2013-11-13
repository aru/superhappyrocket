#include "Building.h"

Building::Building( const char* fileName, Context* ctx )
	:assimpMesh( fileName, ctx ), speed( 5.0f )
{

}

Building::~Building()
{
}