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

	Level lvl(ctxt);
	lvl.LoadContent();
	levels.push_back(lvl);

	unsigned int batC;
	unsigned int objC;
	unsigned int musC;
	unsigned int actC;
	unsigned int textC;
	unsigned int lightC;
	unsigned int assimpC;

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
		for( lightC = 0; lightC < lvl.lights.size(); lightC++ )
		{
			ctxt->renderer->addLight(lvl.lights.at(lightC));
		}
		// Add assimp meshes
		for( assimpC = 0; assimpC < lvl.assimpMesh.size(); assimpC++ )
		{
			ctxt->renderer->addAssimpMesh(lvl.assimpMesh.at(assimpC));
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
	int deltaTicks = ctxt->timer->get_ticks();
	float linear = 6.0f * (deltaTicks / 1000.0f );
	float angular = float(m3dDegToRad(25.0f * (deltaTicks / 1000.0f )));

	switch( ctxt->level )
	{
	case 1:
		
		if( ctxt->input->keysHeld['q'] ) {
			if( levels.size() > 0 )
				if( levels.at(0).objects.size() > 0 )
					levels.at(0).objects.at(0)->renderMe = false;
		}
		else {
			if( levels.size() > 0 )
				if( levels.at(0).objects.size() > 0 )
					levels.at(0).objects.at(0)->renderMe = true;
		}
		if( ctxt->input->keysHeld[SDLK_UP] )
			shrCamera()->cameraFrame->MoveForward(linear);
		if( ctxt->input->keysHeld[SDLK_DOWN] )
			shrCamera()->cameraFrame->MoveForward(-linear);
		if( ctxt->input->keysHeld[SDLK_LEFT] )
			shrCamera()->cameraFrame->RotateWorld(angular, 0.0f, 1.0f, 0.0f);
		if( ctxt->input->keysHeld[SDLK_RIGHT] )
			shrCamera()->cameraFrame->RotateWorld(-angular, 0.0f, 1.0f, 0.0f);
		if( ctxt->input->keysHeld[SDLK_PERIOD] )
			shrCamera()->cameraFrame->RotateWorld(angular, 1.0f, 0.0f, 0.0f);
		if( ctxt->input->keysHeld[SDLK_COMMA] )
			shrCamera()->cameraFrame->RotateWorld(-angular, 1.0f, 0.0f, 0.0f);
		if( ctxt->input->keysHeld[SDLK_SEMICOLON] )
			shrCamera()->cameraFrame->RotateWorld(angular*2, 0.0f, 0.0f, 1.0f);
		if( ctxt->input->keysHeld[SDLK_l] )
			shrCamera()->cameraFrame->RotateWorld(-angular*2, 0.0f, 0.0f, 1.0f);
		break;
	}
	// update the current level
	levels.at(ctxt->level - 1).Update( deltaTicks );

	return 0;
}