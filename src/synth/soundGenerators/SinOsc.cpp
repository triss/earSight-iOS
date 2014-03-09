#include "SinOsc.h"

SinOsc::SinOsc(float freq, float volume) {
	phase 				= 0.0f;
	setFreq(freq);
	setVolume(volume);
}

void SinOsc::setFreq(float f) {
	phaseAdder = (f / (float) SAMPLE_RATE) * TWO_PI;
}

void SinOsc::addAudioOut(float * output, int bufferSize, int nChannels) {
	// sin (n) seems to have trouble when n is very large, so we
	// keep phase in the range of 0-TWO_PI like this:
	while (phase > TWO_PI){
		phase -= TWO_PI;
	}

	// populate sound buffer
	for (int i = 0; i < bufferSize; i++){
		// step along sine wave
		phase += phaseAdder;
		float sample = sin(phase);

		// add values to output
		output[i * nChannels    ] += sample * volume;
		output[i * nChannels + 1] += sample * volume;
	}
}
