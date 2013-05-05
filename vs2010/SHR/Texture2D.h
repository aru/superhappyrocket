#ifndef SHR_TEXTURE2D
#define SHR_TEXTURE2D

#include "Context.h"

class Texture2D
{
public:
	Texture2D();
	Texture2D(const char* f, GLenum min, GLenum mag, GLenum wrap);
	~Texture2D();

	const char* file;
	GLenum minFilter; 
	GLenum magFilter; 
	GLenum wrapMode;
};

#endif