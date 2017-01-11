#include "world.h"

using namespace idl;
using namespace std;

World::World()
: selector(shapes.begin()){

}

Shape & World::currentShape() {
	return *selector;
}

void World::setup(){
	const int nb_x = 46,
		nb_y = 32;
	for (unsigned x = 0; x < nb_x; ++x) {
		for (unsigned y = 0; y < nb_y; ++y) {
			Shape shape;
			shape.path.rectangle(0, 0, 20, 20);
			shape.path.setColor(ofColor(0, 100, 150));
			shape.position = ofVec2f(x * ofGetWidth() / nb_x, y * ofGetHeight() / nb_y);

			shapes.push_back(shape);
		}
	}
}


bool World::endShape()
{
	return selector == shapes.end();
}

bool World::firstShape()
{
	if(shapes.empty())
		return false;
	selector = shapes.begin();
	return true;
}

bool World::nextShape()
{
	++selector;
	return !endShape();
}


