#ifndef BM_ROTARY_BUTTON_H
#define BM_ROTARY_BUTTON_H

#include "Rotary.h"
#include "Bounce2.h"

typedef void (*EncoderCallback) (const int arg);
typedef void (*ButtonCallback) ();

class RotaryButton {

  public:

    RotaryButton(int l_pin, int r_pin, int button_pin) :  _rotary(l_pin, r_pin)

    {
      pinMode(button_pin, INPUT_PULLUP);
      _button.attach(button_pin);
      _button.interval(5);
    }

    int getValue() {
      return _value;
    }

    int getPrevValue() {
      return _prevValue;
    }

    void setValue(uint8_t val) {
      _value = val;
    }

    void setLimits(int min, int max) {
      _min = min;
      _max = max;
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
      if (_button.fell() && (_buttonCallback != NULL)) {
        _buttonCallback();
      }

      unsigned char delta = _rotary.process();
      if (delta) {
        if (delta == DIR_CW && _value > 0) {
          _value -= _step;
          if (_value < 0) _value = 0;
        } else {
          if (delta == DIR_CCW && _value < 255) {
            _value += _step;
            if (_value > 255) _value = 255;
          }
        }

        if(_value < _min) {
          _value = _min;
        } else if(_value > _max) {
          _value = _max;
        }

        if (_value != _prevValue && _encoderCallback != NULL) {
          _encoderCallback(getValue());
          _prevValue = _value;
        }
      }
    }

  protected:

    Rotary _rotary;
    Bounce _button;
    int _value = 0, _prevValue = 0, _step = 1;
    EncoderCallback _encoderCallback;
    ButtonCallback _buttonCallback;

    int _min = 0, _max = 255;

};
#endif
