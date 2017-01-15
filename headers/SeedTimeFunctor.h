#ifndef SEED_FUNCTOR_H
#define SEED_FUNCTOR_H

#include <functional>
#include <vector>
#include "SeedTime.h"

namespace idl {
	
	/**
	 * @brief SeedTime with a std::function, so time can be accessed in the function by calling SeedTime::getStartTime().
	 * 
	 */
	class SeedTimeFunctor : public SeedTime {
	private:
		
		/**
		 * @brief std::function, wich is the callback.
		 */
		std::function<ofVec3f(SeedTime&)> functor;
		
		ofVec3f getValue();
	public:
		SeedTimeFunctor(std::function<ofVec3f(SeedTime&)> functor, std::vector<Setting> settings);
	};

}

#endif