#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "ofMain.h"
#include "shape.h"


namespace idl {

class World {
	std::vector<Shape> shapes;
	std::vector<Shape>::iterator selector;
	
public:
	World();
	
	/* accessors */
	Shape & currentShape();
	void setup();
	bool isCurrentShape();
	bool selectFirstShape();
	bool selectLastShape();
	bool selectNextShape();
};

}

#endif