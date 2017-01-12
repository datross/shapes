#ifndef MODIFIER_ROTATION_H
#define MODIFIER_ROTATION_H

#include "ofMain.h"
#include "modifierSelection.h"

namespace idl {
	
struct Rotator : public ModifierSelection {
	float angle;
	bool individual_origin;
	ofPoint pivot;
	Rotator(Selection&, float angle, bool individual_origin, ofPoint pivot = ofPoint(0,0));
	virtual void apply();
};

}

#endif