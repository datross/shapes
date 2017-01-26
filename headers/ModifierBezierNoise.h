/*
 * ModifierBezierNoise.h
 *
 *  Created on: Jan 25, 2017
 *      Author: julie
 */

#ifndef SRC_MODIFIERBEZIERNOISE_H_
#define SRC_MODIFIERBEZIERNOISE_H_

#include "DependanteSelectionModifier.h"
#include "SeedConstant.h"
#include <memory>

namespace idl {

class Noisator : public DependanteSelectionModifier {
private:
	ofVec2f movement;
public:
	Noisator(std::shared_ptr<Selection>,
			ofVec2f movement,
			std::shared_ptr<Seed> seed =  std::shared_ptr<Seed>(new SeedConstant()));
	virtual void apply();
	virtual ~Noisator();
};

} /* namespace idl */

#endif /* SRC_MODIFIERBEZIERNOISE_H_ */
