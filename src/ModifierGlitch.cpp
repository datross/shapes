#include "ModifierGlitch.h"
#include "view.h"

using namespace idl;
using namespace std;

ModifierGlitch::ModifierGlitch(string type,shared_ptr<Seed> seed): PostFxModifier(seed) {
	if(type == "invert") glitchType = OFXPOSTGLITCH_INVERT;
	if(type == "twist") glitchType = OFXPOSTGLITCH_TWIST;
	if(type == "swell") glitchType = OFXPOSTGLITCH_SWELL;
	if(type == "slitscan") glitchType = OFXPOSTGLITCH_SLITSCAN;
	if(type == "noise") glitchType = OFXPOSTGLITCH_NOISE;
	if(type == "outline") glitchType = OFXPOSTGLITCH_OUTLINE;
	if(type == "cutslider") glitchType = OFXPOSTGLITCH_CUTSLIDER;
	if(type == "shaker") glitchType = OFXPOSTGLITCH_SHAKER;
	if(type == "glow") glitchType = OFXPOSTGLITCH_GLOW;
	if(type == "convergence") glitchType = OFXPOSTGLITCH_CONVERGENCE;
}

ModifierGlitch::~ModifierGlitch() {
}

void ModifierGlitch::reset() {
	View::getInstance().getGlitch()->setFx(glitchType, false);
}

void ModifierGlitch::apply() {
	seed->update();
	bool visible = seed->current().x > 0.5 ? true : false;
	View::getInstance().getGlitch()->setFx(glitchType, visible);
}

