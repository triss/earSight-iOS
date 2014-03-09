#ifndef _PINK_NOISE
#define _PINK_NOISE

#include "ofMain.h"
#include "SoundGen.h"

class PinkNoise : public SoundGen {
	private:
    	float b0, b1, b2, b3, b4, b5, b6;

	public:
		void addAudioOut(float *, int, int);

	PinkNoise(float volume);
};

#endif
