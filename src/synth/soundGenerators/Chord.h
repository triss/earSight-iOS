#ifndef _CHORD
#define _CHORD

#include "SoundGen.h"
#include "SinOsc.h"

class Chord : public SoundGen {
	private:
		vector < SinOsc * > oscs;

	public:
		void addAudioOut(float * output, int bufferSize, int nChannels);
		void setVolume(float volume);

	Chord(float freqs[3], float volume);
};

#endif
