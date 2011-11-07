#ifndef OBJECT_H
#define OBJECT_H

#include "Core.h"
#include "CoreLIB.h"
#include "GlExtensions.h"

class Object
{
public:

	Object();
	virtual ~Object();

	// Names for objects.
    void SetName (const std::string& name);
    const std::string& GetName () const;
    virtual Object* GetObjectByName (const std::string& name);
	// send a name and a buffer, and we'll get you the objects inside, kinda slow cuz push_back lol
    virtual void GetAllObjectsByName (const std::string& name,
        std::vector<Object*>& objects);

protected:
	std::string mName;
};

#endif