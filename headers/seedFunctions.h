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

	// 0 value beginning, 1 valeur ending, 2, time between begin and end
	ofVec3f linearFade(SeedTime& seed) {
		if (seed.getAge() < seed.getSetting(2))
		{
			return ofVec3f(seed.getSetting(0) + (seed.getSetting(1) - seed.getSetting(0))*seed.getAge()/seed.getSetting(2));
		}
		else return ofVec3f(seed.getSetting(1));
	}

	ofVec3f wiggle(SeedTime& seed) {
		return ofVec3f(seed.getSetting(0)*(2*ofNoise(seed.getSetting(1)*seed.getAge())-1),
									 seed.getSetting(0)*(2*ofNoise(seed.getSetting(1)*seed.getAge()+10000)-1),
									 seed.getSetting(0)*(2*ofNoise(seed.getSetting(1)*seed.getAge()+20000)-1));
	}


}

#endif // SEED_FUNCTIONS_H
