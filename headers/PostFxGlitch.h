/*
 * PostFxGlitch.h
 *
 *  Created on: Jan 20, 2017
 *      Author: julie
 */

#ifndef HEADERS_POSTFXGLITCH_H_
#define HEADERS_POSTFXGLITCH_H_

#include "ofMain.h"
#include "ofxPostGlitch.h"

namespace idl {

class PostFxGlitch {
private :
	ofxPostGlitch postFx;

public:
	PostFxGlitch(ofxPostGlitchType type, ofFbo* fbo = NULL);
	PostFxGlitch(ofxPostGlitch& fx);
	void setup(ofFbo* fbo);
	void apply();
	virtual ~PostFxGlitch();
};

} /* namespace idl */

#endif /* HEADERS_POSTFXGLITCH_H_ */
