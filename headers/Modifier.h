#ifndef MODIFIER_H
#define MODIFIER_H

#include <iostream>

namespace idl {

class Modifier {
public:
    Modifier();
    ~Modifier();
    virtual void apply() = 0;
    virtual void reset(){}
};

}

#endif
