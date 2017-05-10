#include "ModifierMove.h"
#include "shape.h"
#include "Hud.h"

#include <iostream>

using namespace std;

using namespace idl;

Movator::Movator(std::shared_ptr<Selection> _selection, ofVec2f _movement, std::shared_ptr<Seed> _seed)
	: DependanteSelectionModifier(_selection, _seed), movement(_movement)
{
}

void Movator::apply() {
	seed->update();

	for(auto it = selection->getShapes().begin(); it != selection->getShapes().end(); ++it) {
		it->shape->addForce(ofVec2f(movement.x*seed->current().x, movement.y*seed->current().y)*it->weight);
	}
}

