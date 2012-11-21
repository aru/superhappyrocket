#ifndef SHRSPATIAL_H
#define SHRSPATIAL_H

#include "ShrGraphicsLIB.h"
#include "ShrControlledObject.h"
#include "ShrBound.h"
#include "ShrTransform.h"

namespace shr
{

class Culler;

class SHR_GRAPHICS_ITEM Spatial : public ControlledObject
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(Spatial);

protected:
    // Abstract base class.  Construction and destruction.
    Spatial ();
public:
    virtual ~Spatial ();

    // Local and world transforms.  In some situations you might need to set
    // the world transform directly and bypass the Spatial::Update()
    // mechanism.  If World is set directly, the mWorldIsCurrent flag should
    // be set to 'true'.
    Transform LocalTransform;
    Transform WorldTransform;
    bool WorldTransformIsCurrent;

    // World bound access.  In some situations you might want to set the
    // world bound directly and bypass the Spatial::Update() mechanism.  If
    // mWorldBound is set directly, the mWorldBoundIsCurrent flag should be
    // set to 'true'.
    Bound WorldBound;
    bool WorldBoundIsCurrent;

    // Culling parameters.
    enum SHR_GRAPHICS_ITEM CullingMode
    {
        // Determine visibility state by comparing the world bounding volume
        // to culling planes.
        CULL_DYNAMIC,

        // Force the object to be culled.  If a Node is culled, its entire
        // subtree is culled.
        CULL_ALWAYS,

        // Never cull the object.  If a Node is never culled, its entire
        // subtree is never culled.  To accomplish this, the first time such
        // a Node is encountered, the bNoCull parameter is set to 'true' in
        // the recursive chain GetVisibleSet/OnGetVisibleSet.
        CULL_NEVER
    };

    CullingMode Culling;

    // Update of geometric state and controllers.  The function computes world
    // transformations on the downward pass of the scene graph traversal and
    // world bounding volumes on the upward pass of the traversal.
    void Update (double applicationTime = -Mathd::MAX_REAL,
        bool initiator = true);

    // Access to the parent object.
    inline Spatial* GetParent ();

protected:
    // Support for the geometric update.
    virtual void UpdateWorldData (double applicationTime);
    virtual void UpdateWorldBound () = 0;
    void PropagateBoundToRoot ();

public_internal:
    // Support for hierarchical culling.
    void OnGetVisibleSet (Culler& culler, bool noCull);
    virtual void GetVisibleSet (Culler& culler, bool noCull) = 0;

    // Access to the parent object.  Node calls this during attach/detach of
    // children.
    inline void SetParent (Spatial* parent);

protected:
    // Support for a hierarchical scene graph.  Spatial provides the parent
    // pointer.  Node provides the child pointers.
    Spatial* mParent;
};

SHR_REGISTER_STREAM(Spatial);
typedef Pointer0<Spatial> SpatialPtr;
#include "ShrSpatial.inl"

}

#endif
