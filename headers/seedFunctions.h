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
		float v = seed.getSetting(0) + seed.getSetting(1) * sin(seed.getSetting(2) * seed.getAge() + seed.getSetting(3));
		return ofVec3f(v);
	}

	/**
	/* @brief if age < 0, then linear interpolation between a and b, else returns b
	 * 0 value beginning, 1 value ending, 2, time between begin and end
	 *
	 * @param seed ...
	 * @return
	 */
	ofVec3f linearFade(SeedTime& seed) {
		if (seed.getAge() < seed.getSetting(2))
		{
			return ofVec3f(seed.getSetting(0) + (seed.getSetting(1) - seed.getSetting(0))*seed.getAge()/seed.getSetting(2));
		}
		else return ofVec3f(seed.getSetting(1));
	}

	/**
	 * @brief Simple wiggle.
	 * 0 amplitude, 1 frequency
	 *
	 * @param seed ...
	 * @return
	 */
	ofVec3f wiggle(SeedTime& seed) {
		return ofVec3f(seed.getSetting(0)*(2*ofNoise(seed.getSetting(1)*seed.getAge())-1),
		seed.getSetting(0)*(2*ofNoise(seed.getSetting(1)*seed.getAge()+10000)-1),
		seed.getSetting(0)*(2*ofNoise(seed.getSetting(1)*seed.getAge()+20000)-1));
	}


}

#endif // SEED_FUNCTIONS_H
