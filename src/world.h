#ifndef WORLD_H
#define WORLD_H

#include <list>

#include "ofMain.h"
#include "shape.h"


namespace idl {

class World {
	/* ------------ Attributes ------------ */
	std::list<Shape> shapes;
	std::list<Shape>::iterator selector;

	/* ------------ Methods ------------ */
	
public:
	World();
	
	/* Returns a reference to the current shape. */
	Shape & currentShape();

	void setup();
	bool isCurrentShape();
	bool selectFirstShape();
	bool selectLastShape();
	bool selectNextShape();
	/* Returns true if selector is at the end. */
	bool endShape();
	/* Select the first shape. Returns false if there isn't one. */
	bool firstShape();
	/* Select next shape. Returns false of end is reached. */
	bool nextShape();

};

}

#endif