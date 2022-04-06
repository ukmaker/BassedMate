#ifndef BM_ENCODERBUTTON_H
#define BM_ENCODER_BUTTON_H

#include "Encoder.h"
#include "Bounce2.h"

typedef void (*EncoderCallback) (const int arg);
typedef void (*ButtonCallback) ();

class EncoderButton {

  public:

  EncoderButton(int l_pin, int r_pin, int button_pin) :  _encoder(l_pin, r_pin)

  {     
    pinMode(button_pin, INPUT_PULLUP);
    _button.attach(button_pin);
    _button.interval(5);
  }

  int getValue() {
    return _value >> 1;
  }

  int getPrevValue() {
    return _prevValue >> 1;
  }

  void setValue(uint8_t val) {
    _value = val << 1;
  }

  void setStep(uint8_t step) {
    _step = step;
  }

  void attachEncoderCallback(EncoderCallback cb) {
    _encoderCallback = cb;
  }

  void attachButtonCallback(ButtonCallback cb) {
    _buttonCallback = cb;
  }

  void update() {
    
    _button.update();
    if(_button.fell() && (_buttonCallback != NULL)) {
      _buttonCallback();
    }
    
    int delta = _encoder.readAndReset();
    if(delta != 0) {
      if(delta < 0 && _value > 0) {
        _value -= _step;
        if(_value < 0) _value = 0;
      } else {
        if(delta > 0 && _value < 511) {
          _value += _step;
          if(_value > 511) _value = 511;
        }
      }

      if(_value != _prevValue && _encoderCallback != NULL) {
        _encoderCallback(getValue());
        _prevValue = _value;
      }
    }
  }

protected:

  Encoder _encoder;
  Bounce _button;
  int _value = 0, _prevValue = 0, _step = 1;
  EncoderCallback _encoderCallback;
  ButtonCallback _buttonCallback;

};
#endif
