#ifndef SELECTSHAPE_H
#define SELECTSHAPE_H

#include "selection.h"


namespace idl {

	class SelectShape : public Shape, public Selection	{
	public:
		SelectShape(shared_ptr<Selection> s);
		~SelectShape();

	private:

	};

}

#endif // !SELECTSHAPE_H
