#include "SeedSoundSpectrum.h"
#include "Utility.h"

#include <iostream>

using namespace idl;
using namespace std;

SeedSoundSpectrum::SeedSoundSpectrum(SoundListener * soundListener, float inf_1, float sup_1, float inf_2, float sup_2, float inf_3, float sup_3)
	: SeedSound(soundListener) {
	bands[0] = ofVec2f(ofClamp(inf_1, 0,1), ofClamp(sup_1, 0,1)); 
	bands[1] = ofVec2f(ofClamp(inf_2, 0,1), ofClamp(sup_2, 0,1));
	bands[2] = ofVec2f(ofClamp(inf_3, 0,1), ofClamp(sup_3, 0,1));
}

ofVec3f SeedSoundSpectrum::getValue() {
	const vector<float> & sp = soundListener->getData().spectrum;
	float nrjs[] = {0, 0, 0};
	for(unsigned i = 0; i < 3; ++i) {
		nrjs[i] = energy(vector<float>(
			sp.begin() + ofClamp(ofLerp(0, sp.size(), bands[i].x), 0, sp.size() - 1),
			sp.begin() + ofClamp(ofLerp(0, sp.size(), bands[i].y), 0, sp.size() - 1)));
	}
	return ofVec3f(nrjs[0], nrjs[1], nrjs[2]);
}