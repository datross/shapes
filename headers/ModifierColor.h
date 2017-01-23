#ifndef MODIFIER_COLOR_H
#define MODIFIER_COLOR_H

#include "ofMain.h"
#include "DependanteSelectionModifier.h"
#include <SeedConstant.h>


namespace idl {
	
class Colorizer : public DependanteSelectionModifier {
	ofColor color;
public:
	Colorizer(shared_ptr<Selection> selection, ofColor& _color, std::shared_ptr<Seed> seed = std::shared_ptr<Seed>(new SeedConstant()));
	virtual void apply();
};

}

#endif