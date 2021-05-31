#ifndef VS1053_H
#define VS1053_H

#define MIDI_NOTE_OFF 0x80
#define MIDI_NOTE_ON 0x90

#define MIDI_CHANNEL_MODE 0xb0
#define MIDI_CHANNEL_VOLUME 0x07
#define MIDI_CHANNEL_EXPRESSION 0x0b
#define MIDI_CHANNEL_PROGRAM 0xc0

typedef struct {
  uint8_t channel;
  uint8_t note;
  uint8_t velocity;
} MIDINote;

class VS1053 {


  public:

  VS1053(uint8_t cs) : _cs(cs) {};

  void enableMIDI() {

  }

  void noteOn(MIDINote note);
  void noteOff(MIDINote note);
  void setVolume(uint8_t channel, uint8_t vol);

  void setVoice(uint8_t channel, uint8_t voice);
  void setBank(uint8_t channel, uint8_t bank);

  protected:
  uint8_t _cs;

  void sendMIDIByte(uint8_t b) {
    digitalWrite(_cs, LOW);
    SPI.transfer(b);
    SPI.transfer(0x00);
    digitalWrite(_cs, HIGH);   
  }
  

  
};

void VS1053::noteOn(MIDINote note) {
  sendMIDIByte(MIDI_NOTE_ON | (note.channel & 0x0f));
  sendMIDIByte(note.note & 0x7f);
  sendMIDIByte(note.velocity & 0x7f);
}

void VS1053::setVolume(uint8_t channel, uint8_t vol) {
  sendMIDIByte(MIDI_CHANNEL_MODE | (channel & 0x0f));
  sendMIDIByte(MIDI_CHANNEL_VOLUME);
  sendMIDIByte(vol & 0x7f);
}

void VS1053::setVoice(uint8_t channel, uint8_t voice) {
    sendMIDIByte(MIDI_CHANNEL_PROGRAM | (channel & 0x0f));
    sendMIDIByte(voice);  
}

#endif
