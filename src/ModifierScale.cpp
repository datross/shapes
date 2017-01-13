#include "ModifierScale.h"
#include <cmath>

#include <iostream>
using namespace std;

using namespace idl;

Scalator::Scalator(Selection& _selection, ofVec2f _scale, bool _individual_origin, ofPoint _pivot, std::shared_ptr<Seed> _seed)
	: DependenteModifier(_selection, _seed), scale(_scale), individual_origin(_individual_origin), pivot(_pivot) {
}


ofVec2f Scalator::getMoveScale(Shape & s){
	return (s.getPosition() - pivot).normalize();
}

void Scalator::apply() {
	seed->update();
	ofVec2f tmp, move;
	
	if(individual_origin) {
		for(auto it = selection.weights.begin(); it != selection.weights.end(); ++it) {
			tmp.x = seed->step().x * it->second * scale.x;
			tmp.y = seed->step().y * it->second * scale.y;
			it->first->addScale(tmp);
		}
	} else {
		for(auto it = selection.weights.begin(); it != selection.weights.end(); ++it) {
			move = getMoveScale(*(it->first));
			tmp.x = seed->step().x * it->second * scale.x * move.x;
			tmp.y = seed->step().y * it->second * scale.y * move.y;
			it->first->addSpeed(tmp);
		}
	}
}