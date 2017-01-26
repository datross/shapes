#ifndef SEED_SOUND_H
#define SEED_SOUND_H

#include "Seed.h"
#include "SoundListener.h"

#include <memory>

/**
 * @brief Abstract Seed which can respond to the sound.
 * Note : this kind of seed should not update the SoundListener.
 * 
 */
namespace idl {
	class SeedSound : public Seed {
	protected:
		/**
		 * @bried Reference to the only SoundListener of the program */
		SoundListener * soundListener;
	public:
		SeedSound(SoundListener * soundListener);
	};
	
}

#endif