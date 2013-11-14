#include "Building.h"

/* The fileName will tell us what kind of mesh this is, 
 * depending on the kind of mesh, we want to have different 
 * bounding boxes for our collision testing.
 */
Building::Building( const char* fileName, Context* ctx )
	:assimpMesh( fileName, ctx ), speed( 5.0f )
{
	if( strncmp( fileName, "", sizeof(fileName) ) )
	{
		box = new BoundingBox( frame.GetOriginX(), frame.GetOriginY(), frame.GetOriginZ(), 1.0f, 1.0f, 1.0f );
	}
	else if( strncmp( fileName, "le", sizeof(fileName) ) ) 
	{
		box = new BoundingBox( frame.GetOriginX(), frame.GetOriginY(), frame.GetOriginZ(), 2.0f, 2.0f, 2.0f );
	}
	else
	{
		printf("Invalid entity requested: %s", fileName);
	}
}

Building::~Building()
{
}