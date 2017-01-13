#ifndef MODIFIER_SCALE_H
#define MODIFIER_SCALE_H

#include "DependenteModifier.h"
#include "SeedConstant.h"

namespace idl {

class Scalator : public DependenteModifier {
private:
	ofVec2f scale;
	bool individual_origin;
	ofPoint pivot;
	
	ofVec2f getMoveScale(Shape & s);
	
public:
	Scalator(Selection&, ofVec2f scale, bool individual_origin, ofPoint pivot = ofPoint(0,0), std::shared_ptr<Seed> seed =  std::shared_ptr<Seed>(new SeedConstant()));
	virtual void apply();
};
	
}

#endif