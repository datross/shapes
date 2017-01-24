#ifndef WORLD_H
#define WORLD_H

#include <list>

#include "ofMain.h"
#include "shape.h"


namespace idl {

class World {
	std::list<Shape> shapes;
	std::list<Shape>::iterator selector;
	
	std::list<Shape> masks;
	ofVideoPlayer background;

	float timePrec;
	
	World();
public:
	static World& getInstance();
	
	/* Makes the world empty */
	void clear();
		
	/* TODO remove this */
	void setup();

	/*Returns a reference to the background*/
	ofVideoPlayer& currentBackground();
		
	/* Returns a reference to the current shape. */
	Shape & currentShape();
	/* Returns true if selector is at the end. */
	bool endShape();
	/* Select the first shape. Returns false if there isn't one. */
	bool firstShape();
	/* Select next shape. Returns false of end is reached. */
	bool nextShape();
	/* Add a shape to the world. */
	void addShape(Shape& shape);

	/* Add a background video to the world */
	void addBackground(ofVideoPlayer& video);

	/* Add a mask to the world */
	void addMask(Shape& shape);
	
	/* updates the whole world logic */
	void update();
	
	/* reset every fields that have an original value */
	void resetTransform();
};

}

#endif
