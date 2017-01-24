#include "view.h"
#include <iostream>

using namespace idl;
using namespace std;

View::View()
	: hud(false), fullScreen(false) {
}

void View::setOfApp(ofBaseApp * _app) {
	if(!_app) {
		cerr << "Error [View] : no ofBaseApp" << endl;
	}
	app = _app;
}

void View::drawShape(Shape& shape) {
	shape.draw();
}

void View::drawBackground(ofVideoPlayer& video) {
	ofColor(255, 255, 255);
	video.draw(0,0, ofGetWindowWidth(), ofGetWindowHeight());
}

void View::drawWorld(World & world) {
	drawBackground(world.currentBackground());
	for(world.firstShape(); !world.endShape(); world.nextShape()) {
		drawShape(world.currentShape());
	}
}

void View::toggleHud() {
	hud = !hud;
}

void View::drawHud() {
	Hud::getInstance().draw(hud);
}

void View::toggleFullScreen() {
	fullScreen = !fullScreen;
 	ofSetFullscreen(fullScreen);
}
