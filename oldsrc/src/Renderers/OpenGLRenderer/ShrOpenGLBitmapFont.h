#ifndef SHROPENGLBITMAPFONT_H
#define SHROPENGLBITMAPFONT_H

#include "ShrOpenGLRendererLIB.h"

namespace shr
{

class BitmapFontChar
{
public:
    BitmapFontChar (int xOrigin, int yOrigin, int xSize, int ySize,
        const unsigned char* bitmap)
    {
        mXOrigin = xOrigin;
        mYOrigin = yOrigin;
        mXSize = xSize;
        mYSize = ySize;
        mBitmap = bitmap;
    }

    int mXOrigin, mYOrigin, mXSize, mYSize;
    const unsigned char* mBitmap;
};

class BitmapFont
{
public:
    BitmapFont (const char* name, int numCharacters,
        const BitmapFontChar* const* characters)
    {
        mName = name;
        mNumCharacters = numCharacters;
        mCharacters = characters;
    }

    const char* mName;
    int mNumCharacters;
    const BitmapFontChar* const* mCharacters;
};

extern const BitmapFont gVerdanaS16B0I0;

}

#endif
