#ifndef SEED_SOUND_ENVELOPPE
#define SEED_SOUND_ENVELOPPE

#include "SeedSound.h"

namespace idl {
	
	/**
	 * Seed which returns the enveloppe of the sound.
	 */
	class SeedSoundEnvelope : public SeedSound {
	private:
	public:
		SeedSoundEnvelope(SoundListener * soundListener);
		
		virtual ofVec3f getValue();
	};
}

#endif