#ifndef _SYNTH 
#define _SYNTH

#include "ofMain.h"

#include "soundGenerators/Chord.h"
#include "soundGenerators/SinOsc.h"
#include "soundGenerators/PinkNoise.h" 
#include "soundGenerators/SoundFilePlayer.h" 

#include "synth/SynthConstants.h"
#include "synth/VolumeMod.h"

class Synth {
	private:
		// sound generators
		Chord * blueChord;
		Chord * yellowChord;
		SinOsc * whiteSine;
		SinOsc * blackSine;
		PinkNoise * greyNoise;
		SoundFilePlayer * redSound;
		SoundFilePlayer * greenSound;

		// volume mods handle fading of sound
		VolumeMod * blueVolumeMod;
	  	VolumeMod * yellowVolumeMod;
	   	VolumeMod * whiteVolumeMod; 
		VolumeMod * blackVolumeMod;
	   	VolumeMod * greyVolumeMod;
	   	VolumeMod * greenVolumeMod;
	   	VolumeMod * redVolumeMod;

	public:
		void addAudioOut(float * output, int bufferSize, int nChannels);
		void mapColourMags(double, double, double, double, double, double, double);
		void fadeOut();
		Synth();
};

#endif
