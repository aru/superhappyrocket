#include "Level.h"

Level::Level()
{
	// Load music
	char * song = "../../content/sounds/shr_gp_music_0.wav";
	songs.push_back(song);

	// Textures used in this level
	Texture2D* haruhiText;
	haruhiText = new Texture2D("haruhi.tga", GL_LINEAR, GL_LINEAR, GL_REPEAT );
	texts.push_back(haruhiText);

	Texture2D* coolText;
	coolText = new Texture2D("CoolTexture.tga", GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR, GL_CLAMP_TO_EDGE );
	texts.push_back(coolText);

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

	SimpleObject* obj;
	GLBatch* bat;
	SimpleObject* betterRocket;
	SimpleObject* betterRocket2;
	GLBatch* bgBatch;
	GLTriangleBatch     sphereBatch;

	obj = new SimpleObject( 7, vArr, vArrSize, &iArr, iArrSize );
	objects.push_back(obj);

	bat = new GLBatch();
	bat->Begin(GL_TRIANGLES, 3);
	bat->CopyVertexData3f(vVerts);
	bat->End();
	batches.push_back(bat);
	

	

	betterRocket = new SimpleObject();
	gltMakeCube( betterRocket->batch, 1.0f );
	betterRocket->textureFile = 1; // haruhi text file
	betterRocket->shaderFile = GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF;
	betterRocket->frame.SetOrigin(2.0f,2.0f,0.0f);
	actors.push_back(betterRocket);

	betterRocket2 = new SimpleObject();
	gltMakeCube( betterRocket2->batch, 1.0f );
	betterRocket2->textureFile = 2; 
	betterRocket2->shaderFile = GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF;
	actors.push_back(betterRocket2);


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
	batches.push_back(bgBatch);

}

Level::~Level()
{
}