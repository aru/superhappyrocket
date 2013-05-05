#include "Texture2D.h"

Texture2D::Texture2D() {}

Texture2D::Texture2D(const char* f, GLenum min, GLenum mag, GLenum wrap )
	:file(f), minFilter(min), magFilter(mag), wrapMode(wrap)
{
}

Texture2D::~Texture2D()
{
}