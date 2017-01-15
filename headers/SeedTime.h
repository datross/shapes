#ifndef SEED_TIME
#define SEED_TIME

#include "Seed.h"

namespace idl {
	
	/**
	 * @brief Seed wich depends on time.
	 */
	class SeedTime : public Seed {
	private:
		/**
		 * @brief Time when the seed was started.
		 */
		float startTime;
	public:
		SeedTime();
		
		/**
		 * @brief Makes the seed start from now. This function is called from SeedTime() .
		 * 
		 * @return void
		 */
		void start();
		
		/**
		 * @brief Returns startTime.
		 *  
		 * @return float
		 */
		float getStartTime();
	};
	
}

#endif