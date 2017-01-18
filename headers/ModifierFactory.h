#ifndef MODIFIER_FACTORY_H
#define MODIFIER_FACTORY_H

#include <memory>
#include "FileManager.h"
#include "modifier.h"

namespace idl {
	class ModifierFactory {
	public:
		static ModifierFactory& getInstance();
		shared_ptr<Modifier> create(json jModifier);
		

	private:
		ModifierFactory();
		~ModifierFactory();
	};
}

#endif // !MODIFIER_FACTORY_H
