#ifndef SHR_LEVEL
#define SHR_LEVEL

class Level;
#include "SceneManager.h"

class Level
{
public:
	Level();
	~Level();

	vector<char*> songs;
	vector<SimpleObject*> objects;
	vector<GLBatch*> batches;
};

#endif