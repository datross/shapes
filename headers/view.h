#ifndef VIEW_H
#define VIEW_H

#include "ofMain.h"
#include "world.h"
#include "PostFxGlitch.h"
#include <memory>

namespace idl {

class View {
	shared_ptr<PostFxGlitch> fx;
	ofFbo fbo;

public:
	View();
	void drawShape(Shape&);
	void setFx(shared_ptr<PostFxGlitch> _fx);
	void drawBackground(ofVideoPlayer&);
	void drawWorld(World&);
	void updateFbo(World & world);
	void drawFbo();
};
	
}

#endif
