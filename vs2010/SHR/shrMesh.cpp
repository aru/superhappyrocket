#include "shrMesh.h"

shrMesh::shrMesh()
{
}

shrMesh::~shrMesh()
{
}

shrMesh::shrMesh( const shrMesh& mesh )
{
	data = mesh.data;
	frame = mesh.frame;
	textureFile = mesh.textureFile;
	shaderFile = mesh.shaderFile;
	texture = mesh.texture;
	textureString = mesh.textureString;
}