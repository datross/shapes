#include "ModifierSoundSetter.h"

using namespace idl;
using namespace std;

ModifierSoundSetter::ModifierSoundSetter(shared_ptr<Seed> s, float v, string p) 
	: SoundModifier(s), value(v), parameter(p){
}

ModifierSoundSetter::~ModifierSoundSetter(){
}

void ModifierSoundSetter::apply() {
	seed->update();
	origalValue = OscWrapper::getInstance().getOriginValue(parameter);
	float val = origalValue + value*seed->current().x;
	OscWrapper::getInstance().sendValue(parameter, val);
}
