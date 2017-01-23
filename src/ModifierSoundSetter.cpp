#include "ModifierSoundSetter.h"

using namespace idl;

ModifierSoundSetter::ModifierSoundSetter(shared_ptr<Seed> s, OscWrapper &osc, float v, string p) 
	: SoundModifier(s, osc), value(v), parametre(p){

}


ModifierSoundSetter::~ModifierSoundSetter(){

}

void ModifierSoundSetter::apply() {
	seed->update();
	origalValue = osc.getOriginValue(parametre);
	float val = origalValue + value*seed->current().x;
	osc.sendValue(parametre, val);
}
