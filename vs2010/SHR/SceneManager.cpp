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

	Level lvl;
	levels.push_back(lvl);

	unsigned int batC;
	unsigned int objC;
	unsigned int musC;
	unsigned int actC;
	unsigned int textC;

	switch( ctxt->level )
	{
	case 1:

		// Add music to the audio manager
		for( musC = 0; musC < lvl.songs.size(); musC++ )
		{
			ctxt->audio->loadMusic( lvl.songs.at(musC) );
		}
		// Load the textures into the texture manager
		for( textC = 0; textC < lvl.texts.size(); textC++ )
		{
			ctxt->textMgr->addTexture( lvl.texts.at(textC) );
		}
		// Load these textures
		ctxt->textMgr->Init2();
		// Add the objects to the renderer
		for( objC = 0; objC < lvl.objects.size(); objC++ )
		{
			ctxt->renderer->addObject(lvl.objects.at(objC));
		}
		// Add actors to the renderer
		for( actC = 0; actC < lvl.actors.size(); actC++ )
		{
			ctxt->renderer->addActor(lvl.actors.at(actC));
		}
		// Add the batches to the renderer
		for( batC = 0; batC < lvl.batches.size(); batC++ )
		{
			ctxt->renderer->addBatch(lvl.batches.at(batC));
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
		//delete rocketBatch;
		//delete bgBatch;
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
			levels.at(0).objects.at(0)->renderMe = !levels.at(0).objects.at(0)->renderMe;
		}
		break;
	default:
		break;
	}
	return 0;
}