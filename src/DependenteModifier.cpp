#include "DependenteModifier.h"

using namespace idl;


DependenteModifier::DependenteModifier(Selection & s, std::shared_ptr<Seed> _seed) : ModifierSelection(s), seed(_seed) {
	
}	

DependenteModifier::~DependenteModifier() {

}
