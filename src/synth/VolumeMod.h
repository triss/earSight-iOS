#ifndef _VOLUME_MOD 
#define _VOLUME_MOD

#include "ofMain.h"
#include "SoundGen.h"
#include "SynthConstants.h"

#define FADING_IN 0
#define FADING_OUT 1
#define DOING_NOTHING 2

class VolumeMod {
	private:
		float volume;

		float prevVolume;
		float destVolume;

		int fadeInPos;
		int fadeOutPos;

		int status;

		SoundGen * soundGen;

	public:
		void fadeOut();
		void fadeTo(float destVolume);

		void modulateVolume(int bufferSize, int numChannels);

	VolumeMod(SoundGen * soundGen, float maxVolume);
};

#endif
