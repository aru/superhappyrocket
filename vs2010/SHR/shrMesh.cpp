#include "shrMesh.h"

shrMesh::shrMesh()
	:textureFile(0), type(0)
{
}

shrMesh::~shrMesh()
{
}

shrMesh::shrMesh( const shrMesh& mesh )
	:textureFile(0)
{
	type = mesh.type;
	data = mesh.data;
	data2 = mesh.data2;
	frame = mesh.frame;
	textureFile = mesh.textureFile;
	shaderFile = mesh.shaderFile;
	texture = mesh.texture;
	textureString = mesh.textureString;
}