#include "BufferIO.h"
#include "Endian.h"
#include "Memory.h"

//----------------------------------------------------------------------------
BufferIO::BufferIO ()
    :
    mBuffer(0),
    mNumBytesTotal(0),
    mNumBytesProcessed(0),
    mMode(BM_NONE)
{
}
//----------------------------------------------------------------------------
BufferIO::BufferIO (int numBytesTotal, char* buffer, int mode)
    :
    mBuffer(0),
    mNumBytesTotal(0),
    mNumBytesProcessed(0),
    mMode(BM_NONE)
{
    Open(numBytesTotal, buffer, mode);
}
//----------------------------------------------------------------------------
BufferIO::~BufferIO ()
{
    if (mMode != BM_NONE)
    {
        Close();
    }
}
//----------------------------------------------------------------------------
bool BufferIO::Open (int numBytesTotal, char* buffer, int mode)
{
    if (mMode == BM_NONE)
    {
        if (buffer && numBytesTotal > 0)
        {
            mBuffer = buffer;
            mNumBytesTotal = numBytesTotal;
            mNumBytesProcessed = 0;
            mMode = mode;
            return true;
        }

        assert(false); /* Failed to open a buffer */
    }
    else
    {
        assert(false); /* Buffer is already open */
    }

    return false;
}
//----------------------------------------------------------------------------
bool BufferIO::Close ()
{
    mBuffer = 0;
    mNumBytesTotal = 0;
    mNumBytesProcessed = 0;
    mMode = BM_NONE;
    return false;
}
//----------------------------------------------------------------------------
bool BufferIO::IncrementNumBytesProcessed (int numBytes)
{
#ifdef BUFFERIO_VALIDATE_OPERATION
    if (numBytes <= 0)
    {
        assert(false); /* Increment must be positive */
        return false;
    }
#endif

    int nextBytesProcessed = mNumBytesProcessed + numBytes;
    if (nextBytesProcessed <= mNumBytesTotal)
    {
        mNumBytesProcessed = nextBytesProcessed;
        return true;
    }

#ifdef BUFFERIO_VALIDATE_OPERATION
    assert(false); /* Increment exceeds buffer size */
#endif

    mNumBytesProcessed = mNumBytesTotal;
    return false;
}
//----------------------------------------------------------------------------
bool BufferIO::Read (size_t itemSize, void* datum)
{
#ifdef BUFFERIO_VALIDATE_OPERATION
    if ((mMode != BM_READ && mMode != BM_READ_AND_SWAP) || !datum
    ||  (itemSize != 1 && itemSize != 2 && itemSize != 4 && itemSize != 8))
    {
        assert(false); /* Invalid BufferIO::Read */
        return false;
    }
#endif

    int nextBytesProcessed = mNumBytesProcessed + (int)itemSize;
    if (nextBytesProcessed <= mNumBytesTotal)
    {
        char* source = mBuffer + mNumBytesProcessed;
        mNumBytesProcessed = nextBytesProcessed;
        memcpy(datum, source, itemSize);
        if (mMode == BM_READ_AND_SWAP && itemSize > 1)
        {
            Endian::Swap(itemSize, datum);
        }
        return true;
    }

#ifdef BUFFERIO_VALIDATE_OPERATION
    assert(false); /* Invalid BufferIO::Read */
#endif

    mNumBytesProcessed = mNumBytesTotal;
    return false;
}
//----------------------------------------------------------------------------
bool BufferIO::Read (size_t itemSize, int numItems, void* data)
{
#ifdef BUFFERIO_VALIDATE_OPERATION
    if ((mMode != BM_READ && mMode != BM_READ_AND_SWAP) || numItems <= 0
    ||  !data
    ||  (itemSize != 1 && itemSize != 2 && itemSize != 4 && itemSize != 8))
    {
        assert(false); /* Invalid BufferIO::Read */
        return false;
    }
#endif

    int numToCopy = ((int)itemSize)*numItems;
    int nextBytesProcessed = mNumBytesProcessed + numToCopy;
    if (nextBytesProcessed <= mNumBytesTotal)
    {
        char* source = mBuffer + mNumBytesProcessed;
        mNumBytesProcessed = nextBytesProcessed;
        memcpy(data, source, (size_t)numToCopy);
        if (mMode == BM_READ_AND_SWAP && itemSize > 1)
        {
            Endian::Swap(itemSize, numItems, data);
        }
        return true;
    }

#ifdef BUFFERIO_VALIDATE_OPERATION
    assert(false); /* Invalid BufferIO::Read */
#endif

    mNumBytesProcessed = mNumBytesTotal;
    return false;
}
//----------------------------------------------------------------------------
bool BufferIO::Write (size_t itemSize, const void* datum)
{
#ifdef BUFFERIO_VALIDATE_OPERATION
    if ((mMode != BM_WRITE && mMode != BM_WRITE_AND_SWAP) || !datum
    ||  (itemSize != 1 && itemSize != 2 && itemSize != 4 && itemSize != 8))
    {
        assert(false); /* Invalid BufferIO::Write */
        return false;
    }
#endif

    int nextBytesProcessed = mNumBytesProcessed + (int)itemSize;
    if (nextBytesProcessed <= mNumBytesTotal)
    {
        char* target = mBuffer + mNumBytesProcessed;
        mNumBytesProcessed = nextBytesProcessed;
        memcpy(target, datum, itemSize);
        if (mMode == BM_WRITE_AND_SWAP && itemSize > 1)
        {
            Endian::Swap(itemSize, target);
        }
        return true;
    }

#ifdef BUFFERIO_VALIDATE_OPERATION
    assert(false); /* Invalid BufferIO::Write */
#endif

    mNumBytesProcessed = mNumBytesTotal;
    return false;
}
//----------------------------------------------------------------------------
bool BufferIO::Write (size_t itemSize, int numItems, const void* data)
{
#ifdef BUFFERIO_VALIDATE_OPERATION
    if ((mMode != BM_WRITE && mMode != BM_WRITE_AND_SWAP) || numItems <= 0
    ||  !data
    ||  (itemSize != 1 && itemSize != 2 && itemSize != 4 && itemSize != 8))
    {
        assert(false); /* Invalid BufferIO::Write */
        return false;
    }
#endif

    int numToCopy = ((int)itemSize)*numItems;
    int nextBytesProcessed = mNumBytesProcessed + numToCopy;
    if (nextBytesProcessed <= mNumBytesTotal)
    {
        char* target = mBuffer + mNumBytesProcessed;
        mNumBytesProcessed = nextBytesProcessed;
        memcpy(target, data, (size_t)numToCopy);
        if (mMode == BM_WRITE_AND_SWAP && itemSize > 1)
        {
            Endian::Swap(itemSize, numItems, target);
        }
        return true;
    }

#ifdef BUFFERIO_VALIDATE_OPERATION
    assert(false); /* Invalid BufferIO::Write */
#endif

    mNumBytesProcessed = mNumBytesTotal;
    return false;
}
//----------------------------------------------------------------------------
