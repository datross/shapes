#include "SeedConstant.h"

using namespace idl;

SeedConstant::SeedConstant(ofVec3f _value) 
	:	Seed(), value(_value) {
}

ofVec3f SeedConstant::getValue() {
	return value;
}

