#ifndef SHRTEXTURE3D_H
#define SHRTEXTURE3D_H

#include "ShrGraphicsLIB.h"
#include "ShrTexture.h"

namespace shr
{

class SHR_GRAPHICS_ITEM Texture3D : public Texture
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(Texture3D);

public:
    // Construction and destruction.
    Texture3D (Format tformat, int dimension0, int dimension1, int dimension2,
        int numLevels, Buffer::Usage usage = Buffer::BU_TEXTURE);

    virtual ~Texture3D ();

    // Get the dimensions of the zero-th level mipmap.
    inline int GetWidth () const;
    inline int GetHeight () const;
    inline int GetThickness () const;

    // Support for mipmap generation.
    void GenerateMipmaps ();
    bool HasMipmaps () const;

    // Access the texture data.
    char* GetData (int level) const;

protected:
    // Support for mipmap generation.
    void ComputeNumLevelBytes ();
    void GenerateNextMipmap (int width, int height, int thickness,
        const char* texels, int widthNext, int heightNext, int thicknessNext,
        char* texelsNext, Float4* rgba);

// Support for the raw load of Texture3D.  Raw save is in Texture.
public:
    static Texture3D* LoadWMTF (const std::string& name,
        int mode = FileIO::FM_DEFAULT_READ);
// End support for raw load.
};

SHR_REGISTER_STREAM(Texture3D);
typedef Pointer0<Texture3D> Texture3DPtr;
#include "ShrTexture3D.inl"

}

#endif
