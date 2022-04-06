/**
   Encapsulate all the methods needed to draw on the screen
   screen is 320x240
*/
#ifndef BM_SCREEN_H
#define BM_SCREEN_H
#include <Adafruit_GFX.h>    // Core graphics library
//#include <ST7735_t3.h>    // Hardware-specific library
#include "Adafruit_ILI9341.h"
#include "Fonts/FreeMono9pt7b.h"

const char * labels[] = { "Volume", "Wet", "Dry", "Line", "Bass", "Treble" };
#define VOL 0
#define WET 1
#define DRY 2
#define LINE 3
#define BASS 4
#define TREBLE 5

#define BAR_TOP 16
#define BAR_LEFT 0
#define BAR_RIGHT 63
#define BAR_HEIGHT 12
#define BAR_GAP 12

#define FONT_HEIGHT 12
#define FONT_WIDTH 12

#define CHANNEL_TOP 200
#define CHANNEL_HEIGHT 20
#define CHANNEL_LEFT 4
#define CHANNEL_WIDTH 180
#define INSTRUMENT_SELECT_LEFT (40 + FONT_HEIGHT * 4)
#define INSTRUMENT_SELECT_TOP 180
#define INSTRUMENT_SELECT_WIDTH 180
#define INSTRUMENT_SELECT_HEIGHT 110
#define INSTRUMENT_SELECT_PADDING_LEFT 6
#define INSTRUMENT_SELECT_PADDING_TOP 4
#define SELECT_COLOUR 0x2222ff

class Screen {

  public:

    Screen(Adafruit_ILI9341 &lcd, int sck, int sdi) : _lcd(lcd), _sck(sck), _sdi(sdi), _fgColour(0xffff), _bgColour(0x0000), _highlightColour(0xffaaaa) {
    }

    void begin() {
      _lcd.setFont(&FreeMono9pt7b);
      _lcd.begin();
      _lcd.setRotation(2);
      _lcd.fillScreen(ILI9341_BLACK);
      delay(500);
    }

    void clearInstrumentSelect() {
      int bx =  CHANNEL_LEFT + 1 + FONT_HEIGHT + 1;
      int w = INSTRUMENT_SELECT_LEFT + INSTRUMENT_SELECT_WIDTH - bx;
      _lcd.fillRect(bx, INSTRUMENT_SELECT_TOP, w, INSTRUMENT_SELECT_HEIGHT, _bgColour);
    }

    void clearInstrumentSelectText() {
      _lcd.fillRect(INSTRUMENT_SELECT_LEFT + 2, INSTRUMENT_SELECT_TOP + 2, INSTRUMENT_SELECT_WIDTH - 4, INSTRUMENT_SELECT_HEIGHT - 4, _bgColour);
    }

    void drawInstrumentSelect(uint8_t channel) {
      clearInstrumentSelect();
      _lcd.drawRect(INSTRUMENT_SELECT_LEFT, INSTRUMENT_SELECT_TOP, INSTRUMENT_SELECT_WIDTH, INSTRUMENT_SELECT_HEIGHT, SELECT_COLOUR);
      _lcd.drawRect(INSTRUMENT_SELECT_LEFT + 1, INSTRUMENT_SELECT_TOP + 1, INSTRUMENT_SELECT_WIDTH - 2, INSTRUMENT_SELECT_HEIGHT - 2, SELECT_COLOUR);
      // Now draw the line connecting to the box
      int by = CHANNEL_TOP + (channel * CHANNEL_HEIGHT) + (FONT_HEIGHT >> 1) - 1;
      int bx = CHANNEL_LEFT + 1 + FONT_HEIGHT + 1;
      int dx = INSTRUMENT_SELECT_LEFT  - bx;
      _lcd.drawFastHLine(bx, by, dx, SELECT_COLOUR);
      _lcd.drawFastHLine(bx, by + 1, dx, SELECT_COLOUR);
    }

    void drawChannelBoxes(uint8_t selected) {
      uint32_t selectedColour = SELECT_COLOUR;

      int x = CHANNEL_LEFT;
      int y = CHANNEL_TOP;

      _lcd.fillRect(CHANNEL_LEFT, CHANNEL_TOP, FONT_WIDTH, 4 * CHANNEL_HEIGHT, _bgColour);

      return;

      // draw all the channel boxes, with the selected one highighted
      for (int i = 0; i < 4; i++) {
        for (int n = 0; n < 8; n++) {
          if (i == selected) {
            _lcd.fillRect(x + 1, y + (i * CHANNEL_HEIGHT), FONT_HEIGHT - 1, FONT_HEIGHT - 1, selectedColour);
          } else {
            _lcd.fillRect(x + 1, y + (i * CHANNEL_HEIGHT), FONT_HEIGHT - 1, FONT_HEIGHT - 1, _fgColour);
          }
          x += FONT_HEIGHT + 1;
        }
        x = CHANNEL_LEFT;
      }
    }

    void clearAllInstrumentText() {
      // clear the text area
      _lcd.fillRect(CHANNEL_LEFT + FONT_HEIGHT, CHANNEL_TOP, CHANNEL_WIDTH - FONT_HEIGHT, 4 * CHANNEL_HEIGHT, _bgColour);
    }

    void setupInstrumentChoices(uint8_t channel, const char * instruments[5])
    {

      clearInstrumentSelect();
      drawInstrumentSelect(channel);
      drawChannelBoxes(channel);
      printInstrumentChoices(instruments);
    }

    void printInstrumentChoices(const char * instruments[5]) {

      // Text for a channel is 180px wide, 12px tall with
      int x = INSTRUMENT_SELECT_LEFT + INSTRUMENT_SELECT_PADDING_LEFT;
      int y = INSTRUMENT_SELECT_TOP + INSTRUMENT_SELECT_PADDING_TOP + FONT_HEIGHT;

      for (int i = 0; i < 5; i++) {
        if (i == 2) {
          _lcd.setTextColor(_highlightColour);
        } else {
          _lcd.setTextColor(_fgColour);
        }
        _lcd.setCursor(x, y);
        _lcd.print(instruments[i]);
        y += FONT_HEIGHT + 2;
      }
    }

    void scrollInstrumentChoices(const char * instruments[5]) {
      clearInstrumentSelectText();
      printInstrumentChoices(instruments);
    }

    void printChannelInstrument(uint8_t channel, char *instrument) {
      //channel = 2;
      // Text for a channel is 180px wide, 12px tall with
      int x = CHANNEL_LEFT;
      int y = CHANNEL_TOP + (channel * CHANNEL_HEIGHT);
      int fy = y + FONT_HEIGHT - 1;
      int fx = x + (FONT_HEIGHT * 8);

      drawChannelBoxes(255);

      _lcd.fillRect(x, y, CHANNEL_WIDTH - FONT_HEIGHT, FONT_HEIGHT, _bgColour);
      _lcd.setTextColor(_fgColour);
      _lcd.setCursor(fx, fy);
      _lcd.print(instrument);
    }


    void drawVolumeBar(uint8_t volume) {
      drawControlBar(1, volume, labels[VOL]);
    }
    void drawBassWetBar(uint8_t volume) {
      drawControlBar(2, volume, labels[WET]);
    }
    void drawBassDryBar(uint8_t volume) {
      drawControlBar(3, volume, labels[DRY]);
    }
    void drawLineBar(uint8_t volume) {
      drawControlBar(4, volume, labels[LINE]);
    }
    void drawTrebleBar(uint8_t treble) {
      drawControlBar(5, treble << 4, labels[TREBLE]);
    }
    void drawBassBar(uint8_t bass) {
      drawControlBar(6, bass << 4, labels[BASS]);
    }

    void drawControlBar(uint8_t line, uint8_t value, const char *label) {
      // Volume bounding box is (0,5),(63,19)
      // Draw the full triangle
      int y = (line * (BAR_HEIGHT + BAR_GAP)) + BAR_TOP;
      int vx = (value * (BAR_RIGHT - BAR_LEFT)) / 255;

      if (_highlight) {
        _lcd.fillTriangle( BAR_LEFT,  y + BAR_HEIGHT, BAR_RIGHT,  y + BAR_HEIGHT,  BAR_RIGHT, y,  _highlightColour);
      } else {
        _lcd.fillTriangle( BAR_LEFT,  y + BAR_HEIGHT, BAR_RIGHT,  y + BAR_HEIGHT,  BAR_RIGHT, y,  _fgColour);
      }
      // now clip the end off as needed
      //(x,y,w,h)
      _lcd.fillRect(BAR_LEFT + vx,  y,  BAR_RIGHT - BAR_LEFT - vx,  BAR_HEIGHT + 1, _bgColour);

      // clear the text position and redraw it
      _lcd.fillRect(BAR_RIGHT, y, 128 - BAR_RIGHT, BAR_HEIGHT, _bgColour);
      if (_highlight) {
        _lcd.setTextColor(_highlightColour);
      } else {
        _lcd.setTextColor(_fgColour);
      }
      _lcd.setCursor(BAR_RIGHT + BAR_GAP, y + BAR_HEIGHT);
      _lcd.print(label);
    }

    void printTempo(uint8_t tempo) {
      _lcd.fillRect(70, 5, 70, 25, _bgColour);
      _lcd.setCursor(70, 15);
      _lcd.setTextColor(_highlightColour);
      _lcd.print(tempo);
    }

    void showRunning(bool running) {
      _lcd.fillRect(140, 5, 20, 20, _bgColour);
      if (running) {
        _lcd.fillTriangle( 140,  5, 140,  24,  159, 12,  _highlightColour);
      } else {
        _lcd.fillRect(140, 5, 20, 20, _highlightColour);
      }
    }

    void setHighlight(bool h) {
      _highlight = h;
    }


  protected:

    Adafruit_ILI9341 &_lcd;
    int _sck, _sdi;

    uint16_t _fgColour, _bgColour, _highlightColour = 0;

    bool _highlight = false;

};
#endif
