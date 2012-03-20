#ifndef NODE_H
#define NODE_H

#include "Object.h"

class Node : public Spatial
{
public:
	Node();
	virtual ~Node();

	int GetNumChildren() const;
	int AttachChild( Spatial* child );
	int DetachChild( Spatial* child );

	std::vector<Spatial*> mChild;
};

#endif