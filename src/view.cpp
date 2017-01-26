#include "view.h"
#include <iostream>

using namespace idl;
using namespace std;

View::View()
	: hud(false), fullScreen(false), freeId(0) {
	fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight(), GL_RGBA);
}

View & View::getInstance() {
	static View instance;
	return instance;
}

void View::setGlitch(ofxPostGlitch * pg) {
	postGlitch = pg;
	postGlitch->setup(&fbo);
}

ofxPostGlitch * View::getGlitch() {
	return postGlitch;
}

void View::drawShape(Shape& shape) {
	shape.draw();
}

void View::drawBackground(ofVideoPlayer& video) {
	ofColor(255, 255, 255);
	video.draw(0,0, ofGetWindowWidth(), ofGetWindowHeight());
}

void View::drawWorld() {
	drawBackground(World::getInstance().currentBackground());
	for(World::getInstance().firstShape(); !World::getInstance().endShape(); World::getInstance().nextShape()) {
		drawShape(World::getInstance().currentShape());
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

int View::addFx(std::shared_ptr<PostFx> fx){
	int tmp = freeId;
	fx->setup(&fbo);
	FXs[freeId++] = fx;
	return tmp;
}

void View::removeFx(int id) {
	auto it = FXs.find(id);
	if(it == FXs.end())
		return;
	FXs.erase(it);
}

void View::updateFbo(){
	fbo.begin();
	// TODO blending
	//ofEnableAlphaBlending();
	ofClear(0,0,0,0);
	drawWorld();
	fbo.end();
}

void View::drawFbo(){
	for(auto& fx : FXs)
		fx.second->apply();
	postGlitch->generateFx();
	ofSetColor(220);
	fbo.draw(0,0);
}
