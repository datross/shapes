#include "world.h"

using namespace idl;
using namespace std;

World::World()
: selector(shapes.begin())
{
}

Shape & World::currentShape() {
	return *selector;
}

bool World::endShape()
{
	return selector != shapes.end();
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
	return currentShape();
}


