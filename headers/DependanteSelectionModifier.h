#ifndef DEPENDENTE_SELECTION_MODIFIER_H
#define DEPENDENTE_SELECTION_MODIFIER_H

#include <memory>

#include "modifierSelection.h"
#include "DependanteModifier.h"
#include "Seed.h"

namespace idl {

class DependanteSelectionModifier : public ModifierSelection, public DependanteModifier {
public:
        DependanteSelectionModifier(std::shared_ptr<Selection> s, std::shared_ptr<Seed> _seed);
        ~DependanteSelectionModifier();
        virtual void apply() = 0;
};

}

#endif // DEPENDENTE_MODIFIER_H

