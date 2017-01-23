#ifndef MODIFIER_SHAPE_CREATOR_H
#define MODIFIER_SHAPE_CREATOR_H

#include "Modifier.h"

namespace idl {

	class ShapeCreator : public Modifier {
	public:
		ShapeCreator();
		~ShapeCreator();
		virtual void apply();

	private:

	};

}
#endif // !MODIFIER_SHAPE_CREATOR_H
