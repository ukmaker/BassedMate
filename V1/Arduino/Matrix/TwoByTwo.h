#ifndef BM_TWOBYTWO_H
#define BM_TWOBYTWO_H


#define BOUNCE_WITH_PROMPT_DETECTION
#include <Bounce2.h>

#define TBT_R 1
#define TBT_G 2
#define TBT_B 4

#define TBT_REFRESH 1

typedef void (*ButtonCallback) ();

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

    _b1.attach(_s1);
    _b1.interval(50);
    
    _b2.attach(_s2);
    _b2.interval(50);
    
    _b3.attach(_s3);
    _b3.interval(50);
    
    _b4.attach(_s4);
    _b4.interval(50);

    _lastUpdated = millis();
    _updateButton = 0;
    
  }

  void update() {
    if(_b1.update() && _b1.fell() && (_b1Callback != NULL)) _b1Callback();
    if(_b2.update() && _b2.fell() && (_b2Callback != NULL)) _b2Callback();
    if(_b3.update() && _b3.fell() && (_b3Callback != NULL)) _b3Callback();
    if(_b4.update() && _b4.fell() && (_b4Callback != NULL)) _b4Callback();
  }

  void updateLeds() {

    int now = millis();
    if((now - _lastUpdated) > TBT_REFRESH) {
      _lastUpdated = now;
      _blank();
      _updateButton++;
      if(_updateButton > 3) _updateButton = 0;
      _show(_colours[_updateButton] & TBT_R, _colours[_updateButton] & TBT_G, _colours[_updateButton] & TBT_B, _leds[_updateButton]);
    }
  }
  
  void attachB1Callback(ButtonCallback cb) {
    _b1Callback = cb;
  }
   
  void attachB2Callback(ButtonCallback cb) {
    _b2Callback = cb;
  }
   
  void attachB3Callback(ButtonCallback cb) {
    _b3Callback = cb;
  }
   
  void attachB4Callback(ButtonCallback cb) {
    _b4Callback = cb;
  }

  void setButtonColour(uint8_t button, uint8_t colour) {
    if(button >= 0 && button < 4) _colours[button] = colour; 
  }

  protected:
  int _r, _g, _b, _leds[4], _s1, _s2, _s3, _s4;

  Bounce _b1, _b2, _b3, _b4;
  ButtonCallback _b1Callback, _b2Callback, _b3Callback, _b4Callback;

  int _lastUpdated;
  int _updateButton;

  uint8_t _colours[4];


  void _show(bool r, bool g, bool b, uint8_t button) {
    // and switch on the LEDS
    digitalWrite(_r, !r);
    digitalWrite(_g, !g);
    digitalWrite(_b, !b);
    // enable the button
    digitalWrite(button, HIGH);
  }
  
  void _blank() {
    digitalWrite(_leds[0], LOW);
    digitalWrite(_leds[1], LOW);
    digitalWrite(_leds[2], LOW);
    digitalWrite(_leds[3], LOW);
  }


};
#endif
