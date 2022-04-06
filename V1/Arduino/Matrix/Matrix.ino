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

#include "EncoderButton.h"
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
#define ENC_VOL_B 32

#define ENC_FN_L 22
#define ENC_FN_R 23
#define ENC_FN_B 21

#define ENC_TEMPO_L 40
#define ENC_TEMPO_R 41
#define ENC_TEMPO_B 39

#define ENC_TONE_L 38
#define ENC_TONE_R 37 
#define ENC_TONE_B 14

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

#define VOICE_BUTTON 2
#define VELOCITY_BUTTON 3
#define RUN_STOP_BUTTON 0
#define EFFECTS_BUTTON 1

#define RUNSTOP_STOPPED_COLOUR TR_R
#define RUNSTOP_PAUSED_COLOUR (TR_R + TR_G)
#define RUNSTOP_RUNNING_COLOUR TR_G

ST7735_t3 tft = ST7735_t3(SC_CS, SC_DC, SC_SDA, SC_SCL, SC_RESET);

VS1053 midi = VS1053(MP_CS, MP_DCS, MP_RESET, MP_SCK, MP_MOSI, MP_MISO);

Screen screen(tft, SC_SCL, SC_SDA);

MIDINote note = {true, 0,27,127, false};

EncoderButton volumeControl(ENC_VOL_L, ENC_VOL_R, ENC_VOL_B);
EncoderButton toneControl(ENC_TONE_L, ENC_TONE_R, ENC_TONE_B);
EncoderButton tempoControl(ENC_TEMPO_L, ENC_TEMPO_R, ENC_TEMPO_B);
EncoderButton functionControl(ENC_FN_L, ENC_FN_R, ENC_FN_B);

TwoByTwo twoByTwo(TR_R, TR_G, TR_B, TR_LG1, TR_LG2, TR_LG3, TR_LG4, TR_B1, TR_B2, TR_B3, TR_B4);

AD5204 pots(DP_CS, DP_CLK, DP_SDI);

Sequencer sequencer(27);

#define MODE_DEFAULT 0
#define MODE_SELECT_VOICE 1
#define MODE_SELECT_VELOCITY 2

int mode = MODE_DEFAULT;

// 0 means no line. Lines are numbered 1 - 4
int selectedLine = 0;
uint8_t selectedNoteX = 0;
uint8_t selectedNoteY = 0;


void leds_thread_func() {
  while(true) twoByTwo.updateLeds();
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

void noteGridEventHandler(keyEvent e) {
 noteGrid.handleEvent(e);
}

void volumeEncoderCallback(int volume) {
    if(mode == MODE_SELECT_VELOCITY) {
      note.velocity = volume;
      sequencer.setNoteVolume(selectedNoteX, selectedNoteY, volume);
      pots.write(DP_MASTER_VOL,volume);
      screen.drawVolumeBar(volume); 
    } else {
      setMasterVolume(volume);
    }
}

void volumeEncoderButtonCallback() {
  midi.noteOn(note);
}

void toneEncoderCallback(int sel) {
  if(mode == MODE_DEFAULT) {
    return;
  }

  if(mode == MODE_SELECT_VOICE) {
    if(sel < 27) {
      sel = 27;
      toneControl.setValue(sel);
    } else if(sel > 87) {
      sel = 87;
      toneControl.setValue(sel);
    }
    setVoice(sel);
  }
}

void toneEncoderButtonCallback() {
  switch(mode) {
    case MODE_DEFAULT:
      // nothing to do
      break;
    case MODE_SELECT_VOICE:
      // set the chosen voice
      setVoice(toneControl.getValue());
      break;
    default:
      // do nothing
      break;
  }
}

void tempoEncoderCallback(int tempo) {
  if(tempo < 20) {
    tempo = 20;
    tempoControl.setValue(tempo);
  } else if(tempo > 200) {
    tempo = 200;
    tempoControl.setValue(tempo);
  }
  setTempo(tempo);
}

void tempoEncoderButtonCallback() {
  noteGrid.setFlashBeat(!noteGrid.getFlashBeat());
}

void toneButtonCallback() {
  if(mode == MODE_DEFAULT) {
    selectedLine = 0;
    mode = MODE_SELECT_VOICE;
  }
  // press to select the voice for a channel
  selectedLine++;
  
  if(selectedLine > 4) {
    mode = MODE_DEFAULT;
  }
  updateMode();
}

void toneButtonLongCallback() {
  mode = MODE_DEFAULT;
  updateMode();
}

void updateMode() {

  noteGrid.restoreLines();

  if(mode == MODE_DEFAULT) {
    
    twoByTwo.setButtonColour(VOICE_BUTTON, 0x00);
    twoByTwo.setButtonColour(VELOCITY_BUTTON, 0x00);
    
  } else if(mode == MODE_SELECT_VOICE) {
    
    twoByTwo.setButtonColour(VOICE_BUTTON, TBT_B);
    noteGrid.selectLine(selectedLine - 1);
    toneControl.setValue(sequencer.getVoice(selectedLine - 1));
    showVoice(sequencer.getVoice(selectedLine - 1));
    
  } else if(mode == MODE_SELECT_VELOCITY) {
    
    twoByTwo.setButtonColour(VELOCITY_BUTTON, TBT_R+TBT_B);
    
  }
}

void runStopButtonCallback() {
  bool running = !sequencer.isRunning();
  sequencer.setRunning(running);
  screen.showRunning(running);
  if(running) {
    twoByTwo.setButtonColour(RUN_STOP_BUTTON, RUNSTOP_RUNNING_COLOUR);  
  } else {
    twoByTwo.setButtonColour(RUN_STOP_BUTTON, RUNSTOP_PAUSED_COLOUR);  
    noteGrid.showPausedBeat(sequencer.getBeat());
  }
}

void runStopButtonLongCallback() {
  sequencer.reset();
  screen.showRunning(false);
  twoByTwo.setButtonColour(RUN_STOP_BUTTON, RUNSTOP_STOPPED_COLOUR);  
}

/**
 * Normal keypress toggles the channels voice on or off at the beat
 * In velocity mode it just rverts to normal mode
 */
void noteGridKeyPressCallback(uint8_t x, uint8_t y) {

  // Ignore keypresses if not in mode 0
  if(mode == 0) {
    if(sequencer.toggle(x, y)) {
      noteGrid.setActive(x,y);
    } else {
      noteGrid.setInactive(x,y);
    }
  } else if(mode == MODE_SELECT_VELOCITY) {
    mode = MODE_DEFAULT;
    noteGrid.cancelBlink();
    updateMode();    
  }
}

/**
 * A long press in normal mode turns on velocity mode
 * The volume knob now controls the velocity at this beat
 * A press on the velocity button tests it
 * A further short press on the beat reverts to normal mode
 */
void noteGridKeyLongPressCallback(uint8_t x, uint8_t y) {

  if(mode == MODE_DEFAULT) {
    
    mode = MODE_SELECT_VELOCITY;
    
    // turn on this beat
    sequencer.setActive(x, y);
    noteGrid.setActive(x,y);
    noteGrid.blink(x,y);
    updateMode();
    selectedNoteX = x;
    selectedNoteY = y;
    
  } else if(mode == MODE_SELECT_VELOCITY) {
    mode = MODE_DEFAULT;
    noteGrid.cancelBlink();
    updateMode();    
  }
}

void cancelVelocityCallback() {
  if(mode == MODE_SELECT_VELOCITY) {
    mode = MODE_DEFAULT;
    noteGrid.cancelBlink();
    updateMode();    
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
  Serial.println("startup");  
  volumeControl.setStep(5);
  
  volumeControl.attachEncoderCallback(volumeEncoderCallback);
  volumeControl.attachButtonCallback(volumeEncoderButtonCallback);
  volumeControl.setValue(127);
  setMasterVolume(127);
   
  toneControl.attachEncoderCallback(toneEncoderCallback);
  toneControl.attachButtonCallback(toneEncoderButtonCallback);
  
  tempoControl.attachEncoderCallback(tempoEncoderCallback);
  tempoControl.attachButtonCallback(tempoEncoderButtonCallback);

  midi.setBank(0, MIDI_BANK_PERCUSSION);
  midi.setInstrument(0, 27);
  toneControl.setValue(27);
  setVoice(27);

  sequencer.attachNoteOnCallback(noteOnCallback);
  sequencer.attachNoteOffCallback(noteOffCallback);
  sequencer.attachBeatCallback(beatCallback);

  tempoControl.setValue(70);
  setTempo(70);

  twoByTwo.setButtonColour(VOICE_BUTTON, 0);
  twoByTwo.setButtonColour(VELOCITY_BUTTON, 0);
  twoByTwo.setButtonColour(RUN_STOP_BUTTON, RUNSTOP_STOPPED_COLOUR);
  twoByTwo.setButtonColour(EFFECTS_BUTTON, 0);
  twoByTwo.attachB1Callback(toneButtonCallback);
  twoByTwo.attachB1LongPressCallback(toneButtonLongCallback);
  twoByTwo.attachB2Callback(runStopButtonCallback);
  twoByTwo.attachB2LongPressCallback(runStopButtonLongCallback);
  twoByTwo.attachB3Callback(cancelVelocityCallback);

  threads.setSliceMicros(10);
  threads.addThread(leds_thread_func, 1);

  noteGrid.attachEventHandler(noteGridEventHandler);
  noteGrid.attachKeyPressCallback(noteGridKeyPressCallback);
  noteGrid.attachKeyLongPressCallback(noteGridKeyLongPressCallback);
  noteGrid.begin();
}

void loop() {
  sequencer.tick();
  noteGrid.tick();
  volumeControl.update();
  toneControl.update();
  tempoControl.update();
  functionControl.update();
  twoByTwo.update();
}

void setVoice(uint8_t voice) {
 sequencer.setVoice(selectedLine-1,voice);
 showVoice(voice);
 note.note = voice;
 midi.noteOn(note);
}

void showVoice(uint8_t voice) {
  const char * names[5];
  for(int i=-2; i < 3; i++) {
    names[i+2] = midi.getInstrumentName(voice+i);
  }
  screen.printInstrumentNames(names);
}

void setMasterVolume(uint8_t volume) {
   // pots.write(DP_MASTER_VOL,volume);
    screen.drawVolumeBar(volume); 
    midi.setVolume(0,volume >> 1);
   // if(volume == 0) {
  //    midi.setVolume(0,0); 
   // } else {
   //   midi.setVolume(0,127);
   // }
}

void setTempo(int tempo) {
  sequencer.setTempo(tempo);
  screen.printTempo(tempo);
}
