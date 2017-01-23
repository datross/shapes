#include "view.h"

using namespace idl;

View::View(){
	fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
	//fx->setup(fbo);
	//fx = shared_ptr<PostFxGlitch>(new PostFxGlitch(OFXPOSTGLITCH_INVERT, &fbo));
}

void View::drawShape(Shape& shape) {
	shape.draw();
}

void View::setFx(shared_ptr<PostFxGlitch> _fx){
	fx = _fx;
	fx->setup(&fbo);
}

void View::drawBackground(ofVideoPlayer& video) {
	ofColor(255, 255, 255);
	video.draw(0,0, ofGetWindowWidth(), ofGetWindowHeight());
}


void View::drawWorld(World & world) {
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_DISABLED);
	drawBackground(world.currentBackground());
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_SCREEN);
	for(world.firstShape(); !world.endShape(); world.nextShape()) {
		drawShape(world.currentShape());
	}
}

void View::updateFbo(World & world){
	fbo.begin();
		//ofClear(0, 0, 0,255);
		drawWorld(world);
	fbo.end();

}

void View::drawFbo(){
	fx->apply();
	fbo.draw(0,0);
}

