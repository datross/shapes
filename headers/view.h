#ifndef VIEW_H
#define VIEW_H

#include "ofMain.h"
#include "world.h"
#include "Hud.h"
#include "PostFx.h"
#include <memory>
#include <map>

namespace idl {

class View {	
private:
	bool hud;
	bool fullScreen;
	std::map<int, std::shared_ptr<PostFx> > FXs;
	int freeId;
	ofFbo fbo;
	ofxPostGlitch * postGlitch;
	ofColor veilColor;
	
	
	View();
public:
	static View & getInstance();
	
	void setGlitch(ofxPostGlitch * pg);
	ofxPostGlitch * getGlitch();
	
	void setVeilColor(ofColor color);
	ofColor getVeilColor();
	
	int addFx(std::shared_ptr<PostFx> fx);
	void removeFx(int id);
	
	
	void updateFbo();
	void drawFbo();
	
	void drawShape(Shape&);
	void drawBackground(ofVideoPlayer&);
	void drawWorld();
	
	void toggleHud();
	
	void drawHud();
	
	void toggleFullScreen();
};
	
}

#endif
