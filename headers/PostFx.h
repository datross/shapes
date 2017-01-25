#ifndef POST_FX_H
#define POST_FX_H
#include "ofMain.h"

namespace idl {

class PostFx {
public:
	PostFx();
	virtual void setup(ofFbo * fbo = NULL) = 0;
	virtual void apply() = 0;
	virtual ~PostFx();
};

}

#endif
