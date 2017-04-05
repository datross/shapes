#include "SelectShape.h"
using namespace idl;

SelectShape::SelectShape(shared_ptr<Selection> s){
	shapes = s->getShapes();
}


SelectShape::~SelectShape()
{
}