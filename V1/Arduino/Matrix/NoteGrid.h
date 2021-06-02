#ifndef BM_NOTE_GRID_H
#define BM_NOTE_GRID_H

#include "Adafruit_NeoTrellis.h"

#define NG_GLOW_TICKS 25

#define NG_NOTE_UNASSIGNED 0
#define NG_NOTE_ASSIGNED 1

#define NG_NOTE_UNASSIGNED_COLOUR 0x000000
#define NG_NOTE_ASSIGNED_COLOUR 0x00ff00

#define NG_NOTE_UNASSIGNED_COLOUR_H 0x000088
#define NG_NOTE_ASSIGNED_COLOUR_H 0x00ff88

#define NG_BEAT_FLASH_COLOUR 0xaa8811
#define NG_NOTE_HIGHLIGHT_COLOUR 0x0000ff

#define NG_BLINK_R 0xff
#define NG_BLINK_G 0x00
#define NG_BLINK_B 0xaa
#define NG_BLINK_TICKS 250

typedef void (*KeyPressCallback) (uint8_t x, uint8_t y);

class NoteGrid {

  public:

  NoteGrid(Adafruit_MultiTrellis &trellis) : _trellis(trellis), _flashBeat(false), _lastKeyPressed(-1) {

    for(int i = 0; i < 4 ; i++) {
      _highlightLine[i] = false;
    }
  }

  void attachEventHandler(TrellisCallback cb) {
    _eventHandler = cb;
  }

  void attachKeyPressCallback(KeyPressCallback cb) {
    _keyPressCallback = cb;
  }
  
  void attachKeyLongPressCallback(KeyPressCallback cb) {
    _keyLongPressCallback = cb;
  }

  // crufty way to get long-press handling in an instance
  TrellisCallback handleEvent(keyEvent e) {

      // RISING edge means the button has been pressed
      if(e.bit.EDGE == SEESAW_KEYPAD_EDGE_RISING) {
        // handle the normal key-press here
        if(_keyPressCallback != NULL) {
          int x = e.bit.NUM % 8;
          int y = e.bit.NUM / 8;
          _keyPressCallback(x, y);
        }
        _lastKeyPressed = e.bit.NUM;
        _lastKeyPressedTime = millis();
      }
    
      // FALLING edge means the button has been released
      if(e.bit.EDGE == SEESAW_KEYPAD_EDGE_FALLING) {
        _lastKeyPressed = -1;
      }
      
      return 0;
  }

  void begin() {
    
    for(int i = 0; i < 32; i++){
        _trellis.setPixelColor(i, ((i & 0b00110000) << 12) + ((i & 0b00001100) << 4) + (i & 0b00000011)); //addressed with keynum
        _trellis.show();
        delay(50);
    }
    
    for(int y = 0; y < 4; y++){
      for(int x = 0; x < 8; x++){
        //activate rising and falling edges on all keys
        _trellis.activateKey(x, y, SEESAW_KEYPAD_EDGE_RISING, true);
        _trellis.activateKey(x, y, SEESAW_KEYPAD_EDGE_FALLING, true);
        _trellis.registerCallback(x, y, _eventHandler);
        _notes[y][x] = 0x000000;
        _trellis.setPixelColor(x, y, 0x000000); //addressed with x,y
        _trellis.show(); //show all LEDs
        delay(50);
      }
    }
  }

  void setFlashBeat(bool flash) {
    _flashBeat = flash;
  }

  bool getFlashBeat() {
    return _flashBeat;
  }

  void setActive(uint8_t x, uint8_t y) {
    _notes[y][x] = true;
    _showNote(x, y);
  }
  
  void setInactive(uint8_t x, uint8_t y) {
    _notes[y][x] =  false;
    _showNote(x, y);
  }

  void blink(uint8_t x, uint8_t y) {
    _blinkX = x;
    _blinkY = y;
    _blinkTicks = 0;
  }

  void cancelBlink() {
    _blinkX = -1;
  }
  
  
  void restoreLine(int line) {
    for(int i = 0; i < 4; i++) {
      _highlightLine[i] = false;
    } 
    
    for(int x=0; x<8; x++) {
      _updateNote(x, line);
    }
    
    _trellis.show();
  }
  
  void restoreLines() {
    for(int i = 0; i < 4; i++) {
      _highlightLine[i] = false;
    } 
    
    for(int x=0; x<8; x++) {
      _updateNote(x, 0);
      _updateNote(x, 1);
      _updateNote(x, 2);
      _updateNote(x, 3);
    }
    _trellis.show();
  }
  
  void selectLine(int line) {
    for(int i = 0; i < 4; i++) {
      _highlightLine[i] = false;
    }   
    _highlightLine[line] = true;
    for(int x=0; x<8; x++) {
      _updateNote(x, line);
    }
    _trellis.show();  
  }
  
  void beat(int column) {
    _ticks = NG_GLOW_TICKS;
    _lastBeat = _beat;
    _beat = column;
  }

  void tick() {
    
    int r = 0xaa;
    int g = 0x88;
    int b = 0x11;

    int hr, hg, hb;

    uint32_t nc, now;

    now = millis();

    if(_lastKeyPressed != -1) {
      if((now - _lastKeyPressedTime) > 500) {
        if(_keyLongPressCallback != NULL) {
          int x = _lastKeyPressed % 8;
          int y = _lastKeyPressed / 8;
          _keyLongPressCallback(x, y);
          _lastKeyPressed = -1;
        }
      }
    }

    if(_blinkX != -1) {
      
      if(_blinkTicks > NG_BLINK_TICKS) {
        _blinkTicks = 0; 
      }
      
      r = NG_BLINK_R;
      g = NG_BLINK_G;
      b = NG_BLINK_B;
      
      // make the column glow to show it's the beat
      r = (r * _blinkTicks ) / NG_BLINK_TICKS;
      g = (g * _blinkTicks ) / NG_BLINK_TICKS;
      b = (b * _blinkTicks ) / NG_BLINK_TICKS;
      nc = pixelColour(_blinkX, _blinkY, r, g, b);
      _trellis.setPixelColor(_blinkX, _blinkY, (r<<16)+(g<<8)+b);
      _trellis.show();
      _blinkTicks++;
    }
    
    if(_flashBeat) {
      if(_ticks > 0 && _beat >= 0 && _beat < 8) {
        _ticks--;
        if((_ticks & 1) == 0) {
          r = 0xaa;
          g = 0x88;
          b = 0x11;
          
          // make the column glow to show it's the beat
          r = (r * _ticks ) / NG_GLOW_TICKS;
          g = (g * _ticks ) / NG_GLOW_TICKS;
          b = (b * _ticks ) / NG_GLOW_TICKS;
          
          for(int i =0; i < 4; i++) {
            nc  = pixelColour(_beat, i, r, g, b);
            _trellis.setPixelColor(_beat, i, nc);
          }
          _trellis.show();
        }
      }
    }
  }

  uint32_t pixelColour(uint8_t x, uint8_t y, uint32_t r, uint32_t g, uint32_t b) {
    uint32_t hr, hg, hb;           
    uint32_t nc  = _noteColour(x, y);
    
    hr = ((nc & 0x00ff0000) >> 16) + r; 
    if(hr > 0xff) hr = 0xff;
    
    hg = ((nc & 0x00ff00) >> 8) + g; 
    if(hg > 0xff) hg = 0xff;
    
    hb = ((nc & 0x00ff)) + b; 
    if(hb > 0xff) hb = 0xff;
    
    return (hr << 16) + (hg << 8) + hb;   
  }


protected:
  Adafruit_MultiTrellis &_trellis;
  TrellisCallback _eventHandler;
  KeyPressCallback _keyPressCallback, _keyLongPressCallback;
  
  bool _notes[4][8];

  // 0 means no highlight
  bool _highlightLine[4];
  bool _flashBeat;

  int _blinkX = -1;
  int _blinkY = -1;
  uint32_t _blinkTicks = 0;
  
  uint32_t _ticks, _lastKeyPressedTime;
  int _beat, _lastBeat, _lastKeyPressed = -1;

  void _showNote(uint8_t x, uint8_t y) {
    _updateNote(x, y);
    _trellis.show();
  }

  void _updateNote(uint8_t x, uint8_t y) {
    uint32_t colour = _noteColour(x, y);
    _trellis.setPixelColor(x, y, colour);
  }

  uint32_t _noteColour(uint8_t x, uint8_t y) {

    if(_highlightLine[y]) {
      if(_notes[y][x]) {
        return NG_NOTE_ASSIGNED_COLOUR_H;      
      } else {
        return NG_NOTE_UNASSIGNED_COLOUR_H;      
      }       
    }
    
    if(_notes[y][x]) {
      return NG_NOTE_ASSIGNED_COLOUR;      
    } else {
      return NG_NOTE_UNASSIGNED_COLOUR;      
    }    
  }

};
#endif
