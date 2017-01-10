#ifndef DEPENDENTE_MODIFIER_H
#define DEPENDENTE_MODIFIER_H

#include "modifierSelection.h"
#include "Seed.h"

namespace idl {
	class DependenteModifier : public ModifierSelection{
	public:
		DependenteModifier(Selection& s, Seed seed);
		~DependenteModifier();
		virtual void apply();
	private:

	};
}

#endif // !DEPENDENTE_MODIFIER_H

