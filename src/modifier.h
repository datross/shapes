#ifndef MODIFIER_H
#define MODIFIER_H

#include "selection.h"

namespace idl {

struct Modifier {
	Selection & selection;
	Modifier(Selection&);
	virtual void apply();
};
	
}

#endif