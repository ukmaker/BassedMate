#ifndef BM_SEQUENCER_H
#define BM_SEQUENCER_H

#include "VS1053.h"

typedef void (*SequenceCallback) (uint8_t beat, MIDINote note);
typedef void (*BeatCallback) (uint8_t beat);

/**
 * Class to encapsulate managing the note sequences
 */
class Sequencer {


public:


Sequencer(int defaultVoice) : _running(false), _millisPerBeat(1000), _ticks(0) {
  
  for(int y = 0; y < 4; y++) {
    _voices[y] = defaultVoice;
    _lastNotes[y] = {false, 0,0,0, false};
    for(int x = 0; x < 8; x++) {
      _notes[x][y] = {false, 0,0,0, false};
    }
  }
}

void attachNoteOnCallback(SequenceCallback cb) {
  _noteOnCallback = cb;
}

void attachBeatCallback(BeatCallback cb) {
  _beatCallback = cb;
}

void attachNoteOffCallback(SequenceCallback cb) {
  _noteOffCallback = cb;
}

void tick() {
    if(_running) {
    long t = millis();
  
    if((t - _ticks) > _millisPerBeat) {
      
      _beat++;
      if(_beat > 7) _beat = 0;
      
      if(_beatCallback != NULL) {
        _beatCallback(_beat);
      }
      
      for(int y =0; y < 4 ; y++) {
        if(_lastNotes[y].played && (_noteOffCallback != NULL)) {
          _noteOffCallback(_beat, _lastNotes[y]);
        }
        
        if(_notes[_beat][y].played && (_noteOnCallback != NULL)) {
          _notes[_beat][y].note = _voices[y];
          _noteOnCallback(_beat, _notes[_beat][y]);
        }
        
        _lastNotes[y] = _notes[_beat][y];
      }
      _ticks = t;
    }
  }
}

void setRunning(bool r) {
  _running = r;
}

bool isRunning() {
  return _running;
}

void setVoice(uint8_t channel, int voice) {
  _voices[channel] = voice;
}

int getVoice(uint8_t channel) {
  return _voices[channel];
}


void setTempo(int tempo) {
  // tempo range is 20 - 200 BPM
  // millis per beat (bpm / 60 * 1000
  _millisPerBeat = 60000 / tempo;
}

bool toggle(uint8_t x, uint8_t y) {
    // to start with we toggle the state
    // if there's no assigned instrument already, use the current voice
    _notes[x][y].played = !_notes[x][y].played;
  
    if(_notes[x][y].played && !_notes[x][y].assigned) {      
      _notes[x][y].note = _voices[y];
      _notes[x][y].velocity = 127;
      _notes[x][y].assigned = true;
    }

    return _notes[x][y].played;
}

void setActive(uint8_t x, uint8_t y) {
    _notes[x][y].played = true;
  
    if(!_notes[x][y].assigned) {      
      _notes[x][y].note = _voices[y];
      _notes[x][y].velocity = 127;
      _notes[x][y].assigned = true;
    }
}

protected:

bool _running;
int _ticks;
int _millisPerBeat;
int _beat;

MIDINote _notes[8][4];
MIDINote _lastNotes[4];
// which voice to use on each channel
int _voices[4];

SequenceCallback _noteOnCallback, _noteOffCallback;
BeatCallback _beatCallback;

};
#endif
