#ifndef SHR_VISUAL
#define SHR_VISUAL
#include "OpenGLRenderer.h"

class Visual;

class Visual
{
public:
	Visual();
	~Visual();

	GLShaderManager		shaderManager;

	int UseShader(GLShaderManager *shader);


};

#endif