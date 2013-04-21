#ifndef SHR_CONTEXT
#define SHR_CONTEXT

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

class Context 
{
public:
	Context(char* file);
	Context();
	~Context();

	int LoadContext(char* file);
	int SaveContext(char* file);

	bool quit;
	int width, height, bpp, vMode;
	int level;
};

#endif