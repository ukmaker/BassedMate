/**************************************************
 * Copyright 2021 Duncan McIntyre
 * MIDI Bass Guitar Toolbox
 *************************************************/

 /**
  * Implement a basic volume control to allow testing output filtering
  * Show a simple volum bar on the screen
  * Volume control is an encoder producing interrupts
  */

#include <Arduino.h>

#include <Adafruit_GFX.h>    // Core graphics library
#include <ST7735_t3.h>    // Hardware-specific library
#include "VS1053.h"
#include <Encoder.h>

/**
 * Screen is an ST7735 based 1.8" screen without touch
 */
#define SC_SCL 27
#define SC_SDA 26
#define SC_CS 0
#define SC_DC 28
#define SC_RESET 29

/**
 * Music player is a VS1053 basic breakout board
 */
#define MP_MOSI 11
#define MP_MISO 12
#define MP_SCK 13
#define MP_CS 25
#define MP_DCS 25
#define MP_DREQ UNUSED
#define MP_RESET 24

#define VOL_L 30
#define VOL_R 31

ST7735_t3 tft = ST7735_t3(SC_CS, SC_DC, SC_SDA, SC_SCL, SC_RESET);

VS1053 midi = VS1053(MP_CS);

MIDINote note = {0,80,127};

Encoder volumeKnob(VOL_L, VOL_R);
long volume = 127;

uint8_t voice = 0;
uint32_t ticks = 0;

void setup() {

   Serial.begin(9600);
   pinMode(MP_MOSI, OUTPUT);
   pinMode(MP_MISO, INPUT);
   pinMode(MP_RESET, OUTPUT);
   pinMode(MP_SCK, OUTPUT);
   pinMode(MP_CS, OUTPUT);

  digitalWrite(MP_CS, HIGH);
  digitalWrite(MP_RESET, LOW);
  delay(10);
  digitalWrite(MP_RESET, HIGH); 
  SPI.begin ();
  SPI.setBitOrder(MSBFIRST);
  midi.enableMIDI();
  midi.setVolume(0,127);
  
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  uint16_t time = millis();
  tft.fillScreen(ST7735_BLACK);
  time = millis() - time;
  delay(500);

  // large block of text
  tft.fillScreen(ST7735_BLACK);
  testdrawtext("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", ST7735_WHITE);
  delay(1000);

}

void loop() {

  long t = millis();
  long newVol = volumeKnob.readAndReset();
  if(newVol != 0) {
    volume += newVol;
    if(volume < 0) {
      volume = 0;
    } else if(volume > 127) {
      volume = 127;
    }
    midi.setVolume(0, volume);
    drawVolumeBar(volume);
  }

  if(t - ticks > 1000) {
    midi.noteOn(note);
    ticks = t;
  }
}

void testdrawtext(const char *text, uint16_t color) {
  tft.setCursor(0, 0);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}

void drawVolumeBar(uint8_t volume) {
  // Volume bounding box is (0,5),(63,19)
  // Draw the full triangle 
  tft.fillTriangle( 0,  19, 63,  19,  63, 5,  0xf0a0);
  // now clip the end off as needed
  tft.fillRect( volume / 2,  5,  63,  19, 0x0000);
}
