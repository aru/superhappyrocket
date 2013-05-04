#include "SimpleObject.h"

SimpleObject::SimpleObject()
	:renderMe(true), shaderFile(0), textureFile(0)
{
	primType = GL_POINTS;
}

SimpleObject::~SimpleObject()
{
	vertex.clear();
	index.clear();
}

SimpleObject::SimpleObject(GLenum type, float* vArr, int vArrSize, float* iArr, int iArrSize)
	:primType(type), renderMe(true)
{
	vertex.assign(vArr,vArr+vArrSize);
	index.assign(iArr,iArr+iArrSize);
}

int SimpleObject::Draw()
{
	glBegin( primType );
	for( unsigned int i = 0; i < vertex.size(); i += 2 )
	{
		glVertex2f( vertex.at(i), vertex.at(i+1) );
	}
	glEnd();
	
	return 0;
}

int SimpleObject::Draw2()
{
	batch.Draw();
	return 0;
}

void SimpleObject::setTexture( int text ){
	textureFile = text;
}
void SimpleObject::setShader( int shade ){
	shaderFile = shade;
}
int SimpleObject::getTexture(){
	return textureFile;
}
int SimpleObject::getShader(){
	return shaderFile;
}