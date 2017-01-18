#include "ModifierRotation.h"
#include "shape.h"

using namespace idl;

Rotator::Rotator(Selection& _selection, float _angle, bool _individual_origin, ofPoint _pivot, std::shared_ptr<Seed> _seed)
	: DependenteModifier(_selection, _seed), angle(_angle), individual_origin(_individual_origin), pivot(_pivot)
{
}

void Rotator::apply() {
	seed->update();
	if(individual_origin) {
		for(std::vector< ShapeSelected >::iterator it = selection.getShapes().begin();
			it != selection.getShapes().end(); ++it) {
			it->first->addRotation(it->second * angle * seed->step().x);
		}
	} else {
		for(std::vector< ShapeSelected >::iterator it = selection.getShapes().begin();
			it != selection.getShapes().end(); ++it) {
			it->first->rotatePosition(it->second * angle * seed->step().x, ofVec3f(pivot.x, pivot.y, 1));
		}
	}
}

