#ifndef MODIFIER_SHAPE_CREATOR_H
#define MODIFIER_SHAPE_CREATOR_H

#include "Modifier.h"
#include "shape.h"

namespace idl {

	class ShapeCreator : public Modifier {
	public:
		ShapeCreator(Shape& shape);
		~ShapeCreator();
		virtual void apply();

	private:
		Shape& shape;
	};

}
#endif // !MODIFIER_SHAPE_CREATOR_H
