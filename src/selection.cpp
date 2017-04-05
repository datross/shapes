#include "selection.h"
#include "Utility.h"

using namespace idl;
using namespace std;

Selection::Selection() : world(World::getInstance()) {

}

void Selection::add(ShapeSelected s){
  shapes.push_back(s);
}

idl::SelectionUniform::SelectionUniform(float weight){
	for (world.firstShape(); !world.endShape(); world.nextShape()) {
		shapes.push_back(ShapeSelected(&world.currentShape(), weight));
	}
}

idl::SelectionRadial::SelectionRadial(float weight, ofPoint point, float radius) {
	for (world.firstShape(); !world.endShape(); world.nextShape()) {
		float dist = (point - world.currentShape().getPosition()).length();
		float w;
		if (dist > radius) {
			w = 0;
		}
		else {
			w = (1 - dist / radius) * weight;
		}
		shapes.push_back(ShapeSelected(&world.currentShape(), w));
	}
}

idl::SelectionById::SelectionById(string id) {
	for (world.firstShape(); !world.endShape(); world.nextShape()) {

		//TODO better
		vector<string> ids = parseIds(world.currentShape().getId());
		for (std::vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
			if (id == (*it))
				shapes.push_back(ShapeSelected(&world.currentShape(), 1));
		}

	}
}

idl::SelectionByColor::SelectionByColor(std::string _color) {
	ofColor color = parseColor(_color);
	for (world.firstShape(); !world.endShape(); world.nextShape()) {
		if (color == world.currentShape().getColor())
			shapes.push_back(ShapeSelected(&world.currentShape(), 1));
	}
}

idl::SelectionRandom::SelectionRandom(float threshold) {
	srand(time(NULL));
	for (world.firstShape(); !world.endShape(); world.nextShape()) {
		float weight = ofRandom(0, 1);
		if (weight >threshold)
			shapes.push_back(ShapeSelected(&world.currentShape(), weight));
	}
}

idl::SelectionIntersection::SelectionIntersection(std::vector<std::shared_ptr<Selection>> s) {
	if (s.empty()) return;
	shared_ptr<Selection> s1 = *(s.begin());
	for (auto it = s.begin() + 1; it != s.end(); ++it) {
		if (!(*it)) continue;
		vector<ShapeSelected> intersection = intersectionTwo(*s1, *(*it));
		s1->getShapes() = intersection;
	}
	shapes = s1->getShapes();
}

std::vector<ShapeSelected> SelectionIntersection::intersectionTwo(Selection & s1, Selection & s2) {
	vector<ShapeSelected> intersection;
	auto shapesS1 = s1.getShapes();
	for (auto it1 = shapesS1.begin(); it1 != shapesS1.end(); ++it1) {
		auto shapesS2 = s2.getShapes();
		for (auto it2 = shapesS2.begin(); it2 != shapesS2.end(); ++it2) {
          if (it1->shape == it2->shape) {
            if(it1->weight < it2->weight) {
				intersection.push_back(*it1);
            } else {
              intersection.push_back(*it2);
            }
          }
		}
	}
	return intersection;
}
