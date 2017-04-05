#include "ModifierRotation.h"
#include "shape.h"

#include <iostream>

using namespace std;

using namespace idl;

Rotator::Rotator(std::shared_ptr<Selection> _selection, float _angle, bool _individual_origin, ofPoint _pivot, std::shared_ptr<Seed> _seed)
	: DependanteSelectionModifier(_selection, _seed), angle(_angle), individual_origin(_individual_origin), pivot(_pivot)
{
}

void Rotator::apply() {
	seed->update();
	if(individual_origin) {
		for(std::vector< ShapeSelected >::iterator it = selection->getShapes().begin();
			it != selection->getShapes().end(); ++it) {
			it->shape->addRotationForce(it->weight * angle * seed->current().x);
		}
	} else {
		for(std::vector< ShapeSelected >::iterator it = selection->getShapes().begin();
			it != selection->getShapes().end(); ++it) {
			ofVec2f dir = it->shape->getPosition() - pivot;
			dir.rotate(90);
			it->shape->addForce(it->weight * angle * seed->current().x * dir);
		}
	}
}

