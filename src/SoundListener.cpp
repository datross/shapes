#include "SoundListener.h"

using namespace idl;

SoundListener::SoundListener() {			
	/* setup fft object */
	fft = ofxFft::create(BUFFER_SIZE, OF_FFT_WINDOW_HAMMING);
	
	/* allocate array for sound data */
	data.spectrum.resize(fft->getBinSize());
}


SoundListener::~SoundListener() {
}

void SoundListener::setInputBuffer(const ofSoundBuffer* b) {
	soundBuffer = b;
	if(soundBuffer) {
		/* allocate data for left channel */
		analyzeChannel.resize(soundBuffer->size()/2);
	}
}

void SoundListener::updateAnalyzeChannel() {
	for(unsigned an_i = 0, buf_i = 0; an_i < analyzeChannel.size(); ++an_i, buf_i += 2) {
		analyzeChannel[an_i] = soundBuffer->getBuffer()[buf_i];
	}
}

void SoundListener::analyze() {
	if(soundBuffer) {
		updateAnalyzeChannel();
		fft->setSignal(analyzeChannel.data());
		
		/* copy data from fft to soundData */
		memcpy(data.spectrum.data(), fft->getAmplitude(), sizeof(float) * fft->getBinSize());
		
		/* computes RMS amplitude and stores it */
		data.enveloppe = soundBuffer->getRMSAmplitude();
	}
}

const SoundData & SoundListener::getData() const {
	return data;
}