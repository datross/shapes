#ifndef SOUND_MODIFIER_H
#define SOUND_MODIFIER_H


#include "modifier.h"
#include "DependenteModifier.h"
#include "ofxAbletonLive.h"
#include "OscWrapper.h"

namespace idl {
    
class SoundModifier : public DependenteModifier {
private:
    OscWrapper &osc;
public:
    SoundModifier();
    ~SoundModifier();
    virtual void apply() = 0;
};

}
#endif // SOUND_MODIFIER_H

/* 

*/
