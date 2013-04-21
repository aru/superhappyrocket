#include "Level.h"

Level::Level()
{
	// Load music
	char * song = "../../content/sounds/shr_gp_music_0.wav";
	songs.push_back(song);

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

	obj = new SimpleObject( 7, vArr, vArrSize, &iArr, iArrSize );
	objects.push_back(obj);

	bat = new GLBatch();
	bat->Begin(GL_TRIANGLES, 3);
	bat->CopyVertexData3f(vVerts);
	bat->End();

	batches.push_back(bat);

}

Level::~Level()
{
}