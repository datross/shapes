#ifndef MODIFIER_SOUND_SETTER_H
#define MODIFIER_SOUND_SETTER_H


#include "SoundModifier.h"

namespace idl {
	class ModifierSoundSetter : public SoundModifier {
	public:
		ModifierSoundSetter(shared_ptr<Seed>, OscWrapper &osc);
		~ModifierSoundSetter();
		virtual void apply();
	};
}
#endif MODIFIER_SOUND_SETTER_H