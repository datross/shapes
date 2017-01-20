#include "ModifierScale.h"
#include <cmath>

#include <iostream>
using namespace std;

using namespace idl;

Scalator::Scalator(shared_ptr<Selection> _selection, ofVec2f _scale, bool _individual_origin, ofPoint _pivot, std::shared_ptr<Seed> _seed)
	: DependanteSelectionModifier(_selection, _seed), scale(_scale), individual_origin(_individual_origin), pivot(_pivot) {
}


ofVec2f Scalator::getMoveScale(Shape & s){
	return (s.getPosition() - pivot).normalize();
}

void Scalator::apply() {
	seed->update();
	ofVec2f tmp, move;
	
	if(individual_origin) {
		for(auto it = selection->getShapes().begin(); it != selection->getShapes().end(); ++it) {
			tmp.x = seed->current().x * it->second * scale.x;
			tmp.y = seed->current().y * it->second * scale.y;
			it->first->addScale(tmp);
		}
	} else {
		for(auto it = selection->getShapes().begin(); it != selection->getShapes().end(); ++it) {
			move = getMoveScale(*(it->first));
			tmp.x = seed->current().x * it->second * scale.x * move.x;
			tmp.y = seed->current().y * it->second * scale.y * move.y;
			it->first->addSpeed(tmp);
		}
	}
}