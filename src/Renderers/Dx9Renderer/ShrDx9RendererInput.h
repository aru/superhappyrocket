// Geometric Tools, LLC
// Copyright (c) 1998-2012
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.0 (2010/01/01)

#ifndef SHRDX9RENDERERINPUT_H
#define SHRDX9RENDERERINPUT_H

#include "ShrDx9RendererLIB.h"

namespace shr
{

class RendererInput
{
public:
    IDirect3D9* mDriver;
    HWND mWindowHandle;
};

}

#endif
