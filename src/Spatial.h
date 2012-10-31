#ifndef SPATIAL_H
#define SPATIAL_H

#include "Object.h"
#include "Transform.h"

class Spatial : public Object
{
public:
	Spatial();
	virtual ~Spatial();

	/ Local and world transforms.  In some situations you might need to set
    // the world transform directly and bypass the Spatial::Update()
    // mechanism.  If World is set directly, the mWorldIsCurrent flag should
    // be set to 'true'.
    Transform LocalTransform;
    Transform WorldTransform;
    bool WorldTransformIsCurrent;

protected:

};

#endif