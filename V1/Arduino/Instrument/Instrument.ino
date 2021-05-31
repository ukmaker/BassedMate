/**************************************************
 * Copyright 2021 Duncan McIntyre
 * MIDI Bass Guitar Toolbox
 *************************************************/

 /**
  * Volume:
  * Instrument: Allows selection of the instrument
  */

#include <Arduino.h>

#include <Adafruit_GFX.h>    // Core graphics library
#include <ST7735_t3.h>    // Hardware-specific library
#include "Screen.h"
#include "VS1053.h"

#define ENCODER_USE_INTERRUPTS 
#include <Encoder.h>
#include <core_pins.h>

#include "Controls.h"

#include "AD5204.h"
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
#define MP_DCS 10
#define MP_DREQ UNUSED
#define MP_RESET 24

#define ENC_VOL_L 30
#define ENC_VOL_R 31

#define ENC_SEL_L 22
#define ENC_SEL_R 23

#define ENC_TEMPO_L 40
#define ENC_TEMPO_R 41

#define DP_CS 15
#define DP_CLK 16
#define DP_SDI 17
#define DP_MASTER_VOL 2

ST7735_t3 tft = ST7735_t3(SC_CS, SC_DC, SC_SDA, SC_SCL, SC_RESET);

VS1053 midi = VS1053(MP_CS, MP_DCS, MP_RESET, MP_SCK, MP_MOSI, MP_MISO);

Screen screen(tft, SC_SCL, SC_SDA);

MIDINote note = {0,27,127};

Controls controls(ENC_VOL_L, ENC_VOL_R, ENC_SEL_L, ENC_SEL_R, ENC_TEMPO_L, ENC_TEMPO_R);

AD5204 pots(DP_CS, DP_CLK, DP_SDI);

long voice = 27;
uint32_t ticks = 0;
uint32_t millisPerBeat = 1000;

void volumeCallback(int volume) {
    setMasterVolume(volume);
}

void selectCallback(int sel) {
  if(sel < 27) {
    sel = 27;
    controls.setSelect(sel);
  } else if(sel > 87) {
    sel = 87;
    controls.setSelect(sel);
  }
  setVoice(sel);
}

void tempoCallback(int tempo) {
  if(tempo < 20) {
    tempo = 20;
    controls.setTempo(tempo);
  } else if(tempo > 200) {
    tempo = 200;
    controls.setTempo(tempo);
  }
  setTempo(tempo);
}


void setup() {
  
  Serial.begin(9600);

  controls.attachVolumeCallback(volumeCallback);
  controls.attachSelectCallback(selectCallback);
  controls.attachTempoCallback(tempoCallback);

  // Set the slew rate to minimum for reliable operation
  // Otherwise it looks like ringing on the DCS line causes false writes to the SDI registers
  // MP_DCS 10
  IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_00 = (IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_00 & 0b1111111111000110) | 0x0008;
  // MP_MOSI 11
  IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_02 = (IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_02 & 0b1111111111000110) | 0x0008;
  // MP_SCK 13
  IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_03 = (IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_03 & 0b1111111111000110) | 0x0008;
  // MP_CS 25
  IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_13 = (IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_13 & 0b1111111111000110) | 0x0008;

  controls.setVolume(127);
  setMasterVolume(127);
  
  midi.setBank(0, MIDI_BANK_PERCUSSION);
  midi.setInstrument(0, 27);
  selectCallback(27);

  controls.setTempo(70);
  setTempo(70);
}

void loop() {
      
  long t = millis();
  if((t - ticks) > millisPerBeat) {
   // midi.noteOff(note);
    midi.noteOn(note);
    ticks = t;
  }

  controls.update();
}

void setVoice(uint8_t voice) {
  note.note = voice;

  char * names[5];
  for(int i=-2; i < 3; i++) {
    names[i+2] = midi.getInstrumentName(voice+i);
  }
  screen.printInstrumentNames( names, 10, 30);
}

void setMasterVolume(uint8_t volume) {
    pots.write(DP_MASTER_VOL,volume);
    screen.drawVolumeBar(volume); 
    if(volume == 0) {
      midi.setVolume(0,0); 
    } else {
      midi.setVolume(0,127);
    }
}

void setTempo(int tempo) {
  // tempo range is 20 - 200 BPM
  // millis per beat (bpm / 60 * 1000
  millisPerBeat = 60000 / tempo;
  screen.printTempo(tempo);
}
