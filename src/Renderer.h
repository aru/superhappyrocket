#ifndef RENDERER_H
#define RENDERER_H

/*	Quick re-cap
	Things engine needs to do:
		* Everything XNA does with the Game class (will explain later)
	
*/

#include <cassert>
#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

#include "Visual.h"

using namespace std;

class Renderer
{
public:
	// This is where we call our platform-dependent constructor before doing any work, aka SDL.
	void Initialize( int width, int height, int colorFormat, 
		int depthStencilFormat, int numMultiSamples );

	// The platform-dependent destructor(SDL) must call this function after doing all the work.
	void Terminate();

	// Accesss to constructor inputs
	inline int GetWidth() const;
	inline int GetHeight() const;
	inline int GetColorFormat() const;
	inline int GetDepthStencilFormat() const;
	inline int GetNumMultisamples() const;

	/* === Resource management. Resources are: vertex formats, vertex buffers, 
		index buffers, textures(in any D), render targets
		vertex shaders and pixel shaders. The functions do the following (hopefully):


	*/

	void Load();
	void Unload();

	// The entry point to drawing the visible set of a scene graph
	void Draw( const Visual* visual );

	void Update();

private:

	// Support for destructor. Destroy any remaining resources that the
    // application did not explicitly release.
    void DestroyAllVertexFormats ();
    void DestroyAllVertexBuffers ();
    void DestroyAllIndexBuffers ();
    void DestroyAllTexture1Ds ();
    void DestroyAllTexture2Ds ();
    void DestroyAllTexture3Ds ();
    void DestroyAllTextureCubes ();
    void DestroyAllRenderTargets ();
    void DestroyAllVertexShaders ();
    void DestroyAllPixelShaders ();

	// Construction parameters.
    int mWidth;
    int mHeight;
    int mColorFormat;
    int mDepthStencilFormat;
    int mNumMultisamples;

    // Global state.
    bool mReverseCullOrder;

	//============================================================================
	// Platform-dependent portion of the interface.
public:
    // Construction and destruction.  Each platform passes opaquely through
    // 'input' whatever information is needed to create a renderer.
    Renderer (/*RendererInput& input,*/ int width, int height,
        int colorFormat, int depthStencilFormat,
        int numMultisamples);

    ~Renderer ();

	// Viewport management.  The viewport is specified in right-handed screen
    // coordinates.  The origin is the lower-left corner of the screen, the
    // y-axis points upward, and the x-axis points rightward.
    void SetViewport (int xPosition, int yPosition, int width,
        int height);
    void GetViewport (int& xPosition, int& yPosition, int& width,
        int& height) const;
    void SetDepthRange (float zMin, float zMax);
    void GetDepthRange (float& zMin, float& zMax) const;
    void Resize (int width, int height);

	// Support for clearing the color, depth, and stencil buffers.
    void ClearColorBuffer ();
    void ClearDepthBuffer ();
    void ClearStencilBuffer ();
    void ClearBuffers ();
    void ClearColorBuffer (int x, int y, int w, int h);
    void ClearDepthBuffer (int x, int y, int w, int h);
    void ClearStencilBuffer (int x, int y, int w, int h);
    void ClearBuffers (int x, int y, int w, int h);
    void DisplayColorBuffer ();

	// Support for masking color channels during drawing.
    void SetColorMask (bool allowRed, bool allowGreen,
        bool allowBlue, bool allowAlpha);

	// The entry point for drawing 2D buffers (for 2D applications).
    void Draw (const unsigned char* screenBuffer);

    // The entry point for drawing 2D text.
    void Draw (int x, int y, const float color,
        const std::string& message);

private:
    // The entry point for drawing 3D objects, called by the single-object
    // Draw function.
    void DrawPrimitive (const Visual* visual);
};

#endif