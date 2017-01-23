#ifndef MODIFIER_EXPAND_H
#define MODIFIER_EXPAND_H

#include "DependanteSelectionModifier.h"
#include <memory>

namespace idl {
	
	class ModifierExpand : public DependanteSelectionModifier {
	private:
		ofVec2f a, b;
		float value;
	public:
		ModifierExpand(std::shared_ptr<Selection> _selection, std::shared_ptr<Seed> _seed, ofVec2f a, ofVec2f b, float value);
		virtual void apply();
	};
	
}

#endif