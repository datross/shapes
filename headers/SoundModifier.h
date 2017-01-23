#ifndef SOUND_MODIFIER_H
#define SOUND_MODIFIER_H

#include "DependanteModifier.h"
#include "ofxAbletonLive.h"
#include "OscWrapper.h"
#include <memory>

namespace idl {
    
class SoundModifier : public DependanteModifier {
public:
    SoundModifier(shared_ptr<Seed>);
    ~SoundModifier();
    virtual void apply() = 0;
};

}
#endif // SOUND_MODIFIER_H
