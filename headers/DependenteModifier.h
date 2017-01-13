#ifndef DEPENDENTE_MODIFIER_H
#define DEPENDENTE_MODIFIER_H

#include <memory>

#include "modifierSelection.h"
#include "Seed.h"

namespace idl {

class DependenteModifier : public ModifierSelection {
public:
        DependenteModifier(Selection & s, std::shared_ptr<Seed> _seed);
        ~DependenteModifier();
        virtual void apply() = 0;

protected:
        std::shared_ptr<Seed> seed;
};

}

#endif // DEPENDENTE_MODIFIER_H

