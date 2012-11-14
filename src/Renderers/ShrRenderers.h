#ifndef SHRRENDERERS_H
#define SHRRENDERERS_H

#include "ShrRenderer.h"

// This list of files includes private headers.  They need to be exposed to
// the application layer for debugging, because otherwise the linker strips
// the symbols from the application.  Consequently, you cannot watch
// variables in the private classes.

#ifdef SHR_USE_DX9
#include "ShrDx9IndexBuffer.h"
#include "ShrDx9Mapping.h"
#include "ShrDx9PixelShader.h"
#include "ShrDx9RenderTarget.h"
#include "ShrDx9Shader.h"
#include "ShrDx9Texture1D.h"
#include "ShrDx9Texture2D.h"
#include "ShrDx9Texture3D.h"
#include "ShrDx9TextureCube.h"
#include "ShrDx9VertexBuffer.h"
#include "ShrDx9VertexFormat.h"
#include "ShrDx9VertexShader.h"
#endif

#ifdef SHR_USE_OPENGL
#include "ShrOpenGLBitmapFont.h"
#include "ShrOpenGLIndexBuffer.h"
#include "ShrOpenGLMapping.h"
#include "ShrOpenGLPixelShader.h"
#include "ShrOpenGLRenderTarget.h"
#include "ShrOpenGLShader.h"
#include "ShrOpenGLTexture1D.h"
#include "ShrOpenGLTexture2D.h"
#include "ShrOpenGLTexture3D.h"
#include "ShrOpenGLTextureCube.h"
#include "ShrOpenGLVertexBuffer.h"
#include "ShrOpenGLVertexFormat.h"
#include "ShrOpenGLVertexShader.h"
#endif

#endif