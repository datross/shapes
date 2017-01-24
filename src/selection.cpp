#include "selection.h"
#include "Utility.h"

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

void Selection::byId(string id){
	for(world.firstShape(); !world.endShape(); world.nextShape()) {

		//TODO better
		vector<string> ids = parseIds(world.currentShape().getId());
		for (std::vector<string>::iterator it = ids.begin() ; it != ids.end(); ++it){
			if (id == (*it))
				shapes.push_back(ShapeSelected(&world.currentShape(), 1));
		}

	}
}

void Selection::byColor(string _color){
	ofColor color = parseColor(_color);
	for(world.firstShape(); !world.endShape(); world.nextShape()) {
			if (color == world.currentShape().getColor())
				shapes.push_back(ShapeSelected(&world.currentShape(), 1));
	}
}

void Selection::random(float threshold){
	srand(time(NULL));
	for(world.firstShape(); !world.endShape(); world.nextShape()) {
		float weight = ofRandom(0, 1);
		if (weight > threshold)
				shapes.push_back(ShapeSelected(&world.currentShape(), weight));
	}
}
