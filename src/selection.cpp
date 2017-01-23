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

void Selection::byId(std::string id){
	for(world.firstShape(); !world.endShape(); world.nextShape()) {
		if (id == world.currentShape().getId())
			shapes.push_back(ShapeSelected(&world.currentShape(), 1));
	}
}

void Selection::byColor(ofColor color){
	for(world.firstShape(); !world.endShape(); world.nextShape()) {
			if (color == world.currentShape().getColor())
				shapes.push_back(ShapeSelected(&world.currentShape(), 1));
	}
}

void Selection::random(float threshold){
	srand(time(NULL));
	for(world.firstShape(); !world.endShape(); world.nextShape()) {
		float weight = ofRandom(0, 1);
		if (weight >threshold)
				shapes.push_back(ShapeSelected(&world.currentShape(), weight));
		}
}
