#include "SeedSoundEnvelope.h"

using namespace idl;

SeedSoundEnvelope::SeedSoundEnvelope(SoundListener * soundListener)
	: SeedSound(soundListener) {

}

ofVec3f SeedSoundEnvelope::getValue() {
	ofVec3f vec(soundListener->getData().enveloppe);
	return vec;
}
