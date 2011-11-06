#ifndef GEOLOADER_H
#define GEOLODAER_H

#include "Core.h"
#include "CoreLIB.h"

class GeoLoader
{
public:
	GeoLoader();
	~GeoLoader();
	/* Function prototypes */
	void LoadFromTxt( char* FILE );

};
#endif