#include "SeedConstant.h"

using namespace idl;

SeedConstant::SeedConstant(ofVec3f _value) 
	:	Seed(), value(_value) {
}

SeedConstant::SeedConstant(float x, float y, float z)
	: Seed(), value(ofVec3f(x, y, z)) {

}

ofVec3f SeedConstant::getValue() {
	return value;
}

