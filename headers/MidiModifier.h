#ifndef MIDI_MODIFIER_H
#define MIDI_MODIFIER_H

#include "Modifier.h"
#include "ofxMidiOut.h"

namespace idl {


class MidiModifier : public Modifier
{
public:
	MidiModifier();
	~MidiModifier();

	virtual void apply();

private:
	ofxMidiOut midiOut;
};

}

#endif MIDI_MODIFIER_H