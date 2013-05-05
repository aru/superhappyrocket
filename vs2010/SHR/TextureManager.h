#ifndef SHR_TEXTURE
#define SHR_TEXTURE

#include <string>

#include "Context.h"

class Texture2D;
#include "Texture2D.h"

class TextureManager
{
public:
	TextureManager();
	TextureManager( Context* context );
	~TextureManager();
	int addTexture(char* file);
	int addTexture(Texture2D* text);
	void changeTexture();
	void bindTexture( int text );
	void Init();
	void Init2();
	bool LoadTGATexture(const char *szFileName, GLenum minFilter, GLenum magFilter, GLenum wrapMode);
	bool LoadTGATexture(Texture2D* text);

	Context* ctxt;
	GLuint *textures;
	vector<char*> textureFiles;
	vector<Texture2D*> texts;
	int numTextures;

	GLbyte *pBytes;

};

#endif