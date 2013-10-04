#include "ShadedObject.h"

ShadedObject::ShadedObject()
{
}

ShadedObject::~ShadedObject()
{
}

int ShadedObject::Draw2()
{
	// Elements needed for the shading
	GLint iTextureUniform = glGetUniformLocation(myTexturedIdentityShader, "colorMap");
	glUniform1i(iTextureUniform,0);

	if( tBatch )
		triBatch.Draw();
	else
		batch.Draw();

	return 0;
}