#ifndef MODIFIER_H
#define MODIFIER_H

#include "SettingList.h"

namespace idl {

class Modifier {
public:
    Modifier(SettingList list);
	Modifier();
    ~Modifier();
    virtual void apply() = 0;
};

}

#endif