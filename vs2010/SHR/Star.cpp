#include "Star.h"

Star::Star()
{
}

Star::~Star()
{
}

int Star::Draw2()
{
	// Declare a light position that matters to us
	static GLfloat vLightPos[] = { 0.0f, 0.0f, 0.0f };
	// Get the actual light position that we care about, light0 in this case
	shrLightArr().at(0)->lightFrame->GetOrigin(vLightPos);
	// Declare a dummy color for the light (white)
	static GLfloat vWhite[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	// Get the actual light color from the light
	m3dCopyVector4(vWhite, shrLightArr().at(0)->color );

	shrCamera()->modelViewMatrix->MultMatrix(frame);
	// Bind texture if there is one
	if( textureFile > 0 )
		ctxt->textMgr->bindTexture(textureFile - 1);
	// Use the selected shader
	ctxt->mShader->UseStockShader(GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF,
                                     shrCamera()->modelViewMatrix->GetMatrix(),
                                     shrCamera()->transformPipeline->GetProjectionMatrix(),
                                     vLightPos, 
                                     vWhite,
                                     0);
	batch.Draw();
	return 0;
}