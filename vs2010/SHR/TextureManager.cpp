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
	//GLint iWidth, iHeight, iComponents;
    //GLenum eFormat;
    GLint iLoop;
	textures = (GLuint*)malloc(sizeof(GLuint) * numTextures);

	// Load textures
	if( textureFiles.size() > 0 )
	{
		// Make n texture objects
		glGenTextures(numTextures, textures);
		for(iLoop = 0; iLoop < numTextures; iLoop++)
		{
			// Bind to next texture object
			glBindTexture(GL_TEXTURE_2D, textures[iLoop]);
			// Load the texture from a tga
			LoadTGATexture(textureFiles.at(iLoop), GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR, GL_REPEAT);
        }
	}
}

void TextureManager::Init2()
{
    GLint iLoop;
	textures = (GLuint*)malloc(sizeof(GLuint) * numTextures);

	// Load textures
	if( texts.size() > 0 )
	{
		// Make n texture objects
		glGenTextures(numTextures, textures);
		for(iLoop = 0; iLoop < numTextures; iLoop++)
		{
			// Bind to next texture object
			glBindTexture(GL_TEXTURE_2D, textures[iLoop]);
			// Load the texture from a tga
			LoadTGATexture(texts.at(iLoop)->file, texts.at(iLoop)->minFilter, texts.at(iLoop)->magFilter, texts.at(iLoop)->wrapMode);
        }
	}
}

int TextureManager::addTexture(char* file)
{
	textureFiles.push_back(file);
	numTextures++;
	return numTextures;
}

int TextureManager::addTexture(Texture2D* text)
{
	texts.push_back(text);
	numTextures++;
	return numTextures;
}

void TextureManager::bindTexture( int text )
{
	glBindTexture(GL_TEXTURE_2D, textures[text]);
}

// Load a TGA as a 2D Texture. Completely initialize the state
bool TextureManager::LoadTGATexture(const char *szFileName, GLenum minFilter, GLenum magFilter, GLenum wrapMode)
{
	GLbyte *pBits;
	int nWidth, nHeight, nComponents;
	GLenum eFormat;
	
	// Read the texture bits
	pBits = gltReadTGABits(szFileName, &nWidth, &nHeight, &nComponents, &eFormat);
	if(pBits == NULL)
		return false;
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
    
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, nComponents, nWidth, nHeight, 0,
				 eFormat, GL_UNSIGNED_BYTE, pBits);
	
    free(pBits);
    
    if(minFilter == GL_LINEAR_MIPMAP_LINEAR || 
       minFilter == GL_LINEAR_MIPMAP_NEAREST ||
       minFilter == GL_NEAREST_MIPMAP_LINEAR ||
       minFilter == GL_NEAREST_MIPMAP_NEAREST)
        glGenerateMipmap(GL_TEXTURE_2D);
    
	return true;
}