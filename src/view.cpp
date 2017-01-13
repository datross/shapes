#include "view.h"

using namespace idl;

View::View()
{
}

void View::drawShape(Shape& shape) {
	shape.draw();
}


void View::drawWorld(World & world) {
	for(world.firstShape(); !world.endShape(); world.nextShape()) {
		drawShape(world.currentShape());
	}
}
