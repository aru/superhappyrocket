#ifndef SHR_BUILDING
#define SHR_BUILDING

#include "assimpMesh.h"

class Building : public assimpMesh
{
public:
	Building( const char* fileName, Context* ctx );
	~Building();

	float speed;
};

#endif