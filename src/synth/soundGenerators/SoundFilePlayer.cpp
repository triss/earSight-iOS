#include "SoundFilePlayer.h"

SoundFilePlayer::SoundFilePlayer(char * path) {
	// we're using ofSoundPlayer so not much work to do!
	player.loadSound(path);
	player.setLoop(true);
	player.setVolume(0.0f);
	player.play();
}

void SoundFilePlayer::addAudioOut(float * o, int bs, int nChannels) {
	// do nothing here since ofSoundPlayer's output there own sound
}

void SoundFilePlayer::setVolume(float volume) {
	// just map to wrapped ofSoundPlayer
	player.setVolume(volume);
}
