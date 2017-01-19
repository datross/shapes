#ifndef SEED_FUNCTIONS_H
#define SEED_FUNCTIONS_H

#include <cmath>
#include "ofMain.h"

#include "SeedTime.h"

/**
 * @file seedFunctions.h
 * Contains most of the functions used to build the seed.
 */

namespace idl {


	/**
	 * @brief Classic sinusoide : A*sin(w*t+p)
	 * 
	 * @param seed
	 * @return ofVec3f
	 */
	ofVec3f sinusoide(SeedTime& seed) {
	float v = seed.getSetting(0) * sin(seed.getSetting(1) * seed.getAge() + seed.getSetting(2));
	return ofVec3f(v);
}

}

#endif // SEED_FUNCTIONS_H
