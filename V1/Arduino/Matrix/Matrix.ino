/**************************************************
 * Copyright 2021 Duncan McIntyre
 * MIDI Bass Guitar Toolbox
 *************************************************/

 /**
  * Volume:
  * Instrument: Allows selection of the instrument
  * Matrix: Starts to use the NeoTrellis to assign notes to beats
  *  : Uses the 2x2 keypad for function select
  */

#include <Arduino.h>
#include <TeensyThreads.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <ST7735_t3.h>    // Hardware-specific library
#include "Screen.h"
#include "VS1053.h"

#define ENCODER_USE_INTERRUPTS 
#include <Encoder.h>
#include <core_pins.h>

#include "Controls.h"
#include "TwoByTwo.h"
#include "Sequencer.h"
#include "NoteGrid.h"

//create a matrix of trellis panels
Adafruit_NeoTrellis t_array[1][2] = {
  
  { Adafruit_NeoTrellis(0x2E), Adafruit_NeoTrellis(0x2F) }
  
};

Adafruit_MultiTrellis trellis((Adafruit_NeoTrellis *)t_array, 1, 2);
NoteGrid noteGrid(trellis);

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
#define ENC_SEL_B 21

#define ENC_TEMPO_L 40
#define ENC_TEMPO_R 41
#define ENC_TEMPO_B 39

#define DP_CS 15
#define DP_CLK 16
#define DP_SDI 17
#define DP_MASTER_VOL 2

// The 2x2 Keypad
#define TR_R 1
#define TR_G 2
#define TR_B 3
#define TR_LG1 4
#define TR_LG2 5
#define TR_LG3 6
#define TR_LG4 7
#define TR_B1 33
#define TR_B2 34
#define TR_B3 35
#define TR_B4 36

#define VELOCITY_BUTTON 2
#define RUN_STOP_BUTTON 0


ST7735_t3 tft = ST7735_t3(SC_CS, SC_DC, SC_SDA, SC_SCL, SC_RESET);

VS1053 midi = VS1053(MP_CS, MP_DCS, MP_RESET, MP_SCK, MP_MOSI, MP_MISO);

Screen screen(tft, SC_SCL, SC_SDA);

MIDINote note = {true, 0,27,127, false};

Controls controls(ENC_VOL_L, ENC_VOL_R, ENC_SEL_L, ENC_SEL_R, ENC_SEL_B, ENC_TEMPO_L, ENC_TEMPO_R, ENC_TEMPO_B);

TwoByTwo twoByTwo(TR_R, TR_G, TR_B, TR_LG1, TR_LG2, TR_LG3, TR_LG4, TR_B1, TR_B2, TR_B3, TR_B4);

AD5204 pots(DP_CS, DP_CLK, DP_SDI);

Sequencer sequencer(27);

int mode = 0;

void leds_thread_func() {
  while(true) twoByTwo.updateLeds();
}

void volumeCallback(int volume) {
    setMasterVolume(volume);
}

void selectCallback(int sel) {
  if(mode == 0) {
    // ignore unless we're setting the voice for a line
    return;
  }
  if(sel < 27) {
    sel = 27;
    controls.setSelect(sel);
  } else if(sel > 87) {
    sel = 87;
    controls.setSelect(sel);
  }
  setVoice(sel);
}

void selectButtonCallback(int unused) {
  if(mode != 0) {
    mode = 0;
    updateMode();
  }
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

void tempoButtonCallback(int unused) {

}

void beatCallback(uint8_t beat) {
  noteGrid.beat(beat);
}

void noteOnCallback(uint8_t beat, MIDINote note) {
  midi.noteOn(note);
}

void noteOffCallback(uint8_t beat, MIDINote note) {
  midi.noteOff(note);
}

void voiceButtonCallback() {
  // press to select the voice for a channel
  mode++;
  if(mode > 4) mode = 0;

  updateMode();
}

void updateMode() {

  noteGrid.restoreLines();

  if(mode == 0) {
    twoByTwo.setButtonColour(VELOCITY_BUTTON, 0x00);
  } else {
    noteGrid.selectLine(mode - 1);
    controls.setSelect(sequencer.getVoice(mode - 1));
    showVoice(sequencer.getVoice(mode - 1));
  }
}

void runStopButtonCallback() {
  bool running = !sequencer.isRunning();
  sequencer.setRunning(running);
  screen.showRunning(running);
  if(running) {
    twoByTwo.setButtonColour(RUN_STOP_BUTTON, TBT_G);  
  } else {
    twoByTwo.setButtonColour(RUN_STOP_BUTTON, TBT_R+TBT_B);  
  }
}


void setup() {
  
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

IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_01 = (IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_01 & 0b1111111111000110) | 0x0008;
IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_00 = (IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_00  & 0b1111111111000110) | 0x0008;

  
  Serial.begin(9600);
  if(!trellis.begin()){
    Serial.println("failed to begin trellis");
    while(1);
  }
  
  controls.attachVolumeCallback(volumeCallback);
  controls.attachSelectCallback(selectCallback);
  controls.attachSelectButtonCallback(selectButtonCallback);
  controls.attachTempoCallback(tempoCallback);
  //controls.attachTempoButtonCallback(tempoButtonCallback);
  controls.setVolume(127);
  setMasterVolume(127);
  
  midi.setBank(0, MIDI_BANK_PERCUSSION);
  midi.setInstrument(0, 27);
  selectCallback(27);

  sequencer.attachNoteOnCallback(noteOnCallback);
  sequencer.attachNoteOffCallback(noteOffCallback);
  sequencer.attachBeatCallback(beatCallback);

  controls.setTempo(70);
  setTempo(70);

  twoByTwo.setButtonColour(0, 1);
  twoByTwo.setButtonColour(1, 3);
  twoByTwo.setButtonColour(2, 5);
  twoByTwo.setButtonColour(3, 7);
  twoByTwo.attachB1Callback(voiceButtonCallback);
  twoByTwo.attachB2Callback(runStopButtonCallback);

  threads.setSliceMicros(10);
  threads.addThread(leds_thread_func, 1);

  noteGrid.attachKeyPressCallback(noteGridKeyPressCallback);
  noteGrid.begin();
}

void loop() {
  sequencer.tick();
  noteGrid.tick();
  trellis.read();
  controls.update();
  twoByTwo.update();
}

void setVoice(uint8_t voice) {
 sequencer.setVoice(mode-1,voice);
 showVoice(voice);
}

void showVoice(uint8_t voice) {
  char * names[5];
  for(int i=-2; i < 3; i++) {
    names[i+2] = midi.getInstrumentName(voice+i);
  }
  screen.printInstrumentNames(names);
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
  sequencer.setTempo(tempo);
  screen.printTempo(tempo);
}

TrellisCallback noteGridKeyPressCallback(keyEvent e) {

  // Ignore keypresses if not in mode 0
  if(mode != 0) {
    return 0;
  }
    
  if(e.bit.EDGE == SEESAW_KEYPAD_EDGE_FALLING) {
    
    int x = e.bit.NUM % 8;
    int y = e.bit.NUM / 8;

    if(sequencer.toggle(x, y)) {
      noteGrid.setActive(x,y);
    } else {
      noteGrid.setInactive(x,y);
    }
  }
  return 0;
}
