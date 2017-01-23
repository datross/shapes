#include "ModifierShapeCreator.h"
#include "world.h"

using namespace idl;

ShapeCreator::ShapeCreator(Shape& s) : shape(s){
	
}

ShapeCreator::~ShapeCreator(){
}

void idl::ShapeCreator::apply(){
	World world = World::getInstance();
	world.addShape(shape);
}
