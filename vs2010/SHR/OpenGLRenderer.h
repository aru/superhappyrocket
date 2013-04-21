#ifndef OPENGL_RENDERER
#define OPENGL_RENDERER

#include "GLTools.h"
#define NO_SDL_GLEXT
//#include "SDL_opengl.h"
#include "SimpleObject.h"
#include <stdio.h>
#include <vector>

#include "GLShaderManager.h"

using namespace std;

class Renderer{
public:
	Renderer();
	~Renderer();
	int Init();
	int Draw();
	int Update();
	int Clear();
	int Shutdown();

	int addObject( SimpleObject* obj );
	int addBatch( GLBatch* bat );
	int clearObjects();

	vector<SimpleObject*> object;
	GLShaderManager* shader;
	vector<GLBatch*> batch;

};

#endif