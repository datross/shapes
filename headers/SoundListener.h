#ifndef SOUNDLISTENER_H
#define SOUNDLISTENER_H

#include "ofxFft.h"

#include <vector>

/* buffer size for the application */
#define IDL_BUFFER_SIZE 256

namespace idl {

/* represents data, spectrum, and enveloppe */
struct SoundData {
	std::vector<float> spectrum;
	float enveloppe;
};

class SoundListener
{
private:
	ofxFft* fft;
	SoundData data;
	
	/* reference to the left sound buffer in ofApp */
	const ofSoundBuffer * soundBuffer;
	
	/* buffer sotring only left channel */
	std::vector<float> analyzeChannel;
	
	/* update leftChannel with data ready to analyze */
	void updateAnalyzeChannel();
public:
	SoundListener();
	~SoundListener();
	void setInputBuffer(const ofSoundBuffer*);

	/* prepare data according to input sound */
	void analyze();
	
	/* returns data computed */
	const SoundData & getData() const;
};

}
#endif //SOUNDLISTENER_H