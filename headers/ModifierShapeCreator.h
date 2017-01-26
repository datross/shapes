#ifndef MODIFIER_SHAPE_CREATOR_H
#define MODIFIER_SHAPE_CREATOR_H

#include "DependanteModifier.h"
#include "shape.h"

namespace idl {

	class ShapeCreator : public DependanteModifier {
	public:
		ShapeCreator(Shape& shape, shared_ptr<Seed> s);
		~ShapeCreator();
		virtual void apply();

	private:
		Shape& shape;
	};

}
#endif // !MODIFIER_SHAPE_CREATOR_H
