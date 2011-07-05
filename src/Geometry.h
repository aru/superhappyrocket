#ifndef PRIM_H
#define PRIM_H

class Visual
{
public:
	enum PrimitiveType
	{
		GT_NONE, // default constructor
		GT_POLYPOINT,
		GT_POLYLLINE_SEGMENTS,
		GT_POLYLINE_CLOSED,
		GT_TRIMESH,
		GT_MAX_QUANTITY
	};

};

#endif