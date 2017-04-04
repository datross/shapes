#ifndef SEED_CONSTANT_H
#define SEED_CONSTANT_H

#include "Seed.h"

namespace idl {
	
class SeedConstant : public Seed {
public:
	SeedConstant(ofVec3f value = ofVec3f(1, 1, 1));
	SeedConstant(float x, float y, float z);
  virtual void reset(){}
private:
	ofVec3f value;
	virtual ofVec3f getValue();
};

}

#endif
