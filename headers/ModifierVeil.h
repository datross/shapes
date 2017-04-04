#ifndef MODIFIER_VEIL_H
#define MODIFIER_VEIL_H

#include "PostFxModifier.h"
#include "ofMain.h"

namespace idl {
	
	class ModifierVeil : public PostFxModifier {
	private:
		ofColor color, colorOrigin;
	public:
		ModifierVeil(std::shared_ptr< Seed > seed, ofColor color);
		virtual void apply();
    virtual void reset();
	
  };

}

#endif
