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

bool World::isCurrentShape()
{
	return selector != shapes.end();
}

bool World::selectFirstShape()
{
	if(shapes.empty())
		return false;
	selector = shapes.begin();
	return true;
}

bool World::selectLastShape()
{
	if(shapes.empty())
		return false;
	selector = shapes.end();
	return true;
}

bool World::selectNextShape()
{
	++selector;
	return isCurrentShape();
}


