#ifndef SHRCONTROLLEDOBJECT_H
#define SHRCONTROLLEDOBJECT_H

#include "ShrGraphicsLIB.h"
#include "ShrController.h"

namespace shr
{

class SHR_GRAPHICS_ITEM ControlledObject : public Object
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(ControlledObject);

protected:
    // Abstract base class.  Construction and destruction.
    ControlledObject ();
public:
    virtual ~ControlledObject ();

    // Access to the controllers that control this object.
    inline int GetNumControllers () const;
    inline Controller* GetController (int i) const;
    void AttachController (Controller* controller);
    void DetachController (Controller* controller);
    void DetachAllControllers ();
    bool UpdateControllers (double applicationTime);

private:
    // The array of controllers that control this object.
    enum { CO_GROW_BY = 4 };
    int mNumControllers, mCapacity;
    ControllerPtr* mControllers;
};

SHR_REGISTER_STREAM(ControlledObject);
typedef Pointer0<ControlledObject> ControlledObjectPtr;
#include "ShrControlledObject.inl"

}

#endif
