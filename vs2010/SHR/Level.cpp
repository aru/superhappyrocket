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
	//GLBatch* rocketBatch;
	SimpleObject* betterRocket;
	GLBatch* bgBatch;
	GLTriangleBatch     sphereBatch;

	obj = new SimpleObject( 7, vArr, vArrSize, &iArr, iArrSize );
	objects.push_back(obj);

	bat = new GLBatch();
	bat->Begin(GL_TRIANGLES, 3);
	bat->CopyVertexData3f(vVerts);
	bat->End();
	batches.push_back(bat);
	

	//rocketBatch = new GLBatch();

	//rocketBatch->Begin(GL_TRIANGLES, 36, 1);
 //   
	//M3DVector3f vFrontLeftB = { -0.7f, -0.7f, 0.7f };
	//M3DVector3f vFrontRightB = { 0.7f, -0.7f, 0.7f };
	//M3DVector3f vBackLeftB = { -0.7f, -0.7f, -0.7f };
	//M3DVector3f vBackRightB = { 0.7f, -0.7f, -0.7f };
	//M3DVector3f vFrontLeftU = { -0.7f, 0.7f, 0.7f };
	//M3DVector3f vFrontRightU = { 0.7f, 0.7f, 0.7f };
	//M3DVector3f vBackLeftU = { -0.7f, 0.7f, -0.7f };
	//M3DVector3f vBackRightU = { 0.7f, 0.7f, -0.7f };
	//M3DVector3f n;

	//// front(BACK)
	//m3dFindNormal(n, vFrontLeftU, vFrontLeftB, vFrontRightB);
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	//rocketBatch->Vertex3fv(vFrontLeftU);		
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 1.0f, 1.0f );
	//rocketBatch->Vertex3fv(vFrontLeftB);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	//rocketBatch->Vertex3fv(vFrontRightB);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 0.0f, 0.0f );
	//rocketBatch->Vertex3fv(vFrontRightU);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	//rocketBatch->Vertex3fv(vFrontLeftU);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	//rocketBatch->Vertex3fv(vFrontRightB);
 //   

	//
	//// back (FRONT)
	//m3dFindNormal(n, vBackLeftU, vBackRightU, vBackRightB);
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	//rocketBatch->Vertex3fv(vBackLeftU);		
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 1.0f, 1.0f );
	//rocketBatch->Vertex3fv(vBackRightU);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	//rocketBatch->Vertex3fv(vBackRightB);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 0.0f, 0.0f );
	//rocketBatch->Vertex3fv(vBackLeftB);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	//rocketBatch->Vertex3fv(vBackLeftU);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	//rocketBatch->Vertex3fv(vBackRightB);

	//// Left (RIGHT)
	//m3dFindNormal(n, vFrontLeftU, vBackLeftU, vBackLeftB);
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	//rocketBatch->Vertex3fv(vFrontLeftU);		
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 1.0f, 1.0f );
	//rocketBatch->Vertex3fv(vBackLeftU);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	//rocketBatch->Vertex3fv(vBackLeftB);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 0.0f, 0.0f );
	//rocketBatch->Vertex3fv(vFrontLeftB);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	//rocketBatch->Vertex3fv(vFrontLeftU);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	//rocketBatch->Vertex3fv(vBackLeftB);


	//// Right (LEFT)
	//m3dFindNormal(n, vFrontRightU, vFrontRightB, vBackRightB);
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	//rocketBatch->Vertex3fv(vFrontRightU);		
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 1.0f, 1.0f );
	//rocketBatch->Vertex3fv(vFrontRightB);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	//rocketBatch->Vertex3fv(vBackRightB);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 0.0f, 0.0f );
	//rocketBatch->Vertex3fv(vBackRightU);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	//rocketBatch->Vertex3fv(vFrontRightU);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	//rocketBatch->Vertex3fv(vBackRightB);

	//// Up 
	//m3dFindNormal(n, vFrontRightU, vBackRightU, vBackLeftU);
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	//rocketBatch->Vertex3fv(vFrontRightU);		
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 1.0f, 1.0f );
	//rocketBatch->Vertex3fv(vBackRightU);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	//rocketBatch->Vertex3fv(vBackLeftU);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 0.0f, 0.0f );
	//rocketBatch->Vertex3fv(vFrontLeftU);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	//rocketBatch->Vertex3fv(vFrontRightU);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	//rocketBatch->Vertex3fv(vBackLeftU);

	//// Down 
	//m3dFindNormal(n, vFrontRightB, vFrontLeftB, vBackLeftB);
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	//rocketBatch->Vertex3fv(vFrontRightB);		
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 1.0f, 1.0f );
	//rocketBatch->Vertex3fv(vFrontLeftB);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	//rocketBatch->Vertex3fv(vBackLeftB);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 0.0f, 0.0f );
	//rocketBatch->Vertex3fv(vBackRightB);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	//rocketBatch->Vertex3fv(vFrontRightB);
 //   
	//rocketBatch->Normal3fv(n);
	//rocketBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	//rocketBatch->Vertex3fv(vBackLeftB);

	//rocketBatch->End();
	//batches.push_back(rocketBatch);

	betterRocket = new SimpleObject();
	gltMakeCube( betterRocket->batch, 1.0f );
	betterRocket->textureFile = 1; // haruhi text file
	betterRocket->shaderFile = GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF;
	betterRocket->frame.SetOrigin(2.0f,2.0f,0.0f);
	actors.push_back(betterRocket);

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