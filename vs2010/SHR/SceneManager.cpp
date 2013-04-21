#include "SceneManager.h"

SceneManager::SceneManager( Context* context, Renderer* render, InputManager* in, AudioManager* aud )
	:ctxt(context), renderer(render), input( in ), audio( aud )
{
}

SceneManager::~SceneManager()
{
}

int SceneManager::Load()
{
	// Load up a triangle
	GLfloat vVerts[] = { -1.0f, 0.0f, 0.0f,
						  1.0f, 0.0f, 0.0f,
						  1.0f, 0.5f, 0.0f };


	float vArr[8] = {     -0.5f, -0.5f, 
						   0.5f, -0.5f,
						   0.5f, 0.5f,
						   -0.5f, 0.5f };
	int vArrSize = 8;
	float iArr = 0;
	int iArrSize = 0;

	switch( ctxt->level )
	{
	case 1:
		object = new SimpleObject( 7, vArr, vArrSize, &iArr, iArrSize );
		renderer->addObject( object );
		batch = new GLBatch();
		batch->Begin(GL_TRIANGLES, 3);
		batch->CopyVertexData3f(vVerts);
		batch->End();
		renderer->addBatch(batch);
		break;
	default:

		break;
	}
	return 0;
}

int SceneManager::Unload()
{
	switch( ctxt->level )
	{
	case 1:
		delete object;
		delete batch;
		break;
	default:
		break;
	}

	return 0;
}

int SceneManager::Update()
{
	Uint16 key;

	switch( ctxt->level )
	{
	case 1:
		key = input->handleKeys();
		if( key == 'q' )
		{
			object->renderMe = !object->renderMe;
		}
		break;
	default:
		break;
	}
	return 0;
}