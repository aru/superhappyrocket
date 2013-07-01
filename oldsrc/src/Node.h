#ifndef NODE_H
#define NODE_H

#include "Spatial.h"
#include "Object.h"

class Node : public Spatial
{
public:
	// Construction and destruction.
	Node();
	virtual ~Node();

	int GetNumChildren() const;
	int AttachChild( Spatial* child );
	int DetachChild( Spatial* child );

	// Child pointers.
	std::vector<Spatial*> mChild;
};

#endif