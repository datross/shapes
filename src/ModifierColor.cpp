#include "ModifierColor.h"
#include "Utility.h"

using namespace idl;

Colorizer::Colorizer(shared_ptr<Selection> selection, ofColor& _color, shared_ptr<Seed> seed)
	: DependanteSelectionModifier(selection, seed), color(_color){
}

void Colorizer::apply(){
	seed->update();
	for(auto it = selection->getShapes().begin();
			it != selection->getShapes().end(); ++it) {
		Shape *shape = it->first;
		ofColor seedC = pourcentVec3ToColor(seed->current());
		ofColor c = ((ofColor(255)-seedC)*shape->getOriginColor()) + (seedC*(shape->getOriginColor()*(1 - it->second)) + (color*it->second));
		shape->setColor(c);
	}
}
