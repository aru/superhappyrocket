#ifndef SHR_ASSIMPMESHDATA
#define SHR_ASSIMPMESHDATA

#include "Context.h"
#include <GLFrame.h>

struct assimpVertexData
{
	M3DVector3d position;
	M3DVector3d normal;
	M3DVector3d tangent;
	M3DVector3d color;
	double U,V;
};

struct assimpTextureData
{
	unsigned int id;
	unsigned int type;
};

#endif