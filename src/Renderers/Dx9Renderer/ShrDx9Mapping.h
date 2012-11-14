// Geometric Tools, LLC
// Copyright (c) 1998-2012
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.0 (2010/01/01)

#ifndef SHRDX9MAPPING_H
#define SHRDX9MAPPING_H

#include "ShrDx9RendererLIB.h"
#include "ShrAlphaState.h"
#include "ShrBuffer.h"
#include "ShrCullState.h"
#include "ShrDepthState.h"
#include "ShrShader.h"
#include "ShrStencilState.h"
#include "ShrTexture.h"
#include "ShrVertexFormat.h"
#include "ShrVisual.h"

namespace shr
{

extern BYTE gDX9AttributeType[VertexFormat::AT_QUANTITY];
extern BYTE gDX9AttributeUsage[VertexFormat::AU_QUANTITY];
extern DWORD gDX9BufferUsage[Buffer::BU_QUANTITY];
extern DWORD gDX9BufferLocking[Buffer::BL_QUANTITY];
extern D3DFORMAT gDX9TextureFormat[Texture::TF_QUANTITY];
extern DWORD gDX9MinFilter[Shader::SF_QUANTITY];
extern DWORD gDX9MipFilter[Shader::SF_QUANTITY];
extern DWORD gDX9WrapMode[Shader::SC_QUANTITY];
extern DWORD gDX9AlphaSrcBlend[AlphaState::SBM_QUANTITY];
extern DWORD gDX9AlphaDstBlend[AlphaState::DBM_QUANTITY];
extern DWORD gDX9AlphaCompare[AlphaState::CM_QUANTITY];
extern DWORD gDX9CullOrder[2];
extern DWORD gDX9DepthCompare[DepthState::CM_QUANTITY];
extern DWORD gDX9StencilCompare[StencilState::CM_QUANTITY];
extern DWORD gDX9StencilOperation[StencilState::OT_QUANTITY];
extern D3DPRIMITIVETYPE gDX9PrimitiveType[Visual::PT_MAX_QUANTITY];

}

#endif
