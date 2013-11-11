#ifndef SHR_CUBEMAP
#define SHR_CUBEMAP

#include "Context.h"
#include "SimpleObject.h"

class CubeMap : public SimpleObject
{

public:

	CubeMap();
	CubeMap( GLfloat size, 
			 const char* f1, const char* f2, const char* f3, 
			 const char* f4, const char* f5, const char* f6 );
	~CubeMap();

	const int Initialize( Context* ctx );
	const int LoadContent();
	const int Draw( Camera* camera, GLShaderManager* shaderManager, TextureManager* textureManager, Light* light );
	const int UnloadContent();

	/* Standard member context pointer */
	Context* ctxt;

	/* Specific values for the cubemap */
	GLfloat cubeMapSize;
	const char* szCubeFaces[6];
	GLenum cube[6];

	/* Variables needed to Load Content */
	GLbyte *pBytes;
    GLint iWidth, iHeight, iComponents;
    GLenum eFormat;
	GLint locMVPSkyBox, locCubeMap;

};

#endif