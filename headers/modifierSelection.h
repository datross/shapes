#ifndef MODIFIER_SELECTION_H
#define MODIFIER_SELECTION_H

#include "selection.h"
#include "modifier.h"

namespace idl {

class ModifierSelection : public Modifier {
protected :
	Selection & selection;

public:
	ModifierSelection(Selection&);
	void setSelection(Selection& s);
	virtual void apply() = 0;
};
	
}

#endif