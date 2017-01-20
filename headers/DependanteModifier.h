#ifndef DEPENDANTE_MODIFIER_H
#define DEPENDANTE_MODIFIER_H

#include "Modifier.h"
#include "Seed.h"
#include <memory>

namespace idl {
	class DependanteModifier : public virtual Modifier{
		std::shared_ptr<Seed> seed;
	public:
		DependanteModifier(std::shared_ptr<Seed>);
		~DependanteModifier();
		virtual void apply() =0;
	private:

	};
}

#endif // !DEPENDANTE_MODIFIER_H
