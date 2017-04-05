/*
 * ModifierBezierNoise.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: julie
 */

#include "ModifierBezierNoise.h"
#include "shape.h"
#include "Hud.h"


namespace idl {

Noisator::Noisator(std::shared_ptr<Selection> _selection,
		ofVec2f _movement,
		std::shared_ptr<Seed> _seed) :
		DependanteSelectionModifier(_selection, _seed), movement(_movement) {
	// TODO Auto-generated constructor stub

}
void Noisator::apply(){
	seed->update();
	for(auto it = selection->getShapes().begin(); it != selection->getShapes().end(); ++it) {
			it->shape->bezierNoise(ofVec2f(movement.x*seed->current().x, movement.y*seed->current().y)*it->weight);
	}
}

Noisator::~Noisator() {
	// TODO Auto-generated destructor stub
}

} /* namespace idl */
