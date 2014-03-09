#ifndef _SYNTH_CONSTANTS
#define _SYNTH_CONSTANTS

// single notes for white and black
#define WHITE_FREQ 		3520.0f
#define BLACK_FREQ		100.0f

// frequencies making up chords for blue and yellow 
#define BLUE_FREQS 		{ 262.0f, 311.0f, 392.0f } 		// c minor 
#define YELLOW_FREQS 	{ 1047.0f, 1319.0f, 1568.0f } 	// c major 

// fade times specified in samples (44100 per second)
#define FADE_IN_TIME 	2205 	// twentieth of a second
#define FADE_OUT_TIME 	22050 	// half a second
#define FADE_EXPONENT 	4 		// curve for fades

// maximum amplitudes for each sound
#define WHITE_AMP 	0.1f
#define BLACK_AMP 	1.0f
#define BLUE_AMP 	0.5f
#define YELLOW_AMP 	0.2f
#define RED_AMP 	1.0f
#define GREEN_AMP 	1.0f
#define GREY_AMP 	0.1f

#define SYNTH_AMP 	0.5f

#endif
