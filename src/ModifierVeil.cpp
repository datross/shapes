#include "ModifierVeil.h"
#include "view.h"
#include "Utility.h"

using namespace idl;
using namespace std;

ModifierVeil::ModifierVeil(shared_ptr< Seed > seed, ofColor _color): PostFxModifier(seed), color(_color) {
	colorOrigin = View::getInstance().getVeilColor();
}

void ModifierVeil::apply() {
	seed->update();
	ofVec3f val = seed->current();
	ofColor tmp = pourcentVec3ToColor(val);
	ofColor _1 = ofColor(255,255,255,255) - tmp;
	ofColor _2 = multiplyOfColor(_1, colorOrigin);
	ofColor _3 = multiplyOfColor(tmp, color);
	ofColor c = _2 + _3;
	View::getInstance().setVeilColor(c);
}

void idl::ModifierVeil::reset() {
  seed->reset();
}

