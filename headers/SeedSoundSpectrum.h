#ifndef SEED_SOUND_SPECTRUM
#define SEED_SOUND_SPECTRUM

#include "SeedSound.h"

namespace idl {
	
	/**
	 * Seed which returns norm of the spectrum on 3 intervals.
	 */
	class SeedSoundSpectrum: public SeedSound {
	private:
		ofVec2f bands[3];
	public:
		
		/** @brief Constructor.
		 * 
		 * @param inf_n Inferior bound of band n.
		 * @param sup_n Superior bound of band n.
		 */
		SeedSoundSpectrum(SoundListener& soundListener, 
						  float inf_1 = 0, float sup_1 = 100, 
						  float inf_2 = 0, float sup_2 = 100, 
						  float inf_3 = 0, float sup_3 = 100);
		
		virtual ofVec3f getValue();
	};
	
}

#endif