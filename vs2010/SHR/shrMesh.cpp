#include "shrMesh.h"

shrMesh::shrMesh()
	:textureFile(0)
{
}

shrMesh::~shrMesh()
{
}

shrMesh::shrMesh( const shrMesh& mesh )
	:textureFile(0)
{
	data = mesh.data;
	frame = mesh.frame;
	textureFile = mesh.textureFile;
	shaderFile = mesh.shaderFile;
	texture = mesh.texture;
	textureString = mesh.textureString;
}