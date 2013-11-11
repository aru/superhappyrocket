#include "Level1.h"

Level1::Level1( Context* ctx )
	:BaseLevel( ctx )
{
}

const int Level1::LoadContent()
{
	/* Music used in this level */
	song = "../../content/sounds/crystals.wav";
	
	/* Additional sounds in this level */
	char* sound1 = "../../content/sounds/shr_fx_0.wav";
	sounds.push_back( sound1 );

	/* Add our Lights */
	static GLfloat vWhite[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	static GLfloat vLightPos[] = { 0.0f, 1.0f, 0.0f, 1.0f};
	Light* light0;
	light0 = new Light( vLightPos, vWhite );
	light0->tBatch = true;
	gltMakeSphere( light0->triBatch, 1.0f, 15, 15 );
	light0->shaderFile = GLT_SHADER_FLAT;
	lightSource = light0;
	//actors.push_back( (SimpleObject*)light0 );

	/* Add a cube map */
	CubeMap* cubeMap;
	cubeMap = new CubeMap( 40.0f, 
						   "../../content/textures/pos_x1.tga", "../../content/textures/neg_x1.tga", "../../content/textures/pos_y1.tga", 
						   "../../content/textures/neg_y1.tga", "../../content/textures/pos_z1.tga", "../../content/textures/neg_z1.tga");
	actors.push_back( (SimpleObject*)cubeMap );

	/* Add an object to reflect the cube map */
	ReflectedObject* reflectedObject;
	reflectedObject = new ReflectedObject( "../../content/textures/tarnish.tga", cubeMap->textureFile );
	gltMakeSphere( reflectedObject->triBatch, 2.0f, 52, 30 );
	reflectedObject->frame.MoveUp( 5.0f );
	actors.push_back( (SimpleObject*)reflectedObject );

	/* Add an assimp model */
	rocket = new assimpMesh( "../../content/models/rocket249.3ds", ctxt );
	rocket->frame.SetOrigin( 0.0f, 0.0f, 12.0f );
	rocket->frame.RotateLocalZ( float( m3dDegToRad( 90.0f ) ));
	rocket->frame.RotateLocalX( float( m3dDegToRad( -90.0f ) ));
	rocket->frame.GetForwardVector( rocketForwardVector );
	rocket->frame.GetUpVector( rocketUpVector );
	actors.push_back( (SimpleObject*)rocket );

	/* Add an assimp model */
	cat = new assimpMesh( "../../content/models/catlow249.3ds", ctxt );
	cat->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
	cat->frame.TranslateWorld( 0.0f, 4.0f, -10.0f );
	cat->frame.TranslateWorld( -5.0f, 0.0f, 0.0f );
	actors.push_back( (SimpleObject*)cat );

	/* Add an assimp model */
	star = new assimpMesh( "../../content/models/estrella249.3ds", ctxt );
	star->frame.RotateLocalZ( float( m3dDegToRad( 90.0f ) ));
	star->frame.MoveForward( 50.0f );
	star->frame.MoveRight( 0.0f );
	actors.push_back( (SimpleObject*)star );

	/* Add an assimp model */
	star2 = new assimpMesh( "../../content/models/estrella249.3ds", ctxt );
	star2->frame.RotateLocalZ( float( m3dDegToRad( 90.0f ) ));
	star2->frame.MoveForward( 50.0f );
	star2->frame.MoveRight( 0.0f );
	actors.push_back( (SimpleObject*)star2 );

	/* Add an assimp model */
	star3 = new assimpMesh( "../../content/models/estrella249.3ds", ctxt );
	star3->frame.RotateLocalZ( float( m3dDegToRad( 90.0f ) ));
	star3->frame.MoveForward( 50.0f );
	star3->frame.MoveRight( 0.0f );
	actors.push_back( (SimpleObject*)star3 );

	/* Add an assimp model */
	star4 = new assimpMesh( "../../content/models/estrella249.3ds", ctxt );
	star4->frame.RotateLocalZ( float( m3dDegToRad( 90.0f ) ));
	star4->frame.MoveForward( 50.0f );
	star4->frame.MoveRight( 0.0f );
	actors.push_back( (SimpleObject*)star4 );

	/* Add an assimp model */
	star5 = new assimpMesh( "../../content/models/estrella249.3ds", ctxt );
	star5->frame.RotateLocalZ( float( m3dDegToRad( 90.0f ) ));
	star5->frame.MoveForward( 50.0f );
	star5->frame.MoveRight( 0.0f );
	actors.push_back( (SimpleObject*)star5 );

	/* Add an assimp model */
	build = new assimpMesh( "../../content/models/edi1.3ds", ctxt );
	build->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
	build->frame.MoveForward( 5.0f );
	build->frame.MoveRight( 3.0f );
	actors.push_back( (SimpleObject*)build );

	/* Add an assimp model */
	build2 = new assimpMesh( "../../content/models/edi2.3ds", ctxt );
	build2->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
	build2->frame.MoveForward( 5.0f );
	build2->frame.MoveRight( -3.0f );
	actors.push_back( (SimpleObject*)build2 );

	/* Add an assimp model */
	build3 = new assimpMesh( "../../content/models/edi3.3ds", ctxt );
	build3->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
	build3->frame.MoveForward( 5.0f );
	build3->frame.MoveRight( 3.0f );
	actors.push_back( (SimpleObject*)build3 );

	return SHR_SUCCESS;
}

Level1::~Level1()
{
	unsigned int i;
	for( i = 0; i < actors.size(); i++ )
	{
		delete actors.at(i);
	}
	actors.clear();

	for( i = 0; i < textures.size(); i++ )
	{
		delete textures.at(i);
	}
	textures.clear();

	sounds.clear();
}

const int Level1::Initialize()
{
	/* Get the time our level has started */
	startTicks = ctxt->timer->get_ticks();

	ctxt->camera->cameraFrame.MoveForward( -15.0f );
	ctxt->camera->cameraFrame.GetForwardVector( cameraForwardVector );
	ctxt->camera->cameraFrame.GetUpVector( cameraUpVector );
	ctxt->camera->cameraFrame.GetOrigin( cameraOrigin );
	ctxt->camera->modelViewMatrix.GetMatrix( cameraMatrix );

	//ctxt->camera->cameraFrame.TranslateWorld( 0.0f, 0.0f, 10.0f );

	return SHR_SUCCESS;
}

const int Level1::Update( int gameTime )
{
	/* Get the time this level has been online */
	currentTicks = gameTime - startTicks;
	/* Get the time difference between this update and the last */
	deltaTicks = ( (gameTime - currentTicks) / 1000 );

	float linear = (0.5f * deltaTicks) / 100;
	float angular = float(m3dDegToRad( (deltaTicks * 1.5f ) / 100));

	if( currentTicks < 10000 )
	{
		cat->frame.RotateWorld( -angular, 0.0f, 1.0f, 0.0f );

		rocket->frame.RotateWorld( -angular, 0.0f, 1.0f, 0.0f );
		rocket->frame.RotateLocal( angular, 0.0f, 1.0f, 0.0f );
		rocket->frame.Normalize();

		star->frame.RotateLocal( -angular, 1.0f, 1.0f, 0.0f );
		star2->frame.RotateLocal( angular, 1.0f, 1.0f, 0.0f );
		star3->frame.RotateLocal( -angular, 1.0f, 1.0f, 0.0f );
		star4->frame.RotateLocal( angular, 1.0f, 1.0f, 0.0f );
		star5->frame.RotateLocal( -angular, 1.0f, 1.0f, 0.0f );

	}
	if( currentTicks > 10000 && currentTicks < 10500 )
	{
		rocket->frame.SetForwardVector( rocketForwardVector );
		rocket->frame.SetUpVector( rocketUpVector );

		ctxt->camera->cameraFrame.SetForwardVector( cameraForwardVector );
		ctxt->camera->cameraFrame.SetUpVector( cameraUpVector );
		ctxt->camera->cameraFrame.SetOrigin( cameraOrigin );
		ctxt->camera->cameraFrame.MoveUp( 1.0f );
		ctxt->camera->cameraFrame.RotateLocalX( float(m3dDegToRad(5.0f)) );

		ctxt->audio->PlayMusic();
	}
	if( currentTicks >= 10500 )
	{
		ctxt->audio->PlayMusic();
		rocket->frame.RotateLocal( angular, 0.0f, 1.0f, 0.0f );
		star->frame.RotateLocal( -angular, 1.0f, 1.0f, 0.0f );
		star->frame.TranslateWorld( 0.0f, 0.0f, linear );
	}
	if( currentTicks >= 13000 )
	{
		star2->frame.RotateLocal( angular, 1.0f, 1.0f, 0.0f );
		star2->frame.TranslateWorld( 0.0f, 0.0f, linear );
	}
	if( currentTicks >= 15000 )
	{
		star3->frame.RotateLocal( -angular, 1.0f, 1.0f, 0.0f );
		star3->frame.TranslateWorld( 0.0f, 0.0f, linear );
	}
	if( currentTicks >= 17000 )
	{
		star4->frame.RotateLocal( angular, 1.0f, 1.0f, 0.0f );
		star4->frame.TranslateWorld( 0.0f, 0.0f, linear );
	}
	if( currentTicks >= 19000 )
	{
		star5->frame.RotateLocal( -angular, 1.0f, 1.0f, 0.0f );
		star5->frame.TranslateWorld( 0.0f, 0.0f, linear );
	}

	if( ctxt->input->isKeyPressed( SDL_SCANCODE_RIGHT ) )
	{
		/* Usual right */
		if( rocket->frame.GetOriginX() <= 1.25f )
		{
			rocket->frame.TranslateWorld( 0.1f * linear, 0.0f, 0.0f );
		}
	}
	if( ctxt->input->isKeyPressed( SDL_SCANCODE_LEFT ) )
	{
		/* Usual left */
		if( rocket->frame.GetOriginX() >= -1.25f )
		{
			rocket->frame.TranslateWorld( 0.1f * -linear, 0.0f, 0.0f );
		}
	}

	return SHR_SUCCESS;
}