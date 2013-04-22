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
	GLBatch* bgBatch;

	obj = new SimpleObject( 7, vArr, vArrSize, &iArr, iArrSize );
	objects.push_back(obj);

	bat = new GLBatch();
	bat->Begin(GL_TRIANGLES, 3);
	bat->CopyVertexData3f(vVerts);
	bat->End();
	batches.push_back(bat);
	

	bgBatch = new GLBatch();
	bgBatch->Begin(GL_TRIANGLES, 36, 1);
    
	M3DVector3f vFrontLeftB = { -0.7f, -0.7f, 0.7f };
	M3DVector3f vFrontRightB = { 0.7f, -0.7f, 0.7f };
	M3DVector3f vBackLeftB = { -0.7f, -0.7f, -0.7f };
	M3DVector3f vBackRightB = { 0.7f, -0.7f, -0.7f };
	M3DVector3f vFrontLeftU = { -0.7f, 0.7f, 0.7f };
	M3DVector3f vFrontRightU = { 0.7f, 0.7f, 0.7f };
	M3DVector3f vBackLeftU = { -0.7f, 0.7f, -0.7f };
	M3DVector3f vBackRightU = { 0.7f, 0.7f, -0.7f };
	M3DVector3f n;

	// front(BACK)
	m3dFindNormal(n, vFrontLeftU, vFrontLeftB, vFrontRightB);
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	bgBatch->Vertex3fv(vFrontLeftU);		
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 1.0f, 1.0f );
	bgBatch->Vertex3fv(vFrontLeftB);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	bgBatch->Vertex3fv(vFrontRightB);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 0.0f, 0.0f );
	bgBatch->Vertex3fv(vFrontRightU);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	bgBatch->Vertex3fv(vFrontLeftU);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	bgBatch->Vertex3fv(vFrontRightB);
    

	
	// back (FRONT)
	m3dFindNormal(n, vBackLeftU, vBackRightU, vBackRightB);
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	bgBatch->Vertex3fv(vBackLeftU);		
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 1.0f, 1.0f );
	bgBatch->Vertex3fv(vBackRightU);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	bgBatch->Vertex3fv(vBackRightB);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 0.0f, 0.0f );
	bgBatch->Vertex3fv(vBackLeftB);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	bgBatch->Vertex3fv(vBackLeftU);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	bgBatch->Vertex3fv(vBackRightB);

	// Left (RIGHT)
	m3dFindNormal(n, vFrontLeftU, vBackLeftU, vBackLeftB);
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	bgBatch->Vertex3fv(vFrontLeftU);		
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 1.0f, 1.0f );
	bgBatch->Vertex3fv(vBackLeftU);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	bgBatch->Vertex3fv(vBackLeftB);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 0.0f, 0.0f );
	bgBatch->Vertex3fv(vFrontLeftB);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	bgBatch->Vertex3fv(vFrontLeftU);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	bgBatch->Vertex3fv(vBackLeftB);


	// Right (LEFT)
	m3dFindNormal(n, vFrontRightU, vFrontRightB, vBackRightB);
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	bgBatch->Vertex3fv(vFrontRightU);		
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 1.0f, 1.0f );
	bgBatch->Vertex3fv(vFrontRightB);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	bgBatch->Vertex3fv(vBackRightB);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 0.0f, 0.0f );
	bgBatch->Vertex3fv(vBackRightU);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	bgBatch->Vertex3fv(vFrontRightU);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	bgBatch->Vertex3fv(vBackRightB);

	// Up 
	m3dFindNormal(n, vFrontRightU, vBackRightU, vBackLeftU);
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	bgBatch->Vertex3fv(vFrontRightU);		
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 1.0f, 1.0f );
	bgBatch->Vertex3fv(vBackRightU);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	bgBatch->Vertex3fv(vBackLeftU);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 0.0f, 0.0f );
	bgBatch->Vertex3fv(vFrontLeftU);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	bgBatch->Vertex3fv(vFrontRightU);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	bgBatch->Vertex3fv(vBackLeftU);

	// Down 
	m3dFindNormal(n, vFrontRightB, vFrontLeftB, vBackLeftB);
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	bgBatch->Vertex3fv(vFrontRightB);		
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 1.0f, 1.0f );
	bgBatch->Vertex3fv(vFrontLeftB);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	bgBatch->Vertex3fv(vBackLeftB);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 0.0f, 0.0f );
	bgBatch->Vertex3fv(vBackRightB);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 0.0f, 1.0f );
	bgBatch->Vertex3fv(vFrontRightB);
    
	bgBatch->Normal3fv(n);
	bgBatch->MultiTexCoord2f(0, 1.0f, 0.0f );
	bgBatch->Vertex3fv(vBackLeftB);

	bgBatch->End();

	batches.push_back(bgBatch);

}

Level::~Level()
{
}