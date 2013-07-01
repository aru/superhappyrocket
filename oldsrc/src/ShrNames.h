#ifndef SHRNAMES_H
#define SHRNAMES_H

#include "ShrCoreLIB.h"

//----------------------------------------------------------------------------
#define SHR_DECLARE_NAMES \
public: \
    virtual Object* GetObjectByName (const std::string& name); \
    virtual void GetAllObjectsByName (const std::string& name, \
        std::vector<Object*>& objects)
//----------------------------------------------------------------------------
#define SHR_IMPLEMENT_DEFAULT_NAMES(baseclassname, classname) \
Object* classname::GetObjectByName (const std::string& name) \
{ \
    return baseclassname::GetObjectByName(name); \
} \
\
void classname::GetAllObjectsByName (const std::string& name, \
    std::vector<Object*>& objects) \
{ \
    baseclassname::GetAllObjectsByName(name, objects); \
}
//----------------------------------------------------------------------------
#define SHR_GET_OBJECT_BY_NAME(source, name, found) \
if (source) \
{ \
    found = source->GetObjectByName(name); \
    if (found) \
    { \
        return found; \
    } \
}
//----------------------------------------------------------------------------
#define SHR_GET_ALL_OBJECTS_BY_NAME(source, name, objects) \
if (source) \
{ \
    source->GetAllObjectsByName(name, objects); \
}
//----------------------------------------------------------------------------

#endif
