#ifndef SHRMEMORY_H
#define SHRMEMORY_H

#include "ShrCoreLIB.h"
#include "ShrAssert.h"
#include "ShrMutex.h"

#ifdef SHR_USE_MEMORY
// Wild Magic memory tracking for debugging.

namespace shr
{

class SHR_CORE_ITEM Memory
{
public:
    // Allow users to provide their own allocator and deallocator.
    typedef void* (*Allocator)(size_t numBytes, const char* file, int line);
    typedef void (*Deallocator)(void* memblock, const char* file, int line);

    // The initialization and termination functions are called in 'main'
    // in the file Application.cpp.  To specify your own allocator and
    // deallocator, modify the Memory::Initialize call in 'main'.
    static void Initialize (
        Allocator allocator = &DefaultAllocator,
        Deallocator deallocator = &DefaultDeallocator
    );

    static void Terminate (const std::string& filename);

public_internal:
    inline Memory (const char* file, int line) : mFile(file), mLine(line) {}
    inline ~Memory () {}

    inline static bool HasMap () { return msMap != 0; }
    void* CreateBlock (size_t numBytes, int numDimensions) const;

    // For 1D arrays:  data[bound0]
    template <typename T>
    T* New1 (const size_t bound0);

    // For 2D arrays:  data[bound1][bound0]
    template <typename T>
    T** New2 (const size_t bound0, const size_t bound1);

    // For 3D arrays:  data[bound2][bound1][bound0]
    template <typename T>
    T*** New3 (const size_t bound0, const size_t bound1, const size_t bound2);

    // For 4D arrays:  data[bound3][bound2][bound1][bound0]
    template <typename T>
    T**** New4 (const size_t bound0, const size_t bound1, const size_t bound2,
        const size_t bound3);


    // For singletons.
    template <typename T>
    void Delete0 (T*& data);

    // For 1D arrays:  data[bound0]
    template <typename T>
    void Delete1 (T*& data);

    // For 2D arrays:  data[bound1][bound0]
    template <typename T>
    void Delete2 (T**& data);

    // For 3D arrays:  data[bound2][bound1][bound0]
    template <typename T>
    void Delete3 (T***& data);

    // For 4D arrays:  data[bound3][bound2][bound1][bound0]
    template <typename T>
    void Delete4 (T****& data);

private_internal:
    static void* DefaultAllocator (size_t numBytes, const char* file,
        int line);

    static void DefaultDeallocator (void* memBlock, const char* file,
        int line);

    class Information
    {
    public:
        inline Information () {}

        inline Information (size_t numBytes, int numDimensions,
            const char* file, int line)
            :
            mNumBytes(numBytes),
            mNumDimensions(numDimensions),
            mFile(file),
            mLine(line),
            mUniqueID(++msUniqueID)
        {
        }

        size_t mNumBytes;
        int mNumDimensions;
        const char* mFile;
        int mLine;
        unsigned int mUniqueID;
        static unsigned int msUniqueID;
    };

    typedef std::map<void*,Information> MemoryMap;
    typedef std::map<unsigned int, std::pair<void*,Information> > SortedMap;

    const char* mFile;
    int mLine;

    // The msMutex is used to prevent concurrent access to msMap.  However,
    // the order of declaration and initialization is as shown because the
    // function CreateBlock tests msMap first to warn about pre-main
    // allocations.
    static MemoryMap* msMap;
    static Mutex msMutex;
    static Allocator msAllocator;
    static Deallocator msDeallocator;
};

#include "ShrMemory.inl"

}

//----------------------------------------------------------------------------
inline void* operator new (size_t numBytes, const shr::Memory& memory)
{
    if (memory.HasMap())
    {
        return memory.CreateBlock(numBytes, 0);
    }
    else
    {
#ifdef SHR_USE_MEMORY_ASSERT_ON_PREINIT_POSTTERM_OPERATIONS
        assertion(false, "Allocations are not tracked outside a "
            "Memory::Initialize/Memory::Terminate block.\n");
#endif
        return malloc(numBytes);
    }
}
//----------------------------------------------------------------------------
inline void operator delete (void*, const shr::Memory&)
{
    // Only called during exception handling.
}
//----------------------------------------------------------------------------

#define new0 new(shr::Memory(__FILE__,__LINE__))
#define new1 shr::Memory(__FILE__,__LINE__).New1
#define new2 shr::Memory(__FILE__,__LINE__).New2
#define new3 shr::Memory(__FILE__,__LINE__).New3
#define new4 shr::Memory(__FILE__,__LINE__).New4
#define delete0 shr::Memory(__FILE__,__LINE__).Delete0
#define delete1 shr::Memory(__FILE__,__LINE__).Delete1
#define delete2 shr::Memory(__FILE__,__LINE__).Delete2
#define delete3 shr::Memory(__FILE__,__LINE__).Delete3
#define delete4 shr::Memory(__FILE__,__LINE__).Delete4

#else

// Standard memory management.
#define new0 new

// For 1D arrays:  data[bound0]
template <typename T>
T* new1 (const size_t bound0);

// For 2D arrays:  data[bound1][bound0]
template <typename T>
T** new2 (const size_t bound0, const size_t bound1);

// For 3D arrays:  data[bound2][bound1][bound0]
template <typename T>
T*** new3 (const size_t bound0, const size_t bound1, const size_t bound2);

// For 4D arrays:  data[bound3][bound2][bound1][bound0]
template <typename T>
T**** new4 (const size_t bound0, const size_t bound1, const size_t bound2,
    const size_t bound3);

// For singletons.
template <typename T>
void delete0 (T*& data);

// For 1D arrays:  data[bound0]
template <typename T>
void delete1 (T*& data);

// For 2D arrays:  data[bound1][bound0]
template <typename T>
void delete2 (T**& data);

// For 3D arrays:  data[bound2][bound1][bound0]
template <typename T>
void delete3 (T***& data);

// For 4D arrays:  data[bound3][bound2][bound1][bound0]
template <typename T>
void delete4 (T****& data);

#include "ShrMemory.inl"

#endif
#endif
