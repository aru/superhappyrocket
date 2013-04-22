#include "SceneManager.h"

SceneManager::SceneManager( Context* context )
	:ctxt(context)
{
}

SceneManager::~SceneManager()
{
}

int SceneManager::Load()
{
	//// Load up a triangle
	//GLfloat vVerts[] = { -1.0f, 0.0f, 0.0f,
	//					  1.0f, 0.0f, 0.0f,
	//					  1.0f, 0.5f, 0.0f };


	//float vArr[8] = {     -0.5f, -0.5f, 
	//					   0.5f, -0.5f,
	//					   0.5f, 0.5f,
	//					   -0.5f, 0.5f };
	//int vArrSize = 8;
	//float iArr = 0;
	//int iArrSize = 0;

	Level lvl;
	unsigned int batC;
	unsigned int objC;
	unsigned int musC;
	unsigned int bgbatC;

	switch( ctxt->level )
	{
	case 1:
		// Add music to the audio manager
		for( musC = 0; musC < lvl.songs.size(); musC++ )
		{
			ctxt->audio->loadMusic( lvl.songs.at(musC) );
		}
		// Add the objects to the renderer
		for( objC = 0; objC < lvl.objects.size(); objC++ )
		{
			ctxt->renderer->addObject(lvl.objects.at(objC));
		}
		// Add the batches to the renderer
		for( batC = 0; batC < lvl.batches.size(); batC++ )
		{
			ctxt->renderer->addBatch(lvl.batches.at(batC));
		}
			// Add the batches to the renderer
		for( bgbatC = 0; bgbatC < lvl.batches.size(); bgbatC++ )
		{
			ctxt->renderer->addBatch(lvl.batches.at(bgbatC));
		}
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
		delete bgBatch;
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
		key = ctxt->input->handleKeys();
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