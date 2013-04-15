#include "ShrGraphicsPCH.h"
#include "ShrCameraNode.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Node, CameraNode);
SHR_IMPLEMENT_STREAM(CameraNode);
SHR_IMPLEMENT_FACTORY(CameraNode);

//----------------------------------------------------------------------------
CameraNode::CameraNode (Camera* camera)
    :
    mCamera(camera)
{
    if (mCamera)
    {
        LocalTransform.SetTranslate(mCamera->GetPosition());

        HMatrix rotate(mCamera->GetDVector(), mCamera->GetUVector(),
            mCamera->GetRVector(), APoint::ORIGIN, true);

        LocalTransform.SetRotate(rotate);
    }
}
//----------------------------------------------------------------------------
CameraNode::~CameraNode ()
{
}
//----------------------------------------------------------------------------
void CameraNode::SetCamera (Camera* camera)
{
    mCamera = camera;

    if (mCamera)
    {
        LocalTransform.SetTranslate(mCamera->GetPosition());

        HMatrix rotate(mCamera->GetDVector(), mCamera->GetUVector(),
            mCamera->GetRVector(), APoint::ORIGIN, true);

        LocalTransform.SetRotate(rotate);

        Update();
    }
}
//----------------------------------------------------------------------------
void CameraNode::UpdateWorldData (double applicationTime)
{
    Node::UpdateWorldData(applicationTime);

    if (mCamera)
    {
        APoint camPosition = WorldTransform.GetTranslate();
        AVector camDVector, camUVector, camRVector;
        WorldTransform.GetRotate().GetColumn(0, camDVector);
        WorldTransform.GetRotate().GetColumn(1, camUVector);
        WorldTransform.GetRotate().GetColumn(2, camRVector);
        mCamera->SetFrame(camPosition, camDVector, camUVector, camRVector);
    }
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Name support.
//----------------------------------------------------------------------------
Object* CameraNode::GetObjectByName (const std::string& name)
{
    Object* found = Node::GetObjectByName(name);
    if (found)
    {
        return found;
    }

    SHR_GET_OBJECT_BY_NAME(mCamera, name, found);
    return 0;
}
//----------------------------------------------------------------------------
void CameraNode::GetAllObjectsByName (const std::string& name,
    std::vector<Object*>& objects)
{
    Node::GetAllObjectsByName(name, objects);

    SHR_GET_ALL_OBJECTS_BY_NAME(mCamera, name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Streaming support.
//----------------------------------------------------------------------------
CameraNode::CameraNode (LoadConstructor value)
    :
    Node(value)
{
}
//----------------------------------------------------------------------------
void CameraNode::Load (InStream& source)
{
    SHR_BEGIN_DEBUG_STREAM_LOAD(source);

    Node::Load(source);

    source.ReadPointer(mCamera);

    SHR_END_DEBUG_STREAM_LOAD(CameraNode, source);
}
//----------------------------------------------------------------------------
void CameraNode::Link (InStream& source)
{
    Node::Link(source);

    source.ResolveLink(mCamera);
}
//----------------------------------------------------------------------------
void CameraNode::PostLink ()
{
    Node::PostLink();
}
//----------------------------------------------------------------------------
bool CameraNode::Register (OutStream& target) const
{
    if (Node::Register(target))
    {
        target.Register(mCamera);
        return true;
    }
    return false;
}
//----------------------------------------------------------------------------
void CameraNode::Save (OutStream& target) const
{
    SHR_BEGIN_DEBUG_STREAM_SAVE(target);

    Node::Save(target);

    target.WritePointer(mCamera);

    SHR_END_DEBUG_STREAM_SAVE(CameraNode, target);
}
//----------------------------------------------------------------------------
int CameraNode::GetStreamingSize () const
{
    int size = Node::GetStreamingSize();
    size += SHR_POINTERSIZE(mCamera);
    return size;
}
//----------------------------------------------------------------------------
