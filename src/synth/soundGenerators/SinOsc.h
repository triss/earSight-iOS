#ifndef _SIN_OSC
#define _SIN_OSC

#include "ofMain.h"
#include "SoundGen.h"
#include "AudioConstants.h"

class SinOsc : public SoundGen {
	private:
		float phase;
		float phaseAdder;
		float phaseAdderTarget;
	
	public:
		void addAudioOut(float * output, int bufferSize, int nChannels);
		void setFreq(float f);

	SinOsc(float freq, float volume);
};

#endif 
