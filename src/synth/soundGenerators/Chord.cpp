#include "Chord.h"

Chord::Chord(float freqs[3], float volume) {
	for(int f = 0; f < 3; f++) {
		oscs.push_back(new SinOsc(freqs[f], volume));	
	}
}

void Chord::addAudioOut(float * output, int bufferSize, int nChannels) {
	for(int i = 0; i < 3; i++) {
		oscs[i]->addAudioOut(output, bufferSize, nChannels);
	}
}

void Chord::setVolume(float volume) {
	for(int i = 0; i < 3; i++) {
		oscs[i]->setVolume(volume);
	}
}
