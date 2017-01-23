#ifndef POST_FX_MODIFIER_H
#define POST_FX_MODIFIER_H

#include "DependanteModifier.h"
#include "PostFx.h"

namespace idl {

class PostFxModifier {

private:
	PostFx *postFxEffect;

public:
	PostFxModifier(PostFx * postFxEffect);
	virtual void apply() = 0;
};

}

#endif
