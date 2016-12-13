#include "modifier_rotation.h"

using namespace idl;

Rotator::Rotator(Selection& selection, float _angle, bool _individual_origin, ofPoint _pivot)
	: Modifier(selection), angle(_angle), individual_origin(_individual_origin), pivot(_pivot)
{
}

void Rotator::apply()
{
	if(individual_origin) {
		for(std::vector< ShapeSelected >::iterator it = selection.weights.begin();
			it != selection.weights.end(); ++it) {
			it->first->rotation += it->second * angle;
			}
	} else {
		for(std::vector< ShapeSelected >::iterator it = selection.weights.begin();
			it != selection.weights.end(); ++it) {
			it->first->position.rotate(it->second * angle, ofVec3f(pivot.x, pivot.y, 1));
		}
	}
}

