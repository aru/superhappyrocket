#ifndef GRAPHICSLIB_H
#define GRAPHICSLIB_H

//#include "MathematicsLIB.h"

// Expose this define to allow resetting of render state and other state in
// the Renderer::Draw (const Visual*, const VisualEffectInstance*) call.
//#define WM5_RESET_STATE_AFTER_DRAW

// Enable this to allow counting the number of pixels drawn in
// Renderer::DrawPrimitive.
//#define WM5_QUERY_PIXEL_COUNT

// Enable this to draw text using display lists in OpenGL; otherwise, text is
// drawn manually using bitmapped fonts.  Currently, the GLX renderer does not
// have the ability to use text display lists.
#ifndef __LINUX__
    #define USE_TEXT_DISPLAY_LIST
#endif

// Some OpenGL 2.x drivers are not handling normal attributes correctly.
// This is a problem should you want to use the normal vector to pass a
// 4-tuple of information to the shader.  The OpenGL 1.x glNormalPointer
// assumes the normals are 3-tuples.  If you know that your target
// machines correctly support OpenGL 2.x normal attributes, expose the
// following #define.  Otherwise, the renderer will use the OpenGL 1.x
// glNormalPointer.
//
// TODO.  I must be misunderstanding how generic attributes work.  On the
// Macintosh, whether PowerPC or Intel, with NVIDIA graphics cards, the
// generic attributes for normals does not work.
#ifndef __APPLE__
    #define USE_OPENGL2_NORMAL_ATTRIBUTES
#endif

#endif