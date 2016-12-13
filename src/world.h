#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "ofMain.h"
#include "shape.h"


namespace idl {

struct World {
	std::vector<Shape> shapes;
	std::vector<Shape>::iterator selector;
	
	World();
	
	/* accessors */
	Shape & currentShape();
	bool isCurrentShape();
	bool selectFirstShape();
	bool selectLastShape();
	bool selectNextShape();
};

}

#endif