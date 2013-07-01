#include "Object.h"

//----------------------------------------------------------------------------
Object::Object ()
{
	// empty lol
}
//----------------------------------------------------------------------------
Object::~Object ()
{
	// huh
}
//----------------------------------------------------------------------------
// Names.
//----------------------------------------------------------------------------
void Object::SetName (const std::string& name)
{
    mName = name;
}
//----------------------------------------------------------------------------
const std::string& Object::GetName () const
{
    return mName;
}
//----------------------------------------------------------------------------
Object* Object::GetObjectByName (const std::string& name)
{
    return (name == mName ? this : 0);
}
//----------------------------------------------------------------------------
void Object::GetAllObjectsByName (const std::string& name,
    std::vector<Object*>& objects)
{
    if (name == mName)
    {
        objects.push_back(this);
    }
}