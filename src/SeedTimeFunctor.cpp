#include "SeedTimeFunctor.h"

using namespace idl;

SeedTimeFunctor::SeedTimeFunctor(std::function< ofVec3f(SeedTime&) > functor, std::vector<Setting> settings) 
	: SeedTime(settings), functor(functor) {
}

ofVec3f SeedTimeFunctor::getValue(){
	return functor(*this);
}

