#ifndef OBJECT_H
#define OBJECT_H

#include "CoreLIB.h"

class Object
{
	
// Names for objects.
public:
    void SetName (const std::string& name);
    const std::string& GetName () const;
    virtual Object* GetObjectByName (const std::string& name);
    virtual void GetAllObjectsByName (const std::string& name,
        std::vector<Object*>& objects);

private:
	std::string mName;
};

#endif