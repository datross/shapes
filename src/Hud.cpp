#include "Hud.h"

using namespace idl;
using namespace std;

Hud::Hud() 
	: timePrec(0) {
	font.load(ofFilePath::getCurrentExeDir()+"../resources/verdana.ttf", 9);
}

Hud& Hud::getInstance() {
	static Hud hud;
	return hud;
}

void Hud::draw(bool visible) {	
	if(visible) {
		/* draw */
		ofSetColor(255,0,0);
		for(unsigned i = 0; i < lines.size(); ++i) {
			font.drawString(lines[i], HUD_LEFT_MARGIN, HUD_TOP_MARGIN + (i+1) * font.getLineHeight());
		}
	}
	
	/* clear */
	lines.clear();
	
	/* adds fps for next frame */
	float fps = 1. / (ofGetElapsedTimef() - timePrec);
	timePrec = ofGetElapsedTimef();
	addEntry<float>("FPS", fps);
}

void Hud::addEntry(string str) {
	lines.push_back(str);
}

