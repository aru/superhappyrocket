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
	~SimpleObject();
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
	// what type of primitive is this?
	GLenum primType;

	// Arrays for data keeping
	GLBatch batch;
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
	int shaderFile;
	// what texture is this using? texture 0 is no texture
	int textureFile;

};

#endif