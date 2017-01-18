#include "DependenteModifier.h"

using namespace idl;


DependenteModifier::DependenteModifier(std::shared_ptr<Selection> s, std::shared_ptr<Seed> _seed) : ModifierSelection(s), seed(_seed) {
	
}	

DependenteModifier::~DependenteModifier() {

}
