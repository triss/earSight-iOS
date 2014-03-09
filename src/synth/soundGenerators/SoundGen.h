#ifndef _SOUND_GEN
#define _SOUND_GEN

class SoundGen {
	protected:
		float volume;

	public:
		virtual void addAudioOut(float *, int, int) {};
		virtual void setVolume(float volume);
};

#endif
