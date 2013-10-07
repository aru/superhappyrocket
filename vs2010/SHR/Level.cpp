#include "Level.h"

Level::Level()
{
}

Level::Level( Context* pctxt )
	:ctxt(pctxt)
{
}

Level::~Level()
{
}

/* Called only once at the time of loading the level
 * Declare all of the assets in a level */
void Level::LoadContent()
{
	/* Music used in the level */
	// Load music
	char * song = "../../content/sounds/shr_gp_music_0.wav";
	songs.push_back(song);

	/* Textures used in the level */
	// Textures used in this level
	Texture2D* haruhiText;
	haruhiText = new Texture2D("haruhi.tga", GL_LINEAR, GL_LINEAR, GL_REPEAT );
	texts.push_back(haruhiText);

	Texture2D* coolText;
	coolText = new Texture2D("CoolTexture.tga", GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR, GL_CLAMP_TO_EDGE );
	texts.push_back(coolText);

	/* Assimp models used in the level */
	/*shrMeshLoader* stage = new shrMeshLoader( "./../../Models/249.3ds", ctxt );
	stage->frame.RotateLocalX( 10.0f );
	assimpMesh.push_back( stage );*/

	/* Assimp models used in the level */
	/*shrMeshLoader* stage2 = new shrMeshLoader( "./../../Models/catlow1.3ds", ctxt );
	stage2->frame.RotateLocalX( -10.0f );
	assimpMesh.push_back( stage2 );*/

	/* Add Lights to our scene */
	static GLfloat vWhite[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	static GLfloat vLightPos[] = { 0.0f, 0.0f, 0.0f, 1.0f};

	Light* newLight = new Light( vLightPos, vWhite );
	lights.push_back( newLight );

	/* Draw a small ball to represent the light */
	gltMakeSphere( newLight->triBatch, 0.25f, 26, 13 );
	//gltMakeCube( newLight->batch, 1.0f );
	newLight->tBatch = true;
	newLight->renderMe = true;

	/* Geometry used in the level */

	// Load up a triangle
	GLfloat vVerts2[] = { -1.0f, 0.0f, 0.0f,
						  1.0f, 0.0f, 0.0f,
						  1.0f, 0.5f, 0.0f };


	float vArr[8] = {     -0.5f, -0.5f, 
						   0.5f, -0.5f,
						   0.5f, 0.5f,
						   -0.5f, 0.5f };

	GLfloat vVerts[] = { -0.5f, 0.0f, 0.0f, 
		                  0.5f, 0.0f, 0.0f,
						  0.0f, 0.5f, 0.0f };

	GLfloat vColors [] = { 1.0f, 0.0f, 0.0f, 1.0f,
		                   0.0f, 1.0f, 0.0f, 1.0f,
						   0.0f, 0.0f, 1.0f, 1.0f };

	GLfloat vTexCoords [] = { 0.0f, 0.0f,
		                      1.0f, 0.0f, 
						      0.5f, 1.0f };

	// Six sides of a cube map
	const char *szCubeFaces[6] = { "pos_x.tga", "neg_x.tga", "pos_y.tga", "neg_y.tga", "pos_z.tga", "neg_z.tga" };

	GLenum  cube[6] = {  GL_TEXTURE_CUBE_MAP_POSITIVE_X,
                     GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
                     GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
                     GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
                     GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
                     GL_TEXTURE_CUBE_MAP_NEGATIVE_Z };

	int vArrSize = 8;
	float iArr = 0;
	int iArrSize = 0;

	SimpleObject* obj;
	GLBatch* bat;
	SimpleObject* betterRocket;
	SimpleObject* betterRocket2;
	//ShadedObject* shadedRocket;
	GLBatch* bgBatch;
	GLTriangleBatch     sphereBatch;

	obj = new SimpleObject( 7, vArr, vArrSize, &iArr, iArrSize );
	//objects.push_back(obj);

	bat = new GLBatch();
	bat->Begin(GL_TRIANGLES, 3);
	bat->CopyVertexData3f(vVerts);
	bat->End();
	//batches.push_back(bat);

	//betterRocket = new SimpleObject();
	betterRocket = new ShadedObject();
	//gltMakeCube( betterRocket->batch, 1.0f );
	betterRocket->batch.Begin(GL_TRIANGLES, 3,  1);
	betterRocket->batch.CopyVertexData3f(vVerts);
	betterRocket->batch.CopyTexCoordData2f(vTexCoords, 0);
	//betterRocket->batch.CopyColorData4f(vColors);
	betterRocket->batch.End();
	betterRocket->textureFile = 1; // haruhi text file
	//betterRocket->shaderFile = GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF;
	betterRocket->shaderFile = shrShader()->LoadShaderPairWithAttributes("./../../shaders/TexturedIdentity.vp", "./../../shaders/TexturedIdentity.fp", 2, GLT_ATTRIBUTE_VERTEX,"vVertex", GLT_ATTRIBUTE_TEXTURE0, "vTexCoords");
	//betterRocket->shaderFile = gltLoadShaderPairSrcWithAttributes("ShadedIdentity.vp", "ShadedIdentity.fp", 2, GLT_ATTRIBUTE_VERTEX,"vVertex", GLT_ATTRIBUTE_COLOR, "vColor");
	betterRocket->frame.SetOrigin(2.0f,2.0f,0.0f);
	actors.push_back(betterRocket);

	betterRocket2 = new SimpleObject();
	gltMakeCube( betterRocket2->batch, 1.0f );
	betterRocket2->textureFile = 2; 
	betterRocket2->shaderFile = GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF;
	//actors.push_back(betterRocket2);

	bgBatch = new GLBatch();
	bgBatch->Begin(GL_TRIANGLE_FAN, 4, 1);
	bgBatch->MultiTexCoord2f(0, 0.0f, 1.0f);
	bgBatch->Vertex3f(-10.0f, 10.0f, -100.0f);
	
	bgBatch->MultiTexCoord2f(0, 0.0, 0.0f);
    bgBatch->Vertex3f(-10.0f, -10.0f, -100.0f);
	
	bgBatch->MultiTexCoord2f(0, 1.0, 0.0);
	bgBatch->Vertex3f(10.0f, -10.0f, -100.0f);
	
	bgBatch->MultiTexCoord2f(0, 1.0f, 1.0);
	bgBatch->Vertex3f(10.0f, 10.0f, -100.0f);
	bgBatch->End();
	//batches.push_back(bgBatch);
}

/* Free all of the assets in the level, please don't forget */
void Level::UnloadContent()
{
	/* Clear is called at time of vector destruction
	 * but let's just be sure */
	songs.clear();
	textures.clear();
	texts.clear();
	objects.clear();
	for( unsigned int i=0; i < actors.size(); i++ )
		free( actors.at(i) );
	actors.clear();
	batches.clear();
}

/* Draw is called ONCE for a level,  
 * Initialize everything in here, things like
 * initial postion of objects, etc */
void Level::Draw( int GameTimeElapsed )
{

}


/* Update is where you add code to check for user input
 * This might include the management of the game state, 
 * the processing of user input, 
 * or the updating of simulation data,
 * also where you update the state of your game... 
 * this could be something as simple as a menu selector bar, 
 * or the position of your ship, enemy AI, gravity, and so on  
 * Anything that must be checked every frame should go here.
 * GameTimeElapsed is the value in milliseconds that has elapsed */
void Level::Update( int GameTimeElapsed )
{
	
}