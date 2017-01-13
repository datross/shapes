#include "Seed.h"
using namespace idl;

Seed::Seed()
	: valueCurrent(0,0,0), valuePrec(0,0,0) {
}

Seed::~Seed()
{
}

ofVec3f Seed::current() const {
	return valueCurrent;
}

ofVec3f Seed::prec() const {
	return valuePrec;
}

ofVec3f Seed::step() const {
	return valueCurrent - valuePrec;
}

void Seed::update(){
	valuePrec = valueCurrent;
	valueCurrent = getValue();
}