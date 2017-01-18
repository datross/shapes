#include "selection.h"

using namespace idl;
using namespace std;

Selection::Selection(): world(World::getInstance()) {
	
}

void Selection::uniform(float weight){
	for(world.firstShape(); !world.endShape(); world.nextShape()) {
		shapes.push_back(ShapeSelected(&world.currentShape(), weight));
	}
}

void Selection::radial(float weight, ofPoint point, float radius){
	for(world.firstShape(); !world.endShape(); world.nextShape()) {
		float dist = (point - world.currentShape().getPosition()).length();
		float w;
		if(dist > radius) {
			w = 0;
		} else {
			w = (1 - dist / radius) * weight;
		}
		shapes.push_back(ShapeSelected(&world.currentShape(), w));
	}
}
