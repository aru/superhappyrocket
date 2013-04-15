#ifndef SHRCAMERANODE_H
#define SHRCAMERANODE_H

#include "ShrGraphicsLIB.h"
#include "ShrCamera.h"
#include "ShrNode.h"

namespace shr
{

class SHR_GRAPHICS_ITEM CameraNode : public Node
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(CameraNode);

public:
    // Construction and destruction.  The node's world translation is used
    // as the camera's location.  The node's world rotation matrix is used
    // for the camera's coordinate axes.  Column 0 of the world rotation
    // matrix is the camera's direction vector, column 1 of the world rotation
    // matrix is the camera's up vector, and column 2 of the world rotation
    // matrix is the camera's right vector.
    //
    // On construction, the node's local transformation is set to the
    // camera's current coordinate system.
    //   local translation       = camera location
    //   local rotation column 0 = camera direction
    //   local rotation column 1 = camera up
    //   local rotation column 2 = camera right
    CameraNode (Camera* camera = 0);
    virtual ~CameraNode ();

    // When you set the camera, the node's local transformation is set to the
    // camera's current current coordinate system.  The node's world
    // transformation is computed, and the camera's coordinate system is set
    // to use the node's world transformation.
    void SetCamera (Camera* camera);

    Camera* GetCamera ();
    const Camera* GetCamera () const;

protected:
    // Geometric updates.
    virtual void UpdateWorldData (double applicationTime);

    CameraPtr mCamera;
};

SHR_REGISTER_STREAM(CameraNode);
typedef Pointer0<CameraNode> CameraNodePtr;
#include "ShrCameraNode.inl"

}

#endif
