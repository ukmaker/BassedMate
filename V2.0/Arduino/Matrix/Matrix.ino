 /**************************************************
   Copyright 2021 Duncan McIntyre
   MIDI Bass Guitar Toolbox
 *************************************************/

/**
   V1.1

   Shared SPI bus
   Power on/off
   Adafruit VS1053 Breakout with RX/TX
*/

#include <Arduino.h>

#include "Instruments.h"
#include "Sequencer.h"
#include "InstrumentSelector.h"

#include <TeensyThreads.h>
#include <Adafruit_GFX.h>    // Core graphics library
//#include <ST7735_t3.h>    // Hardware-specific library
#include "Adafruit_ILI9341.h"
#include "Screen.h"
#include "VS1053.h"
#include "Mixer.h"
#include "SPI.h"


#define ENCODER_USE_INTERRUPTS
//#include <Encoder.h>
#include <core_pins.h>

#include "RotaryButton.h"
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
   Screen is an ST7735 based 1.8" screen without touch
*/
#define SC_SCL 27
#define SC_SDA 26
#define SC_CS 30
#define SC_DC 29
#define SC_RESET 28

/**
   Music player is a VS1053 basic breakout board
*/
#define MP_MOSI 26
#define MP_MISO 1
#define MP_SCK 27
#define MP_CS 32
#define MP_DCS 31
#define MP_DREQ UNUSED
#define MP_RESET 0

#define ENC_VOL_L 17
#define ENC_VOL_R 16
#define ENC_VOL_B 15

#define ENC_FN_L 38
#define ENC_FN_R 37
#define ENC_FN_B 36

#define ENC_TEMPO_L 41
#define ENC_TEMPO_R 40
#define ENC_TEMPO_B 39

#define ENC_TONE_L 23
#define ENC_TONE_R 22
#define ENC_TONE_B 21

#define DP_CS 33
#define DP_CLK 27
#define DP_SDI 26

// The 2x2 Keypad
#define TR_R 2
#define TR_G 3
#define TR_B 4
#define TR_LG1 7
#define TR_LG2 8
#define TR_LG3 6
#define TR_LG4 5
#define TR_B1 9
#define TR_B2 10
#define TR_B3 11
#define TR_B4 12

#define VOICE_BUTTON 0
#define VELOCITY_BUTTON 2
#define RUN_STOP_BUTTON 1
#define POWER_BUTTON 3

#define RUNSTOP_STOPPED_COLOUR TBT_R
#define RUNSTOP_PAUSED_COLOUR (TBT_R + TBT_G)
#define RUNSTOP_RUNNING_COLOUR TBT_G
#define POWER_ON_COLOUR (TBT_R + TBT_G + TBT_B)

#define BATTERY_ENABLE 13
#define USB_POWER 24
#define HEADPHONE 14

Adafruit_ILI9341 tft = Adafruit_ILI9341(&SPI1, SC_DC, SC_CS, SC_RESET);

AD5204 pots(DP_CS);

Screen screen(tft, SC_SCL, SC_SDA);

VS1053 midi = VS1053(MP_CS, MP_DCS, MP_RESET, MP_SCK, MP_MOSI, MP_MISO);
Mixer mixer(pots, midi);

RotaryButton volumeControl(ENC_VOL_L, ENC_VOL_R, ENC_VOL_B);
RotaryButton toneControl(ENC_TONE_L, ENC_TONE_R, ENC_TONE_B);
RotaryButton tempoControl(ENC_TEMPO_L, ENC_TEMPO_R, ENC_TEMPO_B);
RotaryButton functionControl(ENC_FN_L, ENC_FN_R, ENC_FN_B);

TwoByTwo twoByTwo(TR_R, TR_G, TR_B, TR_LG1, TR_LG2, TR_LG3, TR_LG4, TR_B1, TR_B2, TR_B3, TR_B4);
Sequencer sequencer;
InstrumentSelector instrumentSelector(&sequencer, &screen, AllInstruments);

#define MODE_DEFAULT 0
#define MODE_SELECT_VOICE 1
#define MODE_SELECT_VELOCITY 2
#define MODE_MIXER 3

#define TONE_MODE_TREBLE 0
#define TONE_MODE_BASS 1

#define MIXER_MODE_VOLUME 0
#define MIXER_MODE_BASS_WET 1
#define MIXER_MODE_BASS_DRY 2
#define MIXER_MODE_AUX 3

int mode = MODE_DEFAULT;
int toneMode = TONE_MODE_TREBLE;
int mixerMode = MIXER_MODE_VOLUME;

// 0 means no line. Lines are numbered 1 - 4
int selectedLine = 0;
uint8_t selectedNoteX = 0;
uint8_t selectedNoteY = 0;

boolean poweredOn = false;

void leds_thread_func() {
  while (true) twoByTwo.updateLeds();
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
  if (mode == MODE_SELECT_VELOCITY) {
    sequencer.setNoteVolume(selectedNoteX, selectedNoteY, volume);
    screen.drawVolumeBar(volume);
  } else {
    setVolume(volume);
  }
}

void volumeEncoderButtonCallback() {
  int volume;

  deselectVolumes();

  if (mode == MODE_DEFAULT) {
    mode = MODE_MIXER;
    mixerMode = MIXER_MODE_BASS_WET;
    volume = mixer.getBassWetLevel();
    setVolume(volume);
  } else if (mode == MODE_MIXER) {

    switch (mixerMode) {
      case MIXER_MODE_BASS_WET:
        mixerMode = MIXER_MODE_BASS_DRY;
        volume = mixer.getBassDryLevel();
        break;
      case MIXER_MODE_BASS_DRY:
        mixerMode = MIXER_MODE_AUX;
        volume = mixer.getLineLevel();
        break;
      default:
        mode = MODE_DEFAULT;
        mixerMode = MIXER_MODE_VOLUME;
        volume = mixer.getVolumeLevel();
        break;
    }
    setVolume(volume);
  }
}

void deselectVolumes() {
  screen.setHighlight(false);
  screen.drawVolumeBar(mixer.getVolumeLevel());
  screen.drawBassWetBar(mixer.getBassWetLevel());
  screen.drawBassDryBar(mixer.getBassDryLevel());
  screen.drawLineBar(mixer.getLineLevel());
  screen.setHighlight(true);
}

void volumeEncoderButtonLongCallback() {
  mode = MODE_DEFAULT;
}

void toneEncoderCallback(int sel) {

  if (mode == MODE_DEFAULT) {
    if (sel > 15) {
      sel = 15;
      toneControl.setValue(sel);
    }
    if (toneMode == TONE_MODE_TREBLE) {
      setTreble(sel);
    } else {
      setBass(sel);
    }
    return;
  }

  if (mode == MODE_SELECT_VOICE) {
    instrumentSelector.select(sel);
  }
}

void setVolume(uint8_t volume) {
  volumeControl.setValue(volume);
  switch (mixerMode) {
    case MIXER_MODE_VOLUME:
      setVolumeLevel(volume);
      break;
    case MIXER_MODE_BASS_WET:
      setBassWetLevel(volume);
      break;
    case MIXER_MODE_BASS_DRY:
      setBassDryLevel(volume);
      break;
    case MIXER_MODE_AUX:
      setLineLevel(volume);
      break;
    default:
      break;
  }
}

void setVolumeLevel(uint8_t volume) {
  mixer.setVolumeLevel(volume);
  screen.drawVolumeBar(volume);
}

void setBassWetLevel(uint8_t volume) {
  mixer.setBassWetLevel(volume);
  screen.drawBassWetBar(volume);
}

void setBassDryLevel(uint8_t volume) {
  mixer.setBassDryLevel(volume);
  screen.drawBassDryBar(volume);
}

void setLineLevel(uint8_t volume) {
  mixer.setLineLevel(volume);
  screen.drawLineBar(volume);
}

void deselectTones() {
  screen.setHighlight(false);
  screen.drawBassBar(midi.getBass());
  screen.drawTrebleBar(midi.getTreble());
  screen.setHighlight(true);
}

void setTreble(int v) {
  screen.drawTrebleBar(v);
  midi.setTreble(v);
}
void setBass(int v) {
  screen.drawBassBar(v);
  midi.setBass(v);
}

void toneEncoderButtonCallback() {
  switch (mode) {
    case MODE_DEFAULT:
      deselectTones();
      if (toneMode == TONE_MODE_TREBLE) {
        setBass(midi.getBass());
        toneControl.setValue(midi.getBass());
        toneControl.setLimits(0, 15);
        toneMode = TONE_MODE_BASS;
      } else {
        setTreble(midi.getTreble());
        toneControl.setValue(midi.getTreble());
        toneControl.setLimits(0, 15);
        toneMode = TONE_MODE_TREBLE;
      }
      break;
    case MODE_SELECT_VOICE:
      // play the chosen voice
      instrumentSelector.playSelection();
      // replace the previous voice in this line
      sequencer.setInstrument(instrumentSelector.getChannel(), instrumentSelector.getSelectedInstrument());
      midi.setInstrument(instrumentSelector.getChannel(), instrumentSelector.getSelectedInstrument().voice.id);
      break;
    default:
      // do nothing
      break;
  }
}

void setTempo(int tempo) {
  sequencer.setTempo(tempo);
  screen.printTempo(tempo);
}

void tempoEncoderCallback(int tempo) {
  if (tempo < 20) {
    tempo = 20;
    tempoControl.setValue(tempo);
  } else if (tempo > 200) {
    tempo = 200;
    tempoControl.setValue(tempo);
  }
  setTempo(tempo);
}

void tempoEncoderButtonCallback() {
  //noteGrid.setFlashBeat(!noteGrid.getFlashBeat());
}

void toneButtonCallback() {
  Serial.println("TB CB");
  if (mode == MODE_DEFAULT) {

    setMode(MODE_SELECT_VOICE);

  } else if (mode == MODE_SELECT_VOICE) {

    uint8_t channel = instrumentSelector.getChannel();

    // Now move to the next channel
    if (channel < 3) {
      noteGrid.restoreLine(channel);
      noteGrid.selectLine(channel+1);
      instrumentSelector.setChannel(channel + 1);
      instrumentSelector.showInstrumentSelection();
      instrumentSelector.playSelection();
      toneControl.setLimits(0, instrumentSelector.getNumVoices() - 1);
    } else {
      setMode(MODE_DEFAULT);
    }
  }
}

void toneButtonLongCallback() {
  setMode(MODE_DEFAULT);
}

void transitionMode(uint8_t from, uint8_t to) {
  if(mode == from) setMode(to);
}

void setMode(uint8_t m) {

  // If there's no mode transition, do nothing
  if (m == mode) {
    return;
  }

  // restore everything
  setDefaultMode();
  mode = m;

  switch (mode) {
    case MODE_SELECT_VOICE:
      instrumentSelector.setChannel(0);
      twoByTwo.setButtonColour(VOICE_BUTTON, TBT_B);
      noteGrid.selectLine(0);
      toneControl.setValue(instrumentSelector.getIndex());
      toneControl.setLimits(0, instrumentSelector.getNumVoices() - 1);
      instrumentSelector.showInstrumentSelection();
      break;

    case MODE_SELECT_VELOCITY:
      twoByTwo.setButtonColour(VELOCITY_BUTTON, TBT_R + TBT_B);
      break;

    default:
    case MODE_DEFAULT:
      // nothing left to do
      break;

  }
}

void setDefaultMode() {
  mode = MODE_DEFAULT;
  noteGrid.cancelBlink();
  noteGrid.restoreLines();
  twoByTwo.setButtonColour(VOICE_BUTTON, 0x00);
  twoByTwo.setButtonColour(VELOCITY_BUTTON, 0x00);
  displayChannelInstruments();
  screen.showRunning(sequencer.isRunning());
  toneControl.setLimits(0,255);
}


void displayChannelInstruments() {
  screen.clearInstrumentSelect();
  for (uint8_t channel = 0; channel < 4; channel++) {
    screen.printChannelInstrument(channel, sequencer.getInstrument(channel).voice.name);
  }
}

void setChannelDefaults() {
  sequencer.setInstrument(0, drumsCollection.getDefaultInstrument());
  sequencer.setInstrument(1, cymbalsCollection.getDefaultInstrument());
  sequencer.setInstrument(2, woodsCollection.getDefaultInstrument());
  sequencer.setInstrument(3, specialsCollection.getDefaultInstrument());
}

void runStopButtonCallback() {
  bool running = !sequencer.isRunning();
  sequencer.setRunning(running);
  screen.showRunning(running);
  if (running) {
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
   Normal keypress toggles the channels voice on or off at the beat
   In velocity mode it just rverts to normal mode
*/
void noteGridKeyPressCallback(uint8_t x, uint8_t y) {

  // Ignore keypresses if not in mode 0
  if (mode == MODE_DEFAULT || mode == MODE_MIXER) {
    if (sequencer.toggle(x, y)) {
      noteGrid.setActive(x, y);
    } else {
      noteGrid.setInactive(x, y);
    }
  } else if (mode == MODE_SELECT_VELOCITY) {
    noteGrid.cancelBlink();
    setMode(MODE_DEFAULT);
  }
}

/**
   A long press in normal mode turns on velocity mode
   The volume knob now controls the velocity at this beat
   A press on the velocity button tests it
   A further short press on the beat reverts to normal mode
*/
void noteGridKeyLongPressCallback(uint8_t x, uint8_t y) {

  if (mode == MODE_DEFAULT) {

    setMode(MODE_SELECT_VELOCITY);

    // turn on this beat
    sequencer.setActive(x, y);
    noteGrid.setActive(x, y);
    noteGrid.blink(x, y);
    selectedNoteX = x;
    selectedNoteY = y;

  } else if (mode == MODE_SELECT_VELOCITY) {
    noteGrid.cancelBlink();
    setMode(MODE_DEFAULT);
  }
}

void cancelVelocityCallback() {
  transitionMode(MODE_SELECT_VELOCITY, MODE_DEFAULT);
}

void powerButtonReleasedCallback() {
  twoByTwo.attachLongPressCallback(POWER_BUTTON, powerButtonCallback);
}

void powerButtonCallback() {
  if (poweredOn) {
    twoByTwo.setButtonColour(POWER_BUTTON, TBT_R);
    digitalWrite(BATTERY_ENABLE, LOW);
  } else {
    twoByTwo.setButtonColour(POWER_BUTTON, POWER_ON_COLOUR);
    if (!digitalRead(USB_POWER)) {
      digitalWrite(BATTERY_ENABLE, HIGH);
    }
  }

  poweredOn = !poweredOn;
}

void setup() {

  poweredOn = true;

  pinMode(USB_POWER, INPUT);
  pinMode(BATTERY_ENABLE, OUTPUT);
  delay(10);
  if (!digitalRead(USB_POWER)) {
    digitalWrite(BATTERY_ENABLE, HIGH);
  }

  pinMode(35, OUTPUT);

  // Set the slew rate to minimum for reliable operation
  // Otherwise it looks like ringing on the DCS line causes false writes to the SDI registers
  // MP_DCS 31
  IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_36 = (IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_36 & 0b1111111111000110) | 0x0008;
  // MP_MOSI 26
  IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_14 = (IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_14 & 0b1111111111000110) | 0x0008;
  // MP_SCK 27
  IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_15 = (IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_15 & 0b1111111111000110) | 0x0008;
  // MP_CS 32
  IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_12 = (IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_12 & 0b1111111111000110) | 0x0008;

  // sda 18
  IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_01 = (IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_01 & 0b1111111111000110) | 0x0008;
  // scl 19
  IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_00 = (IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_00  & 0b1111111111000110) | 0x0008;



  pinMode(MP_MOSI, OUTPUT);
  pinMode(MP_MISO, INPUT);
  pinMode(MP_RESET, OUTPUT);
  pinMode(MP_SCK, OUTPUT);
  pinMode(MP_CS, OUTPUT);
  pinMode(MP_DCS, OUTPUT);
  digitalWrite(MP_DCS, HIGH);
  digitalWrite(MP_CS, HIGH);
  digitalWrite(MP_RESET, LOW);
  delay(10);
  digitalWrite(MP_RESET, HIGH);


  Serial8.begin(31250);

  SPI1.setMOSI(MP_MOSI);
  SPI1.setSCK(MP_SCK);
  SPI1.setClockDivider(SPI_CLOCK_DIV128);
  SPI1.setBitOrder(MSBFIRST);
  SPI1.begin ();

  Serial.begin(9600);
  Serial.print("Trellis -> ");
  if (!trellis.begin()) {
    Serial.println("FAILED");
  } else {
    Serial.println("OK");
  }

  Serial.print("Screen -> ");
  screen.begin();
  Serial.println("OK");

  volumeControl.setStep(5);
  volumeControl.attachEncoderCallback(volumeEncoderCallback);
  volumeControl.attachButtonCallback(volumeEncoderButtonCallback);

  toneControl.attachEncoderCallback(toneEncoderCallback);
  toneControl.attachButtonCallback(toneEncoderButtonCallback);

  tempoControl.attachEncoderCallback(tempoEncoderCallback);
  tempoControl.attachButtonCallback(tempoEncoderButtonCallback);

  twoByTwo.setButtonColour(VOICE_BUTTON, TBT_R);
  twoByTwo.setButtonColour(VELOCITY_BUTTON, TBT_G);
  twoByTwo.setButtonColour(RUN_STOP_BUTTON, RUNSTOP_STOPPED_COLOUR);
  twoByTwo.setButtonColour(POWER_BUTTON, POWER_ON_COLOUR);
  twoByTwo.attachPressCallback(VOICE_BUTTON, toneButtonCallback);
  twoByTwo.attachLongPressCallback(VOICE_BUTTON, toneButtonLongCallback);
  twoByTwo.attachPressCallback(RUN_STOP_BUTTON, runStopButtonCallback);
  twoByTwo.attachLongPressCallback(RUN_STOP_BUTTON, runStopButtonLongCallback);
  twoByTwo.attachPressCallback(VELOCITY_BUTTON, cancelVelocityCallback);
  twoByTwo.attachReleaseCallback(POWER_BUTTON, powerButtonReleasedCallback);

  threads.setSliceMicros(10);
  threads.addThread(leds_thread_func, 1);

  Serial.print("MIDI -> ");
  midi.enableMIDI();
  delay(200);
  mixer.init();
  delay(100);
  midi.setBank(0, MIDI_BANK_PERCUSSION);
  delay(100);
  midi.setBank(1, MIDI_BANK_PERCUSSION);
  delay(100);
  midi.setBank(2, MIDI_BANK_PERCUSSION);
  delay(100);
  midi.setBank(3, MIDI_BANK_PERCUSSION);
  delay(100);
  midi.setInstrument(0, 35);
  delay(100);
  midi.setInstrument(1, 42);
  delay(100);
  midi.setInstrument(2, 31);
  delay(100);
  midi.setInstrument(3, 28);
  delay(100);
  Serial.println("OK");

  delay(1000);

  toneControl.setValue(27);
  setBass(midi.getBass());

  deselectTones();
  setTreble(8);

  setBassWetLevel(20);
  setBassDryLevel(20);
  setLineLevel(0);
  deselectVolumes();
  setVolumeLevel(127);


  sequencer.attachNoteOnCallback(noteOnCallback);
  sequencer.attachNoteOffCallback(noteOffCallback);
  sequencer.attachBeatCallback(beatCallback);

  tempoControl.setValue(70);
  setTempo(70);

  Serial.println("NoteGrid -> ");
  noteGrid.attachEventHandler(noteGridEventHandler);
  noteGrid.attachKeyPressCallback(noteGridKeyPressCallback);
  noteGrid.attachKeyLongPressCallback(noteGridKeyLongPressCallback);
  noteGrid.setFlashBeat(true);
  noteGrid.begin();
  Serial.println("OK");

  Serial.println("channel defaults -> ");
  setChannelDefaults();
  Serial.println("OK");

  Serial.println("voice selection -> ");
  instrumentSelector.setChannel(0);
  Serial.println("OK");

  setDefaultMode();
}

unsigned long testFillScreen() {
  unsigned long start = micros();
  tft.fillScreen(ILI9341_BLACK);
  yield();
  tft.fillScreen(ILI9341_RED);
  yield();
  tft.fillScreen(ILI9341_GREEN);
  yield();
  tft.fillScreen(ILI9341_BLUE);
  yield();
  tft.fillScreen(ILI9341_BLACK);
  yield();
  return micros() - start;
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
