/**
 * Visual.h
 *
 * Auxiliar class that helps us with the use of shaders.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details http://www.gnu.org/licenses/.
 */#ifndef SHR_VISUAL
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