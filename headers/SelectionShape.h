#ifndef SELECTION_SHAPE_H
#define SELECTION_SHAPE_H

#include "selection.h"
#include "shape.h"

namespace idl {
	class SelectionShape : public Selection, public Shape {
	public:
		SelectionShape();
		~SelectionShape();



	private:

	};
}


#endif // !SELECTION_SHAPE_H
