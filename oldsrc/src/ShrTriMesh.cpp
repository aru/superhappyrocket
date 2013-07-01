#include "ShrGraphicsPCH.h"
#include "ShrTriMesh.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Triangles, TriMesh);
SHR_IMPLEMENT_STREAM(TriMesh);
SHR_IMPLEMENT_FACTORY(TriMesh);
SHR_IMPLEMENT_DEFAULT_NAMES(Triangles, TriMesh);
SHR_IMPLEMENT_DEFAULT_STREAM(Triangles, TriMesh);

//----------------------------------------------------------------------------
TriMesh::TriMesh ()
    :
    Triangles(PT_TRIMESH)
{
}
//----------------------------------------------------------------------------
TriMesh::TriMesh (VertexFormat* vformat, VertexBuffer* vbuffer,
    IndexBuffer* ibuffer)
    :
    Triangles(PT_TRIMESH, vformat, vbuffer, ibuffer)
{
}
//----------------------------------------------------------------------------
TriMesh::~TriMesh ()
{
}
//----------------------------------------------------------------------------
int TriMesh::GetNumTriangles () const
{
    return mIBuffer->GetNumElements()/3;
}
//----------------------------------------------------------------------------
bool TriMesh::GetTriangle (int i, int& v0, int& v1, int& v2) const
{
    if (0 <= i && i < GetNumTriangles())
    {
        int* indices = 3*i + (int*)mIBuffer->GetData();
        v0 = *indices++;
        v1 = *indices++;
        v2 = *indices;
        return true;
    }
    return false;
}
//----------------------------------------------------------------------------
