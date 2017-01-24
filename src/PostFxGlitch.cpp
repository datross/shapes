/*
 * PostFxGlitch.cpp
 *
 *  Created on: Jan 20, 2017
 *      Author: julie
 */

#include "PostFxGlitch.h"

namespace idl {

PostFxGlitch::PostFxGlitch(ofxPostGlitchType type, ofFbo* fbo){
	postFx.setFx(type, true);
	if(fbo)
	postFx.setup(fbo);
}

PostFxGlitch::PostFxGlitch(ofxPostGlitch& fx) : postFx(fx){

}

void PostFxGlitch::setup(ofFbo* fbo){
	postFx.setup(fbo);
}

void PostFxGlitch::apply(){
	postFx.generateFx();
}

PostFxGlitch::~PostFxGlitch() {
	// TODO Auto-generated destructor stub
}

} /* namespace idl */
