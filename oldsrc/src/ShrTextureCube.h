#ifndef SHRTEXTURECUBE_H
#define SHRTEXTURECUBE_H

#include "ShrGraphicsLIB.h"
#include "ShrTexture.h"

namespace shr
{

class SHR_GRAPHICS_ITEM TextureCube : public Texture
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(TextureCube);

public:
    // Construction and destruction.  The faces of the cube are necessarily
    // square textures of size dimension-by-dimension.
    TextureCube (Format tformat, int dimension, int numLevels,
        Buffer::Usage usage = Buffer::BU_TEXTURE);

    virtual ~TextureCube ();

    // Get the dimensions of the zero-th level mipmap.
    inline int GetWidth () const;
    inline int GetHeight () const;

    // Support for mipmap generation.
    void GenerateMipmaps ();
    bool HasMipmaps () const;

    // Note:  Texture::GetNumLevelBytes(level) returns the number of bytes
    // for a level of *one* face.  Texture::GetNumTotalBytes() returns the
    // number of bytes of all levels of *all* faces.

    // Access the texture data.
    char* GetData (int face, int level) const;

protected:
    // Support for mipmap generation.
    void ComputeNumLevelBytes ();
    void GenerateNextMipmap (int dimension, const char* texels,
        int dimensionNext, char* texelsNext, Float4* rgba);

// Support for the raw load of TextureCube.  Raw save is in Texture.
public:
    static TextureCube* LoadWMTF (const std::string& name,
        int mode = FileIO::FM_DEFAULT_READ);
// End support for raw load.
};

SHR_REGISTER_STREAM(TextureCube);
typedef Pointer0<TextureCube> TextureCubePtr;
#include "ShrTextureCube.inl"

}

#endif