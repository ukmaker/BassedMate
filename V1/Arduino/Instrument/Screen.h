/**
 * Encapsulate all the methods needed to draw on the screen
 */
#ifndef BM_SCREEN_H
#define BM_SCREEN_H
#include <Adafruit_GFX.h>    // Core graphics library
#include <ST7735_t3.h>    // Hardware-specific library

class Screen {

public:

  Screen(ST7735_t3 &lcd, int sck, int sdi) : _lcd(lcd), _sck(sck), _sdi(sdi), _fgColour(0xffff), _bgColour(0x0000), _highlightColour(0xffffaa) {  
    SPI1.setMOSI(_sdi);
    SPI1.setSCK(_sck);
    SPI1.begin();
    SPI1.setBitOrder(MSBFIRST);
    
    _lcd.initR(INITR_BLACKTAB);
    _lcd.setRotation(1);
    _lcd.fillScreen(ST7735_BLACK);
    delay(500);
  }


void printInstrumentName(const char * instrument, int x, int y)
{
  _lcd.fillRect(x,y, x+128, y-20, _bgColour);
  _lcd.setTextColor(_highlightColour);
  _lcd.setCursor(x, y);
  _lcd.print(instrument);
}

void printInstrumentNames(const char * instrument[5], int x, int y)
{
  _lcd.fillRect(x,y-20, x+128, y+80, _bgColour);
  for(int i=0; i<5; i++) {
    if(i == 2) {
      _lcd.setTextColor(_highlightColour);
    } else {
      _lcd.setTextColor(_fgColour);
    }
    _lcd.setCursor(x, y + (12 * i));
    _lcd.print(instrument[i]);
  }
}


void drawVolumeBar(uint8_t volume) {
  // Volume bounding box is (0,5),(63,19)
  // Draw the full triangle 
  _lcd.fillTriangle( 0,  19, 63,  19,  63, 5,  _highlightColour);
  // now clip the end off as needed
  _lcd.fillRect( volume / 4,  5,  63,  19, _bgColour);
}

void printTempo(uint8_t tempo) {
  _lcd.fillRect(70,0, 70, 20, _bgColour);
  _lcd.setCursor(70, 10);
  _lcd.setTextColor(_highlightColour);
  _lcd.print(tempo);
}


protected:

  ST7735_t3 &_lcd;
  int _sck, _sdi;

  uint16_t _fgColour, _bgColour, _highlightColour;

};
#endif
