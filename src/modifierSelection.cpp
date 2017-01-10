#include "modifierSelection.h"

using namespace idl;

ModifierSelection::ModifierSelection(Selection& _selection)
	: selection(_selection)
{

}

void ModifierSelection::setSelection(Selection & s){
	selection = s;
}

void ModifierSelection::apply()
{

}

