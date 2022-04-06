#ifndef BM_MIXER_H
#define BM_MIXER_H

#include "AD5204.h"
#include "VS1053.h"
#include "ADMix.h"
#include "RTMIDI.h"

#define DP_BASS_WET 2
#define DP_BASS_DRY 0
#define DP_MASTER_VOL_L 1
#define DP_MASTER_VOL_R 3

#define MIX_MAX -3
#define MIX_MIN -31

class Mixer {

  public:

  Mixer(AD5204 &digiPot, VS1053 &midi) : _digiPot(digiPot), _midi(midi) {}

  void init() {
    _midi.loadUserCode(ADMIX_CODE_SIZE, ADMix_atab, ADMix_dtab);
    delay(100);
  _midi.sendCommand(VS_REG_AICTRL0, MIX_MAX); // Min volume
    _midi.sendCommand(VS_REG_AIADDR, 0x0f00); // activate the plugin
delay(100);
  
    _midi.loadUserCode(RTMIDI_CODE_SIZE, RTMIDI_atab, RTMIDI_dtab);
delay(100);
      _midi.sendCommand(VS_REG_AIADDR, 0x50);
  }

  void setVolumeLevel(int volume) {
    _volume = volume;
    _digiPot.write(DP_MASTER_VOL_L,volume);
    _digiPot.write(DP_MASTER_VOL_R,255 - volume);

    // Output is fully on or off - only the digipot matters
    if(volume == 0) {
      _midi.setVolume(0,127); 
    } else {
      _midi.setVolume(0,127);
    }
  }

  void setBassWetLevel(int volume) {
    _bassWet = volume;
    _digiPot.write(DP_BASS_WET, volume);
  }

  void setBassDryLevel(int volume) {
    _bassDry = volume;
    _digiPot.write(DP_BASS_DRY, 255 - volume);
  }

  /*
   * Map the volume level 0-256 onto the LINE input levels
   */
  void setLineLevel(int volume) {
    _line = volume;
    int v = MIX_MIN + (volume * (MIX_MAX - MIX_MIN)) / 256;
    _midi.sendCommand(VS_REG_AICTRL0, v);
  }

  int getVolumeLevel() {
    return _volume;
  }

  int getBassWetLevel() {
    return _bassWet;
  }

  int getBassDryLevel() {
    return _bassDry;
  }

  int getLineLevel() {
    return _line;
  }

  protected:
  
    AD5204 &_digiPot;
    VS1053 &_midi;
    
    int _volume, _bassWet, _bassDry, _line = 0;

};
#endif
