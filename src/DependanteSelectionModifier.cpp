#include "DependanteSelectionModifier.h"

using namespace idl;


DependanteSelectionModifier::DependanteSelectionModifier(std::shared_ptr<Selection> s, std::shared_ptr<Seed> _seed) : ModifierSelection(s), DependanteModifier(_seed) {
	
}	

DependanteSelectionModifier::~DependanteSelectionModifier() {

}
