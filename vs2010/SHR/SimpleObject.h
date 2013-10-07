/**
 * SimpleObject.h
 *
 * A SimpleObject is a structure created to represent actors in our scene.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details http://www.gnu.org/licenses/.
 */

#ifndef SIMPLE_OBJECT
#define SIMPLE_OBJECT

#include "Context.h"
#include <GLTools.h>
#include <GLFrame.h>
#include <GLMatrixStack.h>
#define NO_SDL_GLEXT
//#include "SDL_opengl.h"
#include <vector>

using namespace std;

class SimpleObject
{
public:
	// Constructor && Destructor
	SimpleObject();
	SimpleObject( Context* ctx );
	SimpleObject(GLenum type, float* vArr, int vArrSize, float* iArr, int iArrSize);
	SimpleObject( const SimpleObject& obj );
	virtual ~SimpleObject();
	int Init();
	int Draw();
	virtual int Draw2();
	int Update();
	int CleanUp();
	void addChildren();
	void setTexture( int text );
	void setShader( int shade );
	int getTexture();
	int getShader();

	// will this be rendered?
	bool renderMe;
	
	// is this object movable?
	bool actor;

	// is this object a triangle batch?
	bool tBatch;

	// what type of primitive is this?
	GLenum primType;

	// Arrays for data keeping
	GLBatch batch;
	GLTriangleBatch triBatch;
	GLFrame frame;
	GLMatrixStack *modelViewMatrix;

	Context *ctxt;
	vector<float> vertex;
	vector<float> index;
	vector<float> normal;
	vector<float> texture;
	vector<float> color;
	// Children below this hierarchachy
	vector<SimpleObject*> child;
	int numChildren;
	// what shader is this using? shader 0 is default pipeline shader
	GLint shaderFile;
	// strings for the shaders this object will be using
	string fragShader, vertShader;
	// what texture is this using? texture 0 is no texture
	int textureFile;

};

#include "ShadedObject.h"

#endif