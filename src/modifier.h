#ifndef MODIFIER_H
#define MODIFIER_H

namespace idl {

	class Modifier {

	public:
		Modifier();
		~Modifier();
		virtual void apply() = 0;
	};

}

#endif