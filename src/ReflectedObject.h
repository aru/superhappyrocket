#ifndef SHR_REFLECTEDOBJECT
#define SHR_REFLECTEDOBJECT

#include "Context.h"
#include "SimpleObject.h"

class ReflectedObject : public SimpleObject
{
public:
	ReflectedObject( const char* upperTexture, GLint reflectedText );
	~ReflectedObject();

	/* Standard member methods */
	const int Initialize( Context* ctx );
	const int LoadContent();
	const int Draw( Camera* camera, GLShaderManager* shaderManager, TextureManager* textureManager, Light* light );
	const int UnloadContent();

	/* Standard member context pointer */
	Context* ctxt;

	/* Variables needed to Load Content */
	GLbyte	*pBytes;
    GLint	iWidth, iHeight, iComponents;
    GLenum	eFormat;
	GLint	locMVPReflect, locMVReflect, locNormalReflect, locInvertedCamera;
	GLint	locTarnishMap;

	/* Object that we will be reflecting */
	GLint	locCubeMap;
	GLuint  reflectedTexture;

};

#endif