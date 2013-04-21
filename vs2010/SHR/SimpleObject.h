#ifndef SIMPLE_OBJECT
#define SIMPLE_OBJECT

#include "GLTools.h"
#define NO_SDL_GLEXT
//#include "SDL_opengl.h"
#include <vector>

using namespace std;

class SimpleObject
{
public:

	SimpleObject();
	SimpleObject(GLenum type, float* vArr, int vArrSize, float* iArr, int iArrSize);
	~SimpleObject();
	int Init();
	int Draw();
	int Update();
	int CleanUp();

	bool renderMe;
	GLenum primType;
	vector<float> vertex;
	vector<float> index;

};

#endif