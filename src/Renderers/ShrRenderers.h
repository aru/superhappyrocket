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
#include "Renderers/OpenGLRenderer/ShrOpenGLBitmapFont.h"
#include "Renderers/OpenGLRenderer/ShrOpenGLIndexBuffer.h"
#include "Renderers/OpenGLRenderer/ShrOpenGLMapping.h"
#include "Renderers/OpenGLRenderer/ShrOpenGLPixelShader.h"
#include "Renderers/OpenGLRenderer/ShrOpenGLRenderTarget.h"
#include "Renderers/OpenGLRenderer/ShrOpenGLShader.h"
#include "Renderers/OpenGLRenderer/ShrOpenGLTexture1D.h"
#include "Renderers/OpenGLRenderer/ShrOpenGLTexture2D.h"
#include "Renderers/OpenGLRenderer/ShrOpenGLTexture3D.h"
#include "Renderers/OpenGLRenderer/ShrOpenGLTextureCube.h"
#include "Renderers/OpenGLRenderer/ShrOpenGLVertexBuffer.h"
#include "Renderers/OpenGLRenderer/ShrOpenGLVertexFormat.h"
#include "Renderers/OpenGLRenderer/ShrOpenGLVertexShader.h"
#endif

#endif