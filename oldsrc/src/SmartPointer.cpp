#include "Core.h"
#include "SmartPointer.h"

PointerBase::ReferenceMap PointerBase::msMap;
Mutex PointerBase::msMutex;