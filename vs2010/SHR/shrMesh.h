#ifndef SHR_MESH
#define SHR_MESH

#include "Context.h"
#include <GLTools.h>
#include <GLFrame.h>
#include <GLTriangleBatch.h>
#include <vector>
#include <string>

class shrMesh{
public:
	// Save all of the data for this model
	//GLBatch data2;
	// Alternative way of saving data
	GLTriangleBatch data;
	// Put in a frame to move easily
	GLFrame			frame;
	// Save what texture/file this is using
	unsigned int	textureFile;
	unsigned int	shaderFile;
};

#endif