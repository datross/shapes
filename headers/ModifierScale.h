#ifndef MODIFIER_SCALE_H
#define MODIFIER_SCALE_H

#include "DependanteSelectionModifier.h"
#include "SeedConstant.h"

namespace idl {

class Scalator : public DependanteSelectionModifier {
private:
	ofVec2f scale;
	bool individual_origin;
	ofPoint pivot;
	ofVec2f getMoveScale(Shape & s);	
public:
	Scalator(shared_ptr<Selection>,
			ofVec2f scale,
			bool individual_origin,
			ofPoint pivot = ofPoint(0,0),
			std::shared_ptr<Seed> seed =  std::shared_ptr<Seed>(new SeedConstant()));
	virtual void apply();
};

}

#endif
