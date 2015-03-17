#include "Light.h"

Light::Light()
{
}

Light::Light( GLfloat* pos, GLfloat* col )
    :SimpleObject()
{

    frame.SetOrigin( pos[0], pos[1], pos[2] );
    position[0] = pos[0];
    position[1] = pos[1];
    position[2] = pos[2];
    color[0] = col[0];
    color[1] = col[1];
    color[2] = col[2];
    color[3] = col[3];
    frame.GetOrigin( position );
}

Light::~Light()
{
}
