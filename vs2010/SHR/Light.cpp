#include "Light.h"

Light::Light()
{
}

Light::Light( GLfloat* pos, GLfloat* col )
	:renderMe(false), tBatch(false)
{
	lightFrame.SetOrigin( pos[0], pos[1], pos[2] );
	this->pos[0] = pos[0];
	this->pos[1] = pos[1];
	this->pos[2] = pos[2];
	this->pos[3] = pos[3];
	color[0] = col[0];
	color[1] = col[1];
	color[2] = col[2];
	color[3] = col[3];
	getPosition();
}

Light::Light( M3DVector4f* vec, M3DVector4f* col )
{
	lightFrame.SetOrigin( *vec[0], *vec[1], *vec[2] );
	m3dCopyVector4( color, *col );
}

M3DVector3f* Light::getPosition()
{
	lightFrame.GetOrigin( position );
	return &position;
}

M3DVector4f* Light::getColor()
{
	return &color;
}

Light::~Light()
{
}

void Light::Draw()
{
	if( renderMe )
	{
		if( tBatch )
			triBatch.Draw();
		else
			batch.Draw();
	}
}