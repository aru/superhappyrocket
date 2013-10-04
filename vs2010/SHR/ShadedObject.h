#ifndef SHADED_OBJECT
#define SHADED_OBJECT

#include "SimpleObject.h"

class ShadedObject : public SimpleObject
{
public:
	ShadedObject();
	~ShadedObject();
	virtual int Draw2();
	GLint myTexturedIdentityShader;
};

#endif