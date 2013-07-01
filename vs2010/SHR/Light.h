#ifndef SHR_LIGHT
#define SHR_LIGHT

#include "Context.h"

class Light
{
public:
	Light();
	~Light();

	M3DMatrix44f		 light;
	M3DVector4f          color; // Color of this light
	GLFrame              *lightFrame;
	GLMatrixStack		 *modelViewMatrix;		// Modelview Matrix
	GLMatrixStack		 *projectionMatrix;		// Projection Matrix
	GLGeometryTransform	 *transformPipeline;		// Geometry Transform Pipeline
};

#endif