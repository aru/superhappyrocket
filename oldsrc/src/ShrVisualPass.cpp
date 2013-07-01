#include "ShrGraphicsPCH.h"
#include "ShrVisualPass.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Object, VisualPass);
SHR_IMPLEMENT_STREAM(VisualPass);
SHR_IMPLEMENT_FACTORY(VisualPass);

//----------------------------------------------------------------------------
VisualPass::VisualPass ()
{
}
//----------------------------------------------------------------------------
VisualPass::~VisualPass ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Name support.
//----------------------------------------------------------------------------
Object* VisualPass::GetObjectByName (const std::string& name)
{
    Object* found = Object::GetObjectByName(name);
    if (found)
    {
        return found;
    }

    SHR_GET_OBJECT_BY_NAME(mVShader, name, found);
    SHR_GET_OBJECT_BY_NAME(mPShader, name, found);
    SHR_GET_OBJECT_BY_NAME(mAlphaState, name, found);
    SHR_GET_OBJECT_BY_NAME(mCullState, name, found);
    SHR_GET_OBJECT_BY_NAME(mDepthState, name, found);
    SHR_GET_OBJECT_BY_NAME(mOffsetState, name, found);
    SHR_GET_OBJECT_BY_NAME(mStencilState, name, found);
    SHR_GET_OBJECT_BY_NAME(mWireState, name, found);

    return 0;
}
//----------------------------------------------------------------------------
void VisualPass::GetAllObjectsByName (const std::string& name,
    std::vector<Object*>& objects)
{
    Object::GetAllObjectsByName(name, objects);

    SHR_GET_ALL_OBJECTS_BY_NAME(mVShader, name, objects);
    SHR_GET_ALL_OBJECTS_BY_NAME(mPShader, name, objects);
    SHR_GET_ALL_OBJECTS_BY_NAME(mAlphaState, name, objects);
    SHR_GET_ALL_OBJECTS_BY_NAME(mCullState, name, objects);
    SHR_GET_ALL_OBJECTS_BY_NAME(mDepthState, name, objects);
    SHR_GET_ALL_OBJECTS_BY_NAME(mOffsetState, name, objects);
    SHR_GET_ALL_OBJECTS_BY_NAME(mStencilState, name, objects);
    SHR_GET_ALL_OBJECTS_BY_NAME(mWireState, name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Streaming support.
//----------------------------------------------------------------------------
VisualPass::VisualPass (LoadConstructor value)
    :
    Object(value)
{
}
//----------------------------------------------------------------------------
void VisualPass::Load (InStream& source)
{
    SHR_BEGIN_DEBUG_STREAM_LOAD(source);

    Object::Load(source);

    source.ReadPointer(mVShader);
    source.ReadPointer(mPShader);
    source.ReadPointer(mAlphaState);
    source.ReadPointer(mCullState);
    source.ReadPointer(mDepthState);
    source.ReadPointer(mOffsetState);
    source.ReadPointer(mStencilState);
    source.ReadPointer(mWireState);

    SHR_END_DEBUG_STREAM_LOAD(VisualPass, source);
}
//----------------------------------------------------------------------------
void VisualPass::Link (InStream& source)
{
    Object::Link(source);

    source.ResolveLink(mVShader);
    source.ResolveLink(mPShader);
    source.ResolveLink(mAlphaState);
    source.ResolveLink(mCullState);
    source.ResolveLink(mDepthState);
    source.ResolveLink(mOffsetState);
    source.ResolveLink(mStencilState);
    source.ResolveLink(mWireState);
}
//----------------------------------------------------------------------------
void VisualPass::PostLink ()
{
    Object::PostLink();
}
//----------------------------------------------------------------------------
bool VisualPass::Register (OutStream& target) const
{
    if (Object::Register(target))
    {
        target.Register(mVShader);
        target.Register(mPShader);
        target.Register(mAlphaState);
        target.Register(mCullState);
        target.Register(mDepthState);
        target.Register(mOffsetState);
        target.Register(mStencilState);
        target.Register(mWireState);
        return true;
    }
    return false;
}
//----------------------------------------------------------------------------
void VisualPass::Save (OutStream& target) const
{
    SHR_BEGIN_DEBUG_STREAM_SAVE(target);

    Object::Save(target);

    target.WritePointer(mVShader);
    target.WritePointer(mPShader);
    target.WritePointer(mAlphaState);
    target.WritePointer(mCullState);
    target.WritePointer(mDepthState);
    target.WritePointer(mOffsetState);
    target.WritePointer(mStencilState);
    target.WritePointer(mWireState);

    SHR_END_DEBUG_STREAM_SAVE(VisualPass, target);
}
//----------------------------------------------------------------------------
int VisualPass::GetStreamingSize () const
{
    int size = Object::GetStreamingSize();
    size += SHR_POINTERSIZE(mVShader);
    size += SHR_POINTERSIZE(mPShader);
    size += SHR_POINTERSIZE(mAlphaState);
    size += SHR_POINTERSIZE(mCullState);
    size += SHR_POINTERSIZE(mDepthState);
    size += SHR_POINTERSIZE(mOffsetState);
    size += SHR_POINTERSIZE(mStencilState);
    size += SHR_POINTERSIZE(mWireState);
    return size;
}
//----------------------------------------------------------------------------
