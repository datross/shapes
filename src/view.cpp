#include "view.h"

using namespace idl;

View::View()
{
}

void View::drawShape(Shape& shape)
{
	ofPushMatrix();
	ofTranslate(shape.position.x, shape.position.y, 0.);
	ofRotate(shape.rotation);
	ofScale(shape.scale.x, shape.scale.y, 1.);
	
	shape.path.draw();
	
	ofPopMatrix();
}


void View::drawWorld(World & world)
{
	for(world.selectFirstShape(); world.isCurrentShape(); world.selectNextShape()) {
		drawShape(world.currentShape());
	}
}
