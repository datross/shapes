#include "ModifierExpand.h"
#include "Hud.h"

#include <iostream>

using namespace idl;
using namespace std;

ModifierExpand::ModifierExpand(std::shared_ptr<Selection> _selection, std::shared_ptr<Seed> _seed, ofVec2f _a, ofVec2f _b, float _value)
	: DependanteSelectionModifier(_selection, _seed), a(_a), b(_b), value(_value) {
}

void ModifierExpand::apply() {
	seed->update();
	ofVec2f normal = (b - a).rotate(90).normalize();
	ofVec2f dir;
	for(auto it = selection->getShapes().begin(); it != selection->getShapes().end(); ++it) {
		dir = normal;
		/* flip direction if it's the wrong one */
		if(dir.dot(it->shape->getPosition() - a) < -1)
			dir = -normal;
		it->shape->addForce(it->weight * seed->current() * dir * value);
		Hud::getInstance().addEntry("Expand direction", dir);
	}
}
