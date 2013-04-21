#include "Context.h"

Context::Context()
	:quit(false)
{

}

Context::Context(char* file)
	:quit(false)
{
	LoadContext(file);
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