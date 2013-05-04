#ifndef SHR_TEXTURE
#define SHR_TEXTURE

#include "Context.h"
#include <string>

class TextureManager
{
public:
	TextureManager();
	TextureManager( Context* context );
	~TextureManager();
	int addTexture(char* file);
	void changeTexture();
	void bindTexture( int text );
	void Init();

	Context* ctxt;
	GLuint *textures;
	vector<char*> textureFiles;
	int numTextures;

	GLbyte *pBytes;

};

#endif