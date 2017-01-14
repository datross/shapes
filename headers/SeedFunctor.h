#ifndef SEED_FUNCTOR_H
#define SEED_FUNCTOR_H

#include <functional>
#include "Seed.h"

namespace idl {
	
class SeedFunctor : public Seed {
private:
	std::function<ofVec3f()> functor;
	virtual ofVec3f getValue();
public:	
	SeedFunctor(std::function<ofVec3f()> functor);
};

}

#endif