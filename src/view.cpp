#include "view.h"

using namespace idl;

View::View()
{
}

void View::drawShape(Shape& shape) {
	shape.draw();
}

void View::drawBackground(ofVideoPlayer& video) {;
	video.draw(0,0, ofGetWindowWidth(), ofGetWindowHeight());
	cout << "Video : " << video.isPlaying() << endl;
}


void View::drawWorld(World & world) {
	drawBackground(world.currentBackground());
	for(world.firstShape(); !world.endShape(); world.nextShape()) {
		drawShape(world.currentShape());
	}

}
