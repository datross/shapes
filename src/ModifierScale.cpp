#include "ModifierScale.h"
#include <cmath>

#include <iostream>
using namespace std;

using namespace idl;

Scalator::Scalator(shared_ptr<Selection> _selection, ofVec2f _scale, bool _individual_origin, ofPoint _pivot, std::shared_ptr<Seed> _seed)
	: DependanteSelectionModifier(_selection, _seed), scale(_scale), individual_origin(_individual_origin), pivot(_pivot) {
	if(!_selection)
		cout << "SELECTION VIDE !!" << endl;
}


ofVec2f Scalator::getMoveScale(Shape & s){
	return (s.getPosition() - pivot).normalize();
}

void Scalator::apply() {
	seed->update();
	ofVec2f tmp, move;
	
	if(individual_origin) {
		for(auto it = selection->getShapes().begin(); it != selection->getShapes().end(); ++it) {
			tmp.x = seed->current().x * it->weight * scale.x;
			tmp.y = seed->current().y * it->weight * scale.y;
			it->shape->addScaleForce(tmp);
		}
	} else {
		for(auto it = selection->getShapes().begin(); it != selection->getShapes().end(); ++it) {
			move = getMoveScale(*(it->shape));
			tmp.x = seed->current().x * it->weight * scale.x * move.x;
			tmp.y = seed->current().y * it->weight * scale.y * move.y;
			it->shape->addForce(tmp);
		}
	}
}
