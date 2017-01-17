#include "SeedSoundEnvelope.h"

using namespace idl;

SeedSoundEnvelope::SeedSoundEnvelope(SoundListener& soundListener)
	: SeedSound(soundListener) {

}

ofVec3f SeedSoundEnvelope::getValue() {
	return ofVec3f(soundListener.getData().enveloppe);
}
