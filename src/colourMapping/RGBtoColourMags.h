#ifndef _RGB_TO_COLOUR_MAGS
#define _RGB_TO_COLOUR_MAGS

#include "colorspace.h"
#include "ColourMappingConstants.h"

// define min and max macros
#ifndef MIN
	#define MIN(x,y) (((x) < (y)) ? (x) : (y))
#endif

#ifndef MAX
	#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#endif

void rgbToColourMags(
		double * white, double * black, double * grey,
		double * green, double * red, double * blue, double * yellow,
		int r, int g, int b
); 

#endif
