#ifndef MODIFIER_ROTATION_H
#define MODIFIER_ROTATION_H

#include "DependenteModifier.h"
#include "SeedConstant.h"
#include <memory>

namespace idl {
	
class Rotator : public DependenteModifier {
private:
	float angle;
	bool individual_origin;
	ofPoint pivot;
public:
	Rotator(std::shared_ptr<Selection>, 
			float angle, 
			bool individual_origin, 
			ofPoint pivot = ofPoint(0,0), 
			std::shared_ptr<Seed> seed =  std::shared_ptr<Seed>(new SeedConstant()));
	virtual void apply();
};

}

#endif