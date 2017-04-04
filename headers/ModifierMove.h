#ifndef MODIFIER_MOVE_H
#define MODIFIER_MOVE_H

#include "DependanteSelectionModifier.h"
#include "SeedConstant.h"
#include <memory>
#include <iostream>

namespace idl {

class Movator : public DependanteSelectionModifier {
private:
	ofVec2f movement;
public:
	Movator(std::shared_ptr<Selection>,
			ofVec2f movement,
			std::shared_ptr<Seed> seed =  std::shared_ptr<Seed>(new SeedConstant()));
	virtual void apply();
};

}

#endif
