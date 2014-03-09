#include "VolumeMod.h"

VolumeMod::VolumeMod(SoundGen * sg, float v) {
	soundGen = sg;
	volume = v;

	status = DOING_NOTHING;
	fadeOutPos = FADE_OUT_TIME;
	fadeInPos = FADE_IN_TIME;
}

void VolumeMod::fadeOut() {
	if(status != FADING_OUT) {
		status = FADING_OUT;
		fadeOutPos = 0;
		fadeInPos = FADE_IN_TIME;
		prevVolume = volume;
	}
}

void VolumeMod::fadeTo(float dv) {
	status = FADING_IN;
	destVolume = dv;
	prevVolume = volume;

	// start fading in
	fadeInPos = 0;
	
	// stop fading out
	fadeOutPos = FADE_OUT_TIME;
}

void VolumeMod::modulateVolume(int bufferSize, int numChannels) {
	// work out how far to step through envelopes
	int timeStep = bufferSize;	

	// if we're fading out
	if(status == FADING_OUT) {
		fadeOutPos += timeStep;	
		if(fadeOutPos >= FADE_OUT_TIME) { status = DOING_NOTHING; }

		volume = (float)MAX(0.0, 1.0 - pow(
				((float)fadeOutPos / (float)FADE_OUT_TIME), 
				FADE_EXPONENT
			)) * prevVolume;

		// update the sound generators volume
		soundGen->setVolume(volume);
	}

	// if we're fading in
	if(status == FADING_IN) {
		fadeInPos += timeStep;	
		if(fadeInPos >= FADE_IN_TIME) { status = DOING_NOTHING; }

		volume = prevVolume + (pow(
				(float)fadeInPos / (float)FADE_IN_TIME, 
				FADE_EXPONENT
			) * (destVolume - prevVolume));

		// update the sound generators volume
		soundGen->setVolume(volume);
	}
}
