#ifndef MODIFIER_SOUND_SETTER_H
#define MODIFIER_SOUND_SETTER_H


#include "SoundModifier.h"

namespace idl {
	class ModifierSoundSetter : public SoundModifier {
		float value, origalValue;
		string parameter;

	public:
		ModifierSoundSetter(shared_ptr<Seed>, float v, string p);
		~ModifierSoundSetter();
		virtual void apply();
	};
}

#endif // MODIFIER_SOUND_SETTER_H