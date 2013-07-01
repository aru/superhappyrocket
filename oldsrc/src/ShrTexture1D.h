#ifndef SHRTEXTURE1D_H
#define SHRTEXTURE1D_H

#include "ShrGraphicsLIB.h"
#include "ShrTexture.h"

namespace shr
{

class SHR_GRAPHICS_ITEM Texture1D : public Texture
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(Texture1D);

public:
    // Construction and destruction.
    Texture1D (Format tformat, int dimension0, int numLevels,
        Buffer::Usage usage = Buffer::BU_TEXTURE);

    virtual ~Texture1D ();

    // Get the dimension of the zero-th level mipmap.
    inline int GetLength () const;

    // Support for mipmap generation.
    void GenerateMipmaps ();
    bool HasMipmaps () const;

    // Access the texture data.
    char* GetData (int level) const;

protected:
    // Support for mipmap generation.
    void ComputeNumLevelBytes ();
    void GenerateNextMipmap (int length, const char* texels, int lengthNext,
        char* texelsNext, Float4* rgba);

// Support for the raw load of Texture1D.  Raw save is in Texture.
public:
    static Texture1D* LoadWMTF (const std::string& name,
        int mode = FileIO::FM_DEFAULT_READ);
// End support for raw load.
};

SHR_REGISTER_STREAM(Texture1D);
typedef Pointer0<Texture1D> Texture1DPtr;
#include "ShrTexture1D.inl"

}

#endif