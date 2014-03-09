#include "RGBtoColourMags.h" 
#include <math.h>

void rgbToColourMags(
	double * white, double * black, double * grey,
	double * green, double * red, 
	double * blue, double * yellow,
	int r, int g, int b
) {
	// get CIELUV values from rgb
	double l, u, v;
	Rgb2Luv(&l, &u, &v, (double)r/255.0, (double)g/255.0, (double)b/255.0);

	// calculate CIE chroma
	double cieChroma = sqrt((u * u) + (v * v));

	// calculate colour magnitudes
	*white = pow(l, 4) / 100000000.0;
	*black = pow(l - 100, 4) / 100000000.0;

	*red = MIN(u / 100, 1);
	*green = MAX(0, MIN(u * -1.0 / 80, 1));

	*blue = MIN((v * -1.0) / 15, 1);
	*yellow = MIN(v / 100, 1);

	*grey = pow((l * (l - 100.0) / 1000.0) / 2.5, 4)
		* pow((180 - cieChroma) / 180, 4);

	// cutoff magnitudes at specific values
	if(*white < WHITE_CUTOFF) { *white = 0.0; }
	if(*black < BLACK_CUTOFF) { *black = 0.0; }
	if(*red < RED_CUTOFF) { *red = 0.0; }
	if(*green < GREEN_CUTOFF) { *green = 0.0; }
	if(*blue < BLUE_CUTOFF) { *blue = 0.0; }
	if(*yellow < YELLOW_CUTOFF) { *yellow = 0.0; }
	if(*grey < YELLOW_CUTOFF) { *grey = 0.0; }
}
