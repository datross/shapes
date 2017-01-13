#include "SeedFunctor.h"

using namespace idl;

SeedFunctor::SeedFunctor(std::function<ofVec3f()> _functor) 
	: functor(_functor) {
}

ofVec3f SeedFunctor::getValue()
{
	return functor();
}

