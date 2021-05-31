#ifndef VS1053_H
#define VS1053_H

#define VS_REG_MODE 0x0
#define VS_REG_STATUS 0x1
#define VS_REG_BASS 0x2
#define VS_REG_CLOCKF 0x3
#define VS_REG_DECODE_TIME 0x4
#define VS_REG_AUDATA 0x5
#define VS_REG_WRAM 0X6
#define VS_REG_WRAMADDR 0X7
#define VS_REG_HDAT0 0X8
#define VS_REG_HDAT1 0X9
#define VS_REG_AIADDR 0XA
#define VS_REG_VOL 0XB
#define VS_REG_AICTRL0 0XC
#define VS_REG_AICTRL1 0XD
#define VS_REG_AICTRL2 0XE
#define VS_REG_AICTRL3 0XF

// BIT POSITIONS IN VS_REG_MODE
#define VS_SM_DIFF 0
#define VS_SM_LAYER12 1
#define VS_SM_RESET 2
#define VS_SM_CANCEL 3
#define VS_SM_EARSPEAKER_LO 4
#define VS_SM_TESTS 5
#define VS_SM_STREAM 6
#define VS_SM_EARSPEAKER_HI 7
#define VS_SM_DACT 8
#define VS_SM_SDIORD 9
#define VS_SM_SDISHARE 10
#define VS_SM_SDINEW 11
#define VS_SM_ADPCM 12
#define VS_SM_LINE1 14
#define VS_SM_CLK_RANGE 15

// BIT POSITIONS IN VS_REG_STATUS
#define VS_SS_DO_NOT_JUMP 15
#define VS_SS_SWING 12
#define VS_SS_VCM_OVERLOAD 11 
#define VS_SS_VCM_DISABLE 10
#define VS_SS_VER 4
#define VS_SS_APDOWN 2
#define VS_SS_CLOCK 1
#define VS_SS_REFERENCE_SEL 0

// BIT POSITIONS IN VS_REG_BASS
#define VS_ST_AMPLITUDE 12
#define VS_ST_FREQLIMIT 8
#define VS_SB_AMPLITUDE 4
#define VS_SB_FREQLIMIT 0

// BIT POSITIONS IN VS_REG_CLOCKF
#define VS_SC_MULT 13
#define VS_SC_ADD 11
#define VS_SC_FREQ 0

// values for the clock multiplier
#define VS_CLOCK_MULT_1_0 0
#define VS_CLOCK_MULT_2_0 1
#define VS_CLOCK_MULT_2_5 2
#define VS_CLOCK_MULT_3_0 3
#define VS_CLOCK_MULT_3_5 4
#define VS_CLOCK_MULT_4_0 5
#define VS_CLOCK_MULT_4_5 6
#define VS_CLOCK_MULT_5_0 7


#define MIDI_NOTE_OFF 0x80
#define MIDI_NOTE_ON 0x90

#define MIDI_CHANNEL_MODE 0xb0
#define MIDI_CHANNEL_VOLUME 0x07
#define MIDI_CHANNEL_EXPRESSION 0x0b
#define MIDI_CHANNEL_PROGRAM 0xc0

#define MIDI_MODE_SET_BANK 0
#define MIDI_BANK_MELODIC 0
#define MIDI_BANK_PERCUSSION 0x78

const int minMelody = 0;
const int maxMelody = 127;
const char* melodyNames[]={     
    "Grand Piano","Bright Piano","Elec Grand Piano","Honky-Tonk Piano","Electric Piano 1","Electric Piano 2","Harpsicord","Clavi","Celesta",
    "Glockenspiel","Music Box","Vibraphone","Marimba","Xylophone","Tubular Bells","Dulcimer",
    "Drawbar Organ","Percussive Organ","Rock Organ","Church Organ","Reed Organ",
    "Accordian","Harmonica","Tango Accordian",
    "Acous Gtr (Nylon)","Acous Gtr (Steel)","Elec Gtr (Jazz)","Elec Gtr (Clean)","Elec Gtr (Muted)","Overdriven Gtr","Distorted Gtr","Gtr Harmonics",
    "Acoustic Bass","Elec Bass (Finger)","Elec Bass (Pick)","Fretless Bass","Slap Bass 1","Slap Bass 2","Synth Bass 1","Synth Bass 2",
    "Violin","Viola","Cello","Contrabass","Tremelo Strings","Pizzicato Strings","Orchestral Harp",
    "Timpani",
    "String Ensemb 1","String Ensemb 2","Synth Strings 1","Synth Strings 2",
    "Choir Aahs","Voice Oohs","Synth Voice",
    "Orchestra Hit",
    "Trumpet","Trombone","Tuba","Muted Trumpet","French Horn","Brass Section","Synth Brass 1","Synth Brass 2",
    "Soprano Sax","Alto Sax","Tenor Sax","Baritone Sax",
    
    "Oboe","English Horn","Bassoon","Clarinet","Piccolo","Flute","Recorder","Pan Flute","Blown Bottle","Shakuhachi","Whistle","Ocarina",
    
    "Square Lead","Saw Lead","Calliope Lead","Chiff Lead","Charang Lead","Voice Lead","Fifths Lead","Bass & Lead",
    
    "New Age Pad","Warm Pad","Polysynth Pad","Choir Pad","Bowed Pad","Metallic Pad","Halo Pad","Sweep Pad",
    
    "Rain FX","Sound Track FX","Crystal FX","Atmosphere FX","Brightness FX","Goblins FX","Echoes FX","Sci-Fi FX",
    
    "Sitar","Banjo","Shamisen","Koto","Kalimba","Bag Pipe","Fiddle","Shanai",
    
    "Tinkle Bell","Agogo","Pitched Percusssion","Wood Block","Taiko Drum","Melodic Drum","Synth Drum","Reverse Cymbal",
    
    "Guitar Fret Noise","Breath Noise","Seashore","Bird Tweet","Telephone Ring","Helicopter","Applause","Gunshot"
    
    };
    
const int minPercussion = 28;
const int maxPercussion = 87;
const char* percussionNames[]={    
    // disabled because it's really buggy "High Q",
    "Slap","Scratch Push","Scratch Pull","Sticks","Square Click","Metronome Click","Metronome Bell",
    "Acoustic BD","BD 1","Side Stick","Acoustic SD","HC","Electric SD","Low Flr Tom","CH [EXC 1]",
    "High Flr Tom","Pedal HH [EXC 1]","Low Tom","OH [EXC 1]","Low-Mid Tom","High-Mid Tom","Crash 1","High Tom",
    "Ride 1","China Cymbal","Ride Bell","Tamborine","Splash","(More) Cowbell","Crash 2","Vibra Slap",
    "Ride 2","High Bongo","Low Bongo","Hi Mute Conga","Open Hi Conga","Low Conga","High Timbale","Low Timbali",
    "High Agogo","Low Agogo","Cabasa","Maracas","Short Whistle [EXC2]","Long Whistle [EXC2]","Short Guiro [EXC3]","Long Guiro [EXC3]",
    "Claves","High Wood Block","Low Wood Block","Mute Cuica[EXC4]","Open Cuica[EXC4]","Mute Triangle [EXC5]","Open Triangle [EXC5]","Shaker",
    "Jingle Bells","Bell Tree","Castanets","Mute Surdo [EXC6]","Open Surdo [EXC6]"
  };

typedef struct {
  bool played;
  uint8_t channel;
  uint8_t note;
  uint8_t velocity;
  bool assigned;
} MIDINote;

class VS1053 {


  public:

  VS1053(int cs, int dcs, int reset, int sck, int mosi, int miso) : _cs(cs), _dcs(dcs), _reset(reset), _sck(sck), _mosi(mosi), _miso(miso), _bank(0) {
    
    pinMode(_mosi, OUTPUT);
    pinMode(_miso, INPUT);
    pinMode(_reset, OUTPUT);
    pinMode(_sck, OUTPUT);
    pinMode(_cs, OUTPUT);
    pinMode(_dcs, OUTPUT);
    digitalWrite(_dcs, HIGH);
    digitalWrite(_cs, HIGH);
    digitalWrite(_reset, LOW);
    delay(10);
    digitalWrite(_reset, HIGH); 
    
    SPI.begin ();
    SPI.setClockDivider(SPI_CLOCK_DIV128);
    SPI.setBitOrder(MSBFIRST);
    // midi.enableMIDI();
  }

  void enableMIDI() {
    digitalWrite(_reset, LOW);
    delay(10);
    digitalWrite(_reset, HIGH);
    delay(10);
    // now update the clock speed to 5X
    sendCommand(VS_REG_CLOCKF, (VS_CLOCK_MULT_5_0 << VS_SC_MULT));
    // let it settle
    delay(1);
  }

  void sendCommand(uint8_t address, uint16_t data) {
    digitalWrite(_cs, LOW);
    delayMicroseconds(1);
    SPI.transfer(0x00);
    SPI.transfer(address);
    SPI.transfer(data >> 8);
    SPI.transfer(data & 0xff);
    delayMicroseconds(1);
    digitalWrite(_cs, HIGH); 
    delayMicroseconds(1);   
  }

  void sendMIDIByte(uint8_t b) {
    digitalWrite(_dcs, LOW);
    delayMicroseconds(1);
    SPI.transfer(0x00);
    SPI.transfer(b);
    delayMicroseconds(1);
    digitalWrite(_dcs, HIGH); 
    delayMicroseconds(1);
  }
    
  void noteOn(MIDINote note) {
    sendMIDIByte(MIDI_NOTE_ON | (note.channel & 0x0f));
    sendMIDIByte(note.note & 0x7f);
    sendMIDIByte(note.velocity & 0x7f);
  }
  
  void noteOff(MIDINote note) {
    sendMIDIByte(MIDI_NOTE_OFF | (note.channel & 0x0f));
    sendMIDIByte(note.note & 0x7f);
    sendMIDIByte(note.velocity & 0x7f);
  }
  
  void setVolume(uint8_t channel, uint8_t vol) {
    sendMIDIByte(MIDI_CHANNEL_MODE | (channel & 0x0f));
    sendMIDIByte(MIDI_CHANNEL_VOLUME);
    sendMIDIByte(vol & 0x7f);
  }
  
  void setInstrument(uint8_t channel, uint8_t instrument) {
      sendMIDIByte(MIDI_CHANNEL_PROGRAM | (channel & 0x0f));
      sendMIDIByte(instrument);  
  }

  const char * getInstrumentName(uint8_t instrument) {
     if((_bank == 0) | (_bank == 0x79)) {
       if((instrument >= minMelody) && (instrument < maxMelody)) {
        return melodyNames[instrument - minMelody];
       }
     } else {
       if((instrument  >= minPercussion) && (instrument < maxPercussion)) {
        return percussionNames[instrument - minPercussion];
       }    
     }
     return " ";
  }
  
  void setBank(uint8_t channel, uint8_t bank) {
    sendMIDIByte(MIDI_CHANNEL_MODE | (channel & 0x0f));
    sendMIDIByte(MIDI_MODE_SET_BANK);
    sendMIDIByte(bank & 0x7f); 
    _bank = bank;
  }

    protected:
      uint8_t _cs, _dcs, _reset, _sck, _mosi, _miso;
      char _name[30];
      uint8_t _bank;
};
#endif
