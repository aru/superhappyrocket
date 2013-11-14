#include "Star.h"

Star::Star( Context* ctx, float r0, float r1, float r2 )
	:assimpMesh( "../../content/models/estrella249.3ds", ctxt ), speed( 5.0f )
{
	box = new BoundingBox( frame.GetOriginX(), frame.GetOriginY(), frame.GetOriginZ(), 1.0f, 1.0f, 1.0f );
}

Star::~Star()
{
	delete box;
}