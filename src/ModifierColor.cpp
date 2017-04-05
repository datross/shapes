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
		float w = it->weight;
		Shape *shape = it->shape;
		ofColor seedC = pourcentVec3ToColor(seed->current());
		ofColor c = ((ofColor(255)-seedC)*shape->getOriginColor()) + seedC*((shape->getOriginColor()*(1 - it->weight)) + (color*it->weight));
		shape->setColor(c);
// 		shape->setColor(shape->getOriginColor() * (1 - w) + color * w);
	}
}
