#ifndef SOUND_MODIFIER_H
#define SOUND_MODIFIER_H


#include "modifier.h"
#include "ofxAbletonLive.h"

namespace idl {
    
class SoundModifier : public Modifier {
private:
    ofxAbletonLive live;
public:
    SoundModifier();
    ~SoundModifier();
    virtual void apply() = 0;
};

}
#endif // SOUND_MODIFIER_H
