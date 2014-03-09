#include "Synth.h"

// set up our new synthesizer
Synth::Synth() {
	float blueFreqs[3] = BLUE_FREQS; 
	blueChord = new Chord(blueFreqs, 0.0f);	
	blueVolumeMod = new VolumeMod(blueChord, 0.0f);

	float yellowFreqs[3] = YELLOW_FREQS;
	yellowChord = new Chord(yellowFreqs, 0.0f);
	yellowVolumeMod = new VolumeMod(yellowChord, 0.0f);

	whiteSine = new SinOsc(WHITE_FREQ, 0.0f);
	whiteVolumeMod = new VolumeMod(whiteSine, 0.0f);
	blackSine = new SinOsc(BLACK_FREQ, 0.0f);
	blackVolumeMod = new VolumeMod(blackSine, 0.0f);

	greyNoise = new PinkNoise(0.0f);
	greyVolumeMod = new VolumeMod(greyNoise, 0.0f);

	greenSound = new SoundFilePlayer("sounds/i.wav");
	greenVolumeMod = new VolumeMod(greenSound, 0.0f);
	redSound = new SoundFilePlayer("sounds/u.wav");
	redVolumeMod = new VolumeMod(redSound, 0.0f);
}

// called each time we need audio output
void Synth::addAudioOut(float * output, int bufferSize, int nChannels) {
	// apply volume envelopes
	blueVolumeMod->modulateVolume(bufferSize, nChannels);
	yellowVolumeMod->modulateVolume(bufferSize, nChannels);
	whiteVolumeMod->modulateVolume(bufferSize, nChannels);
	blackVolumeMod->modulateVolume(bufferSize, nChannels);
	greyVolumeMod->modulateVolume(bufferSize, nChannels);
	greenVolumeMod->modulateVolume(bufferSize, nChannels);
	redVolumeMod->modulateVolume(bufferSize, nChannels);

	// output sounds
	blueChord->addAudioOut(output, bufferSize, nChannels);
	yellowChord->addAudioOut(output, bufferSize, nChannels);
	whiteSine->addAudioOut(output, bufferSize, nChannels);
	blackSine->addAudioOut(output, bufferSize, nChannels);
	greyNoise->addAudioOut(output, bufferSize, nChannels);
	// no need to do this for red/green

	// reduce overall volume levels
	//for(int i = 0; i < bufferSize * nChannels; i++) {
	//	output[i] *= SYNTH_AMP;
	//}
}

// update sound volumes based on colour magnitudes
void Synth::mapColourMags(
	double white, double black, double grey,
   	double green, double red, 
	double blue, double yellow
) {
	whiteVolumeMod->fadeTo(white * WHITE_AMP);
	blackVolumeMod->fadeTo(black * BLACK_AMP);
	greyVolumeMod->fadeTo(grey * GREY_AMP);
	blueVolumeMod->fadeTo(blue * BLUE_AMP);
	yellowVolumeMod->fadeTo(yellow * YELLOW_AMP);
	greenVolumeMod->fadeTo(green * GREEN_AMP);
	redVolumeMod->fadeTo(red * RED_AMP);
}

// fade the synth out - for when finger removed from screen etc.
void Synth::fadeOut() {
	whiteVolumeMod->fadeOut();
	blackVolumeMod->fadeOut();
	greyVolumeMod->fadeOut();
	blueVolumeMod->fadeOut();
	yellowVolumeMod->fadeOut();
	greenVolumeMod->fadeOut();
	redVolumeMod->fadeOut();
}
