#ifndef POST_FX_MODIFIER_H
#define POST_FX_MODIFIER_H

#include "DependanteModifier.h"
#include "PostFx.h"

namespace idl {

class PostFxModifier : public DependanteModifier {

private:
	PostFx *postFxEffect;

public:
	PostFxModifier(std::shared_ptr< Seed >, PostFx * postFxEffect = NULL);
	virtual void apply() = 0;
};

}

#endif
