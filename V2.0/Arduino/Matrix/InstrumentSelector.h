#include "Instruments.h"
#include "Screen.h"

#ifndef BM_INSTRUMENTSELECTOR_H
#define BM_INSTRUMENTSELECTOR_H

class InstrumentSelector {

  public:

    InstrumentSelector(Sequencer *seq, Screen *screen, Instruments **assortment ) : _sequencer(seq), _screen(screen), _assortment(assortment) {}

    void select(int sel) {

      if (sel < 0) {
        sel = 0;
      } else if (sel >= _assortment[_channel]->getNumVoices()) {
        sel = _assortment[_channel]->getNumVoices() - 1;
      }

      _index = sel;

      playSelection();
      scrollInstrumentSelection();
    }

    void playSelection() {
      Instrument instrument = getSelectedInstrument();
      _sequencer->setInstrument(_channel, instrument);      
    }

    Instrument getSelectedInstrument() {
      return _assortment[_channel]->getInstrumentByIndex(_index);
    }

    uint8_t getChannel() {
      return _channel;
    }

    void setChannel(uint8_t channel) {
      _channel = channel;
      Instrument i = _sequencer->getInstrument(channel);
      _index = _assortment[_channel]->indexOf(_sequencer->getInstrument(_channel).voice.id);
    }

    uint8_t getIndex() {
      return _index;
    }

    uint8_t getNumVoices() {
      return _assortment[_channel]->getNumVoices();
    }


    void prepareSelection() {

      int start = _index - 2;
      int end = _index + 2;

      uint8_t ndx = 0;
      for (int i = start; i <= end; i++) {
        _names[ndx] = getNameByIndex(i);
        ndx++;
      }
    }

    const char *getNameByIndex(int index) {
      const char *empty = "";
      if (index < 0) return empty;
      if (index >=  _assortment[_channel]->getNumVoices()) return empty;
      return  _assortment[_channel]->getInstrumentByIndex(index).voice.name;
    }

    void showInstrumentSelection() {
      prepareSelection();
      _screen->clearAllInstrumentText();
      _screen->setupInstrumentChoices(_channel, _names);
    }

    void scrollInstrumentSelection() {
      prepareSelection();
      _screen->scrollInstrumentChoices(_names);
    }


  protected:

    Sequencer *_sequencer;
    Instruments **_assortment;
    Screen *_screen;

    uint8_t _index = 0;
    uint8_t _channel = 0;
    const char* _names[5];

};

#endif
