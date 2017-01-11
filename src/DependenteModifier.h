#ifndef DEPENDENTE_MODIFIER_H
#define DEPENDENTE_MODIFIER_H

#include "modifierSelection.h"
#include "Seed.h"

namespace idl {
	class DependenteModifier : public ModifierSelection{
	public:
		
		DependenteModifier(Selection & s, Seed & _seed);
		~DependenteModifier();
		virtual void apply()=0;
	
	protected:
		Seed &seed;
	};
}

#endif // !DEPENDENTE_MODIFIER_H

