#include "world.h"

using namespace idl;
using namespace std;

World::World()
: selector(shapes.begin()), timePrec(ofGetElapsedTimef()) {

}

World & idl::World::getInstance(){
	static World instance;
	return instance;
}

void World::clear() {
	shapes.clear();
}

Shape & World::currentShape() {
	return *selector;
}

ofVideoPlayer& World::currentBackground() {
	return background;
}

void World::setup(){
	const int nb_x = 46,
		nb_y = 32;
	for (unsigned x = 0; x < nb_x; ++x) {
		for (unsigned y = 0; y < nb_y; ++y) {
			ofPath p; 
			p.rectangle(0, 0, 20, 20);
			p.setColor(ofColor(0, 100, 150));
			ofVec2f pos(x * ofGetWidth() / nb_x, y * ofGetHeight() / nb_y);
			Shape shape(p, pos);
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

void World::update() {
	float now = ofGetElapsedTimef();
	for(firstShape(); !endShape(); nextShape()) {
		currentShape().update(now - timePrec);
	}
	timePrec = now;
}

void World::addShape(Shape & shape) {
	shapes.push_front(shape);
}

void World::addMask(Shape& shape) {
	masks.push_back(shape);
}

void World::addBackground(ofVideoPlayer& video) {
	background = video;
}


