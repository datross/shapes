/*
 * PostFxGlitch.h
 *
 *  Created on: Jan 20, 2017
 *      Author: julie
 */

#ifndef HEADERS_POSTFXGLITCH_H_
#define HEADERS_POSTFXGLITCH_H_

#include "ofMain.h"
#include "PostFx.h"
#include "ofxPostGlitch.h"

namespace idl {

class PostFxGlitch : public PostFx {
private :
	ofxPostGlitch postFx;
	ofxPostGlitchType type;
public:
	PostFxGlitch(ofxPostGlitchType type);
	PostFxGlitch(ofxPostGlitch& fx);
	virtual void setup(ofFbo* fbo);
	virtual void apply();
	virtual ~PostFxGlitch();
};

} /* namespace idl */

#endif /* HEADERS_POSTFXGLITCH_H_ */
