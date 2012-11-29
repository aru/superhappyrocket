#ifndef SHRVISUAL_H
#define SHRVISUAL_H

#include "ShrGraphicsLIB.h"
#include "ShrSpatial.h"
#include "ShrIndexBuffer.h"
#include "ShrVertexBuffer.h"
#include "ShrVertexFormat.h"
#include "ShrVisualEffectInstance.h"

namespace shr
{

class SHR_GRAPHICS_ITEM Visual : public Spatial
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(Visual);

public:
    enum PrimitiveType
    {
        PT_NONE,  // default constructor
        PT_POLYPOINT,
        PT_POLYSEGMENTS_DISJOINT,
        PT_POLYSEGMENTS_CONTIGUOUS,
        PT_TRIANGLES,  // abstract
        PT_TRIMESH,
        PT_TRISTRIP,
        PT_TRIFAN,
        PT_MAX_QUANTITY
    };

protected:
    // Abstract base class.  Construction and destruction.
    Visual (PrimitiveType type = PT_NONE);
    Visual (PrimitiveType type, VertexFormat* vformat, VertexBuffer* vbuffer,
        IndexBuffer* ibuffer);
public:
    virtual ~Visual ();

    // Member access to geometric data.
    inline PrimitiveType GetPrimitiveType () const;

    inline void SetVertexFormat (VertexFormat* vformat);
    inline const VertexFormat* GetVertexFormat () const;
    inline VertexFormat* GetVertexFormat ();

    inline void SetVertexBuffer (VertexBuffer* vbuffer);
    inline const VertexBuffer* GetVertexBuffer () const;
    inline VertexBuffer* GetVertexBuffer ();

    inline void SetIndexBuffer (IndexBuffer* ibuffer);
    inline const IndexBuffer* GetIndexBuffer () const;
    inline IndexBuffer* GetIndexBuffer ();

    inline const Bound& GetModelBound () const;
    inline Bound& GetModelBound ();

    // Access to the visual effect for drawing the object.
    inline void SetEffectInstance (VisualEffectInstance* effect);
    inline VisualEffectInstance* GetEffectInstance () const;

    // Geometric updates.  If the positions in the vertex buffer have been
    // modified, you might want to update the surface frames (normals,
    // tangents, and bitangents) for indexed-triangle primitives.  It is
    // assumed that the positions have been updated and the vertex buffer is
    // unlocked.  The argument of UpdateModelSpace specifies the update
    // algorithm:
    //
    //   GU_MODEL_BOUND_ONLY:
    //      Update only the model-space bound of the new positions.
    //
    // For the other options, the model-space bound is always recomputed,
    // regardless of type of primitive.  For the surface frames to be updated,
    // the Visual must represent an indexed-triangle primitive and must have
    // the relevant channels (normal, tangents, bitangents).  If the primitive
    // is not indexed triangles, the update call does nothing to the frames.
    // An update occurs only for those channels present in the vertex buffer.
    // For example, if the vertex buffer has no normals, GU_NORMALS will
    // have no effect on the vertex buffer.  As another example, if you
    // specify GU_USE_GEOMETRY and the vertex buffer has normals and tangents
    // but not bitangents, only normals and tangents are updated (i.e. the
    // vertex buffer is not regenerated to have bitangents).
    //
    //   GU_NORMALS:
    //      Update the normals.
    //
    //   GU_USE_GEOMETRY:
    //      Use the mesh topology to determine the surface frames.  The
    //      algorithm uses a least-squares method, which is expensive.
    //
    //   GU_USE_TCOORD_CHANNEL + nonnegative_integer:
    //      The standard way to generate surface frames is to use a texture
    //      coordinate unit from the vertex buffer.
    // 
    // To reduce video memory usage by the vertex buffers, if your vertex
    // shaders use normals, tangents, and bitangents, consider passing in
    // normals and tangents, and then have the shader compute the bitangent as
    //    bitangent = Cross(normal, tangent)

    enum SHR_GRAPHICS_ITEM UpdateType
    {
        GU_MODEL_BOUND_ONLY = -3,
        GU_NORMALS = -2,
        GU_USE_GEOMETRY = -1,
        GU_USE_TCOORD_CHANNEL = 0
    };

    virtual void UpdateModelSpace (UpdateType type);

protected:
    // Support for the geometric update.
    virtual void UpdateWorldBound ();
    virtual void UpdateModelBound ();

    // Support for hierarchical culling.
    virtual void GetVisibleSet (Culler& culler, bool noCull);

protected:
    // Geometric data.
    PrimitiveType mType;
    VertexFormatPtr mVFormat;
    VertexBufferPtr mVBuffer;
    IndexBufferPtr mIBuffer;
    Bound mModelBound;

    // Shader effect used to draw the Visual.
    VisualEffectInstancePtr mEffect;

// Support for the raw load/save of Visual.
public:
    // Load/save a visual from/to a *.wmvf file outside the streaming system.
    // Only the components are loaded, because Visual is an abstract
    // base class for the actual instantiable primitives and cannot be
    // created properly unless we have a Load for each instantiable primitive.
    static void LoadWMVF (const std::string& name, PrimitiveType& type,
        VertexFormat*& vformat, VertexBuffer*& vbuffer, IndexBuffer*& ibuffer,
        int mode = FileIO::FM_DEFAULT_READ);

    void SaveWMVF (const std::string& name,
        int mode = FileIO::FM_DEFAULT_WRITE);

private:
    static VertexFormat* LoadVertexFormat (FileIO& inFile);
    static VertexBuffer* LoadVertexBuffer (FileIO& inFile,
        VertexFormat* vformat);
    static IndexBuffer* LoadIndexBuffer (FileIO& inFile);
    void SaveVertexFormat (FileIO& outFile);
    void SaveVertexBuffer (FileIO& outFile);
    void SaveIndexBuffer (FileIO& outFile);
// End support for raw load/save.
};

SHR_REGISTER_STREAM(Visual);
typedef Pointer0<Visual> VisualPtr;
#include "ShrVisual.inl"

}

#endif
