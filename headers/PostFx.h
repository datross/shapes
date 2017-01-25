#ifndef POST_FX_H
#define POST_FX_H
#include "ofMain.h"
#include "ofxPostGlitch.h"

namespace idl {

class PostFx {
public:
	PostFx();
	virtual void setup(ofFbo * fbo = NULL, ofxPostGlitch * pg = NULL) = 0;
	virtual void apply() = 0;
	virtual ~PostFx();
};

}

#endif
