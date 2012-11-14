#ifndef SHRTEXTURE2D_H
#define SHRTEXTURE2D_H

#include "ShrGraphicsLIB.h"
#include "ShrTexture.h"

namespace shr
{

class SHR_GRAPHICS_ITEM Texture2D : public Texture
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(Texture2D);

public:
    // Construction and destruction.
    Texture2D (Format tformat, int dimension0, int dimension1,
        int numLevels, Buffer::Usage usage = Buffer::BU_TEXTURE);

    virtual ~Texture2D ();

    // Get the dimensions of the zero-th level mipmap.
    inline int GetWidth () const;
    inline int GetHeight () const;

    // Support for mipmap generation.
    void GenerateMipmaps ();
    bool HasMipmaps () const;

    // Access the texture data.
    char* GetData (int level) const;

protected:
    // Support for mipmap generation.
    void ComputeNumLevelBytes ();
    void GenerateNextMipmap (int width, int height, const char* texels,
        int widthNext, int heightNext, char* texelsNext, Float4* rgba);

// Support for the raw load of Texture2D.  Raw save is in Texture.
public:
    static Texture2D* LoadWMTF (const std::string& name,
        int mode = FileIO::FM_DEFAULT_READ);
// End support for raw load.
};

SHR_REGISTER_STREAM(Texture2D);
typedef Pointer0<Texture2D> Texture2DPtr;
#include "ShrTexture2D.inl"

}

#endif