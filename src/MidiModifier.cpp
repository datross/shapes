#include "MidiModifier.h"

using namespace idl;

MidiModifier::MidiModifier()
{
	midiOut.openPort("DelaunayPort");
}


MidiModifier::~MidiModifier()
{
}

void MidiModifier::apply() {
	//midiOut.sendNoteOn(1, 60, 64);
	midiOut << NoteOn(1, 60, 64) << NoteOff(1, 60);
	
}