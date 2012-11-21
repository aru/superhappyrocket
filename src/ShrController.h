#ifndef SHRCONTROLLER_H
#define SHRCONTROLLER_H

#include "ShrGraphicsLIB.h"
#include "ShrObject.h"

namespace shr
{

class ControlledObject;

class SHR_GRAPHICS_ITEM Controller : public Object
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(Controller);

protected:
    // Abstract base class.  Construction and destruction.
    Controller ();
public:
    virtual ~Controller ();

    // Member access.
    inline ControlledObject* GetObject () const;
    inline void SetApplicationTime (double applicationTime);
    inline double GetApplicationTime () const;

    // The animation update.  The application time is in milliseconds.
    virtual bool Update (double applicationTime);

    // Time management.  A controller may use its own time scale, and it
    // specifies how times are to be mapped to application time.
    enum SHR_GRAPHICS_ITEM RepeatType
    {
        RT_CLAMP,
        RT_WRAP,
        RT_CYCLE
    };

    // Member access.
    RepeatType Repeat;  // default = RT_CLAMP
    double MinTime;     // default = 0
    double MaxTime;     // default = 0
    double Phase;       // default = 0
    double Frequency;   // default = 1
    bool Active;        // default = true

public_internal:
    // This function is public because the class ControlledObject needs to set
    // the object during a call to AttachController.  Derived classes that
    // manage a set of controllers also need to set the objects during a call
    // to AttachController.
    virtual void SetObject (ControlledObject* object);

protected:
    // Conversion from application time units to controller time units.
    // Derived classes may use this in their update routines.
    double GetControlTime (double applicationTime);

    // The controlled object.  This is a regular pointer rather than a
    // smart pointer to avoid the reference cycle between mObject and
    // 'this'.
    ControlledObject* mObject;

    // The application time in milliseconds.
    double mApplicationTime;
};

SHR_REGISTER_STREAM(Controller);
typedef Pointer0<Controller> ControllerPtr;
#include "ShrController.inl"

}

#endif
