#include "SimpleObject.h"

SimpleObject::SimpleObject()
	:textureFile(0), shaderFile(0), tBatch(false)
{
}

SimpleObject::SimpleObject( const SimpleObject& obj )
{
	textureFile = obj.textureFile;
	vertex = obj.vertex;
	index = obj.index;
	normal = obj.normal;
	color = obj.color;
	texture = obj.texture;

}

SimpleObject::~SimpleObject()
{
	vertex.clear();
	index.clear();
	normal.clear();
	color.clear();
	texture.clear();
}

const int SimpleObject::Draw()
{
	if( tBatch)
		triBatch.Draw();
	else
		batch.Draw();

	return SHR_SUCCESS;
}

/* A SimpleObject has either a texture or it doesn't */
const int SimpleObject::Draw( Camera* camera, GLShaderManager* shaderManager, TextureManager* textureManager, Light* light )
{
	/* Get the camera matrix */
	camera->cameraFrame.GetCameraMatrix(camera->camera, false);

	/* Get the final transformation for this object */
	frame.GetMatrix( mScaleMatrix );
	m3dScaleMatrix44( mScaleMatrix, scaleVector );

	/* Apply Actor Transform */
	camera->modelViewMatrix.PushMatrix();

	camera->modelViewMatrix.MultMatrix( camera->camera );
	camera->modelViewMatrix.MultMatrix( frame );
	camera->modelViewMatrix.MultMatrix( mScaleMatrix );

	switch( shaderFile ) 
	{
	case GLT_SHADER_FLAT:
		shaderManager->UseStockShader( GLT_SHADER_FLAT,
									   camera->transformPipeline.GetModelViewProjectionMatrix(),
									   light->color );
		break;
	case GLT_SHADER_POINT_LIGHT_DIFF:
		shaderManager->UseStockShader( GLT_SHADER_POINT_LIGHT_DIFF,
						               camera->modelViewMatrix.GetMatrix(),
							           camera->transformPipeline.GetProjectionMatrix(),
									   light->position, 
									   light->color,
									   0);
		break;
	case GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF:
		if( textureFile == 0 ) 
		{
			printf("No texture file to draw textured object\n");
			// Bail out, this is wrong
			SDL_assert(1);
		}
		/* Set the shader */
		shaderManager->UseStockShader( GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF,
						               camera->modelViewMatrix.GetMatrix(),
							           camera->transformPipeline.GetProjectionMatrix(),
									   &(light->position), 
									   &(light->color),
									   0);
		/* Set the texture in here */
		textureManager->bindTexture( textureFile - 1 );
		break;
	default:
		/* We really haven't thought of this case, just bail out, 
		 * did you set a wrong value? */
		printf("Check that the shader exists\n");
		SDL_assert(1);
		break;
	}

	/* Actually do the drawing */
	if( tBatch )
		triBatch.Draw();
	else
		batch.Draw();

	/* Pop Actor Transform */
	camera->modelViewMatrix.PopMatrix();

	return SHR_SUCCESS;
}

const int SimpleObject::Initialize( Context* ctx ) { return SHR_SUCCESS; }
const int SimpleObject::LoadContent() { return SHR_SUCCESS; }
const int SimpleObject::Update() { return SHR_SUCCESS; }
const int SimpleObject::UnloadContent() { return SHR_SUCCESS; }