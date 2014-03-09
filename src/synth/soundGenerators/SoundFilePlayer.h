#ifndef _SOUND_FILE_PLAYER
#define _SOUND_FILE_PLAYER

#include "ofMain.h"
#include "SoundGen.h"
#include "AudioConstants.h"

class SoundFilePlayer : public SoundGen {
	private:
		ofSoundPlayer player;

	public:
		void addAudioOut(float * output, int bufferSize, int nChannels);
		void setVolume(float volume);

	SoundFilePlayer(char * path);
};

#endif 
