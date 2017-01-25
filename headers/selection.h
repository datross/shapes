#ifndef SELECTION_H
#define SELECTION_H

#include <vector>
#include <memory>

#include "ofMain.h"
#include "shape.h"
#include "world.h"
#include "SettingList.h"

namespace idl {
	
typedef std::pair<Shape*, float> ShapeSelected;


class Selection{
protected:
	std::vector<ShapeSelected> shapes;
	World& world;
public:
	Selection(string type, SettingList& param);
	
	std::vector<ShapeSelected>& getShapes() { return shapes; }
	// TODO gérer proprement la construction
	void uniform(float weight);
	void radial(float weight, ofPoint point, float radius);
	void byId(std::string id);
	void byColor(std::string color);
	void random(float threshold);

};

}

#endif
