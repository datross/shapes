#ifndef SOUND_MODIFIER_H
#define SOUDN_MODIFIER_H


#include "Modifier.h"
#include "ofxAbletonLive.h"

namespace idl {

	class SoundModifier : public Modifier {
		
		ofxAbletonLive live;

	public:
		SoundModifier();
		~SoundModifier();
		virtual void apply() = 0;
	};

}
#endif // !SOUND_MODIFIER_H
