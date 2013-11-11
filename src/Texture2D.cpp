#include "Texture2D.h"

Texture2D::Texture2D() {}

Texture2D::Texture2D(const char* f, GLenum min, GLenum mag, GLenum wrap )
	:file(f), minFilter(min), magFilter(mag), wrapMode(wrap)
{
}

Texture2D::~Texture2D()
{
}

Texture2D::Texture2D(string* str, GLenum min, GLenum mag, GLenum wrap)
	:minFilter(min), magFilter(mag), wrapMode(wrap)
{
	file = str->c_str();
}

Texture2D::Texture2D(string str, GLenum min, GLenum mag, GLenum wrap)
	:minFilter(min), magFilter(mag), wrapMode(wrap), textureString(str)
{
	file = textureString.c_str();
}

Texture2D::Texture2D( const Texture2D &txt )
{
	this->file = txt.file;
	this->magFilter = txt.magFilter;
	this->minFilter = txt.minFilter;
	this->wrapMode = txt.wrapMode;
	this->textureFile = txt.textureFile;
	this->textureString = txt.textureString;
}