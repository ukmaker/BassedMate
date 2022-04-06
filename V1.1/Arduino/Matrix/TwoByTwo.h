#ifndef BM_TWOBYTWO_H
#define BM_TWOBYTWO_H


#define BOUNCE_WITH_PROMPT_DETECTION
#include <Bounce2.h>

#define TBT_R 1
#define TBT_G 2
#define TBT_B 4

#define TBT_REFRESH 1

typedef void (*ButtonCallback) ();

typedef struct Button {
  
  Bounce button;
  ButtonCallback pressCallback;
  ButtonCallback releaseCallback;
  ButtonCallback longPressCallback;
  uint8_t colour;
  uint32_t pressedTimestamp;
  bool longPressRaised;
  
} Button;


class TwoByTwo {

  public:

  TwoByTwo(int r, int g, int b, int l1, int l2, int l3, int l4, int s1, int s2, int s3, int s4) :
   _r(r), _g(g), _b(b), _leds({l1, l2, l3, l4}), _s1(s1), _s2(s2), _s3(s3), _s4(s4) 
   {
    // RGB Outputs are active low
    pinMode(_r, OUTPUT);
    digitalWrite(_r, HIGH);
    
    pinMode(_g, OUTPUT);
    digitalWrite(_g, HIGH);
    
    pinMode(_b, OUTPUT);
    digitalWrite(_b, HIGH);
    
    // LED grounds are active high
    pinMode(l1, OUTPUT);
    digitalWrite(l1, LOW);
    
    pinMode(l2, OUTPUT);
    digitalWrite(l2, LOW);
    
    pinMode(l3, OUTPUT);
    digitalWrite(l3, LOW);
    
    pinMode(l4, OUTPUT);
    digitalWrite(l4, LOW);

    // Switches are active low inputs an need pullups
    pinMode(_s1, INPUT_PULLUP);
    pinMode(_s2, INPUT_PULLUP);
    pinMode(_s3, INPUT_PULLUP);
    pinMode(_s4, INPUT_PULLUP);

    _buttons[0].button.attach(_s1);
    _buttons[1].button.attach(_s2);
    _buttons[2].button.attach(_s3);
    _buttons[3].button.attach(_s4);

    for(int i = 0; i < 4; i++) {
      _buttons[i].colour = 0;
      _buttons[i].pressedTimestamp = 0;
      _buttons[i].longPressRaised = false;
      _buttons[i].button.interval(50);
    }

    _lastUpdated = millis();
    _updateButton = 0;
    
  }

  void update() {
    for(int i = 0; i < 4 ; i++) {
      if(_buttons[i].button.update()) {
        if(_buttons[i].button.fell()) {
          _buttons[i].pressedTimestamp = millis();
          _buttons[i].longPressRaised = false;
          if(_buttons[i].pressCallback != NULL) {
            _buttons[i].pressCallback();
          }
        } else {
          if(_buttons[i].releaseCallback != NULL) {
            _buttons[i].releaseCallback();
          }
        }
      }

      if(_buttons[i].button.read() == 0) {
        if(!_buttons[i].longPressRaised) {
          if((millis() - _buttons[i].pressedTimestamp) > 1000) {
            _buttons[i].longPressRaised = true;
            if(_buttons[i].longPressCallback != NULL) {
              _buttons[i].longPressCallback();
            }
          }
        }
      }
    }
  }

  /**
   * For now this method runs on the Teensy on its own thread so that the LEDS
   * can be updated fast enough that they don't flash
   */
  void updateLeds() {

    int now = millis();
    if((now - _lastUpdated) > TBT_REFRESH) {
      _lastUpdated = now;
      digitalWrite(_leds[_updateButton], LOW);
      
      _updateButton++;
      if(_updateButton > 3) {
        _updateButton = 0;
      }
    
      _show(_buttons[_updateButton].colour & TBT_R, _buttons[_updateButton].colour & TBT_G, _buttons[_updateButton].colour & TBT_B, _leds[_updateButton]);
    }
  }
  
  void attachPressCallback(uint8_t b, ButtonCallback cb) {
    _buttons[b].pressCallback = cb;
  }

  void attachReleaseCallback(uint8_t b, ButtonCallback cb) {
    _buttons[b].releaseCallback = cb;
  }

  void attachLongPressCallback(uint8_t b, ButtonCallback cb) {
    _buttons[b].longPressCallback = cb;
  }
   
  void setButtonColour(uint8_t button, uint8_t colour) {
    if(button >= 0 && button < 4) {
      _buttons[button].colour = colour; 
    }
  }

  protected:
  int _r, _g, _b, _leds[4], _s1, _s2, _s3, _s4;

  int _lastUpdated;
  int _updateButton;

  Button _buttons[4];


  void _show(bool r, bool g, bool b, uint8_t button) {
    // and switch on the LEDS
    digitalWrite(_r, !r);
    digitalWrite(_g, !g);
    digitalWrite(_b, !b);
    // enable the button
    digitalWrite(button, HIGH);
  }
};
#endif
