#ifndef SELECTION_H
#define SELECTION_H

#include <vector>
#include <memory>

#include "ofMain.h"
#include "shape.h"
#include "world.h"

namespace idl {
	
struct ShapeSelected {
ShapeSelected(Shape* s, float w)
    : shape(s), weight(w) {}

    Shape* shape;
    float weight;
};

class Selection{
protected:
	std::vector<ShapeSelected> shapes;
	World& world;
public:
	Selection();
	std::vector<ShapeSelected>& getShapes() { return shapes; }
};

class SelectionUniform : public Selection {
public:
	SelectionUniform(float weight);
};

class SelectionRadial : public Selection {
public:
	SelectionRadial(float weight, ofPoint point, float radius);
};

class SelectionById : public Selection { 
public:
	SelectionById(std::string id);
};

class SelectionByColor : public Selection {
public:
	SelectionByColor(std::string color);
};

class SelectionRandom : public Selection {
public:
	SelectionRandom(float threshold);
};

class SelectionIntersection : public Selection {
public:
	SelectionIntersection(std::vector<std::shared_ptr<Selection>> s);
private:
	std::vector<ShapeSelected> intersectionTwo(Selection& s1, Selection& s2);
};

}

#endif
