#ifndef BM_CONTROLS_H
#define BM_CONTROLS_H

#define BOUNCE_WITH_PROMPT_DETECTION
#include <Bounce2.h>

typedef void (*ControlCallback) (const int arg);

class Controls {

  public:

  Controls(int vol_l_pin, int vol_r_pin, int sel_l_pin, int sel_r_pin, int tempo_l_pin, int tempo_r_pin ) : 
  _volume(0), _prevVolume(0), _volumeStep(5), _select(0), _prevSelect(0), _volumeKnob(vol_l_pin, vol_r_pin), _selectKnob(sel_l_pin, sel_r_pin),
  _tempoKnob(tempo_l_pin, tempo_r_pin)

  {
  }

  void update() {
    int delta = _volumeKnob.readAndReset();
    if(delta != 0) {
      if(delta < 0 && _volume > 0) {
        _volume -= _volumeStep;
        if(_volume < 0) _volume = 0;
      } else {
        if(delta > 0 && _volume < 511) {
          _volume += _volumeStep;
          if(_volume > 511) _volume = 511;
        }
      }

      if(_volume != _prevVolume && _volumeCallback != NULL) {
        _volumeCallback(_volume >> 1);
        _prevVolume = _volume;
      }
    }

    delta = _selectKnob.readAndReset();
    _select += delta;
    if(_select != _prevSelect && _selectCallback != NULL) {
        _selectCallback(_select >> 1);
        _prevSelect = _select;
    }

    delta = _tempoKnob.readAndReset();
    _tempo += delta;
    if(_tempo != _prevTempo && _tempoCallback != NULL) {
        _tempoCallback(_tempo >> 1);
        _prevTempo = _tempo;
    }
  }

  void attachVolumeCallback(ControlCallback cb) {
    _volumeCallback = cb;
  }

  void attachSelectCallback(ControlCallback cb) {
    _selectCallback = cb;
  }

  void attachTempoCallback(ControlCallback cb) {
    _tempoCallback = cb;
  }

  void setSelect(int select) {
    _select = select << 1;
  }

  void setVolume(uint8_t vol) {
    _volume = vol << 1;
  }

  void setVolumeStep(uint8_t step) {
    _volumeStep = step;
  }

  void setTempo(uint8_t tempo) {
    _tempo = tempo << 1;
  }





protected:
  Encoder _volumeKnob;
  Encoder _selectKnob;
  Encoder _tempoKnob;

  int _volume, _prevVolume, _volumeStep;
  int _select, _prevSelect;
  int _tempo, _prevTempo;

  ControlCallback _volumeCallback;
  ControlCallback _selectCallback;
  ControlCallback _tempoCallback;



};
#endif
