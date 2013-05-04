#include "TextureManager.h"

TextureManager::TextureManager()
	: numTextures(0), textures(0), textureFiles(0)
{
}

TextureManager::TextureManager( Context* context )
	:numTextures(0), textures(0), textureFiles(0), ctxt( context )
{
}

TextureManager::~TextureManager()
{
	glDeleteTextures(numTextures, textures);
}

void TextureManager::Init()
{
	GLint iWidth, iHeight, iComponents;
    GLenum eFormat;
    GLint iLoop;

	// Load textures
	if( textureFiles.size() > 0 )
	{
		glGenTextures(numTextures, textures);
		for(iLoop = 0; iLoop < numTextures; iLoop++)
			{
			// Bind to next texture object
			glBindTexture(GL_TEXTURE_2D, textures[iLoop]);
        
			// Load texture, set filter and wrap modes
			pBytes = gltReadTGABits(textureFiles.at(iLoop),&iWidth, &iHeight,
				                  &iComponents, &eFormat);

			// Load texture, set filter and wrap modes
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexImage2D(GL_TEXTURE_2D, 0, iComponents, iWidth, iHeight, 0, eFormat, GL_UNSIGNED_BYTE, pBytes);
			glGenerateMipmap(GL_TEXTURE_2D);
			// Don't need original texture data any more
			free(pBytes);
        }
	}
}

int TextureManager::addTexture(char* file)
{
	textureFiles.push_back(file);
	numTextures++;
	return 0;
}

void TextureManager::bindTexture( int text )
{
	glBindTexture(GL_TEXTURE_2D, textures[text]);
}