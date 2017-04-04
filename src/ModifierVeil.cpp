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
	View::getInstance().setVeilColor((ofColor(255) - pourcentVec3ToColor(val)) * colorOrigin + pourcentVec3ToColor(val) * color);
}

void idl::ModifierVeil::reset() {
  seed->reset();
}

