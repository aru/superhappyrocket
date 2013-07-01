#include "Context.h"

Context::Context()
	:quit(false)
{

}

Context::Context(char* file)
	:quit(false)
{
	// Load the context from a file
	LoadContext( file );
	// Start the audio
	audio = new AudioManager( this );
	// Start the input handler
	input = new InputManager( this );
	// Start the texture manager
	textMgr = new TextureManager( this );
	// Start the shader manger
	mShader = new GLShaderManager();
	// Start the scene manager
	scene = new SceneManager( this );
	// Start the camera manager
	mCamera = new CameraManager( this );
	//Initialize OpenGL
	renderer = new Renderer( this );
	// Initialize Assimp Manager
	aManager = new AssimpManager( this );
}

Context::~Context()
{
	delete renderer;
	delete audio;
	delete input;
	delete scene;
}

int Context::LoadContext(char* file)
{
	ifstream ctxtFile;

	ctxtFile.open( file );
	if( ctxtFile.is_open() )
	{
		ctxtFile >> width;
		ctxtFile >> height;
		ctxtFile >> bpp;
		ctxtFile >> vMode;
		ctxtFile >> level;
	}
	else 
	{
		printf("Error loading context: %s", file);
	}

	ctxtFile.close();

	return 0;
}

int Context::SaveContext(char* file)
{
	ofstream ctxtFile;
	ctxtFile.open( file );
	if( ctxtFile.is_open() )
	{
		ctxtFile << width << endl;
		ctxtFile << height << endl;
		ctxtFile << bpp << endl;
		ctxtFile << vMode << endl;
		ctxtFile << level << endl;
	}
	ctxtFile.close();

	return 0;
}