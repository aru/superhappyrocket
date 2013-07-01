#include "ShrCorePCH.h"
#include "ShrSmartPointer.h"
using namespace shr;

PointerBase::ReferenceMap PointerBase::msMap;
Mutex PointerBase::msMutex;
