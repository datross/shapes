#ifndef MODIFIER_SELECTION_H
#define MODIFIER_SELECTION_H

#include "selection.h"
#include "Modifier.h"

namespace idl {

struct ModifierSelection : public Modifier {
	Selection & selection;
	ModifierSelection(Selection&);
	void setSelection(Selection& s);
	virtual void apply();
};
	
}

#endif