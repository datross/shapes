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
	View::getInstance().setVeilColor((ofColor(255) - pourcentVec3ToColor(seed->current())) * colorOrigin + pourcentVec3ToColor(seed->current()) * color);
}

