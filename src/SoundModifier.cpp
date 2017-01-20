#include "SoundModifier.h"

using namespace idl;

SoundModifier::SoundModifier(shared_ptr<Seed> s, OscWrapper &_osc) : DependanteModifier(s), osc(_osc){

}


SoundModifier::~SoundModifier()
{
}
