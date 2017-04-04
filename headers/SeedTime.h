#ifndef SEED_TIME
#define SEED_TIME

#include "Seed.h"

namespace idl {
	
	typedef float Setting;
	
	/**
	 * @brief Seed wich depends on time, and wich holds settings for its configuration.
	 */
	class SeedTime : public Seed {
	private:
		/**
		 * @brief Time when the seed was started.
		 */
		float startTime;
		
		/**
		 * @brief Stores values used as settings of the seed.
		 */
		std::vector<Setting> settings;
	public:
		/**
		 * @brief Build the seed with the given settings.
		 * 
		 * @param settings
		 */
		SeedTime(std::vector<Setting> settings);
		
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
		
		
		/**
		 * @brief return age of the seed
		 * 
		 * @return float
		 * 
		 */
		float getAge();
		
		/**
		 * @brief Returns the seed settings.
		 * 
		 * @param i Index of the setting.
		 * @return float& A reference to the corresponding setting.
		 */
		Setting& getSetting(unsigned i);
		
		/**
		 * @brief Returns the settings number.
		 * 
		 * @return unsigned int
		 */
		unsigned getSettingsCount();

		virtual void reset() {
			if(getAge()>1)
				start();
		}
	};	
	
}

#endif
