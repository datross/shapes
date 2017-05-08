#include "world.h"
#include <iostream>

using namespace idl;
using namespace std;

World::World()
: selector(shapes.begin()), timePrec(ofGetElapsedTimef()) {
    current_dream = -1;
}

void World::pushNewDream() {
  shapes_dreams.push_back(list<shared_ptr<Shape> >());
  current_dream = shapes_dreams.size() -1;
}

World & idl::World::getInstance(){
	static World instance;
	return instance;
}

void World::clear() {
	shapes.clear();
	masks.clear();
}

Shape * World::currentShape() {
	return *selector;
}

// ofVideoPlayer& World::currentBackground() {
// 	return background;
// }

// void World::setup(){
// 	const int nb_x = 46,
// 		nb_y = 32;
// 	for (unsigned x = 0; x < nb_x; ++x) {
// 		for (unsigned y = 0; y < nb_y; ++y) {
// 			ofPath p; 
// 			p.rectangle(0, 0, 20, 20);
// 			p.setColor(ofColor(0, 100, 150));
// 			ofVec2f pos(x * ofGetWidth() / nb_x, y * ofGetHeight() / nb_y);
// 			shapes.push_back(shared_ptr<Shape>(new Shape(p, pos)));	
// 		}
// 	}
// }


bool World::endShape(){
	return selector == shapes.end();
}

bool World::firstShape(){
	if(shapes.empty())
		return false;
	selector = shapes.begin();
	return true;
}

bool World::nextShape(){
	++selector;
	return !endShape();
}

void World::update() {
	float now = ofGetElapsedTimef();
	for(firstShape(); !endShape(); nextShape()) {
		currentShape()->update(now - timePrec);
	}
	timePrec = now;
// 	background.update();

}

Shape* World::addShape(Shape & shape) {
	shapes_dreams[current_dream].push_front(shared_ptr<Shape>(new Shape(shape)));
	return shapes_dreams[current_dream].begin()->get();
}

Shape* World::addShape(Shape* shape) {
	shapes_dreams[current_dream].push_back(shared_ptr<Shape>(shape));
	return shapes_dreams[current_dream].begin()->get();
}

void World::addMask(Shape& shape) {
	masks.push_back(shape);
}

// void World::addBackground(ofVideoPlayer& video) {
// 	background = video;
// }

void World::setCurrentDream(unsigned dream) {
    if(dream >= shapes_dreams.size()){
      cerr<<"index out of range"<<endl;
      return;
    }
    current_dream = dream;
    shapes.clear();
    for(auto s : shapes_dreams[current_dream]) {
      shapes.push_front(s.get());
    }
}


