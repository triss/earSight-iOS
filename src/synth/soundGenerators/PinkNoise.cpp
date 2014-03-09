#include "PinkNoise.h"

PinkNoise::PinkNoise(float volume){
    b0 = b1 = b2 = b3 = b4 = b5 = b6 = 0.0;

	setVolume(volume);
}

void PinkNoise::addAudioOut(float * output, int bufferSize, int nChannels) {
	// populate sound buffer
	for(int i = 0; i < bufferSize; i++){
		float white = ofRandomf();	

		b0 = 0.99886 * b0 + white * 0.0555179;
		b1 = 0.99332 * b1 + white * 0.0750759;
		b2 = 0.96900 * b2 + white * 0.1538520;
		b3 = 0.86650 * b3 + white * 0.3104856;
		b4 = 0.55000 * b4 + white * 0.5329522;
		b5 = -0.7616 * b5 - white * 0.0168980;

		float sample = b0 + b1 + b2 + b3 + b4 + b5 + b6 + white * 0.5362;

		// compensate for gain
		sample *= 0.11;

		// add values to output
		output[i * nChannels    ] += sample * volume;
		output[i * nChannels + 1] += sample * volume;

		b6 = white * 0.115926;
	}	
}
