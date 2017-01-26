#ifndef MODIFIER_GLITCH_H
#define MODIFIER_GLITCH_H

#include "PostFxModifier.h"
#include "ofxPostGlitch.h"
#include <string>

namespace idl {
	
	class ModifierGlitch : public PostFxModifier {
	private:
		ofxPostGlitchType glitchType;
	public:
		ModifierGlitch(std::string type, std::shared_ptr<Seed> seed);
		~ModifierGlitch();
		virtual void apply();
	};
	
}

#endif
		