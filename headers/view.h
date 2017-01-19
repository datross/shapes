#ifndef VIEW_H
#define VIEW_H

#include "ofMain.h"
#include "world.h"
#include "Hud.h"

namespace idl {

class View {	
private:
	bool hud;
	bool fullScreen;
	ofBaseApp * app;
public:
	View();
	
	void setOfApp(ofBaseApp * app);
	
	void drawShape(Shape&);
	void drawWorld(World&);
	
	void toggleHud();
	
	void drawHud();
	
	void toggleFullScreen();
};
	
}

#endif