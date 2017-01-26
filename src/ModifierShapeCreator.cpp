#include "ModifierShapeCreator.h"
#include "world.h"

using namespace idl;

ShapeCreator::ShapeCreator(Shape& s, shared_ptr<Seed> seed) : shape(s), DependanteModifier(seed){
	
}

ShapeCreator::~ShapeCreator(){

}

void idl::ShapeCreator::apply(){
	bool apply = seed->current().x > 0.5 ? true : false;
	if (!apply)
		return;
	World world = World::getInstance();
	world.addShape(shape);
}
