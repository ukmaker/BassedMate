#ifndef BM_INSTRUMENTS_H
#define BM_INSTRUMENTS_H

typedef struct Voice {
  const char *name;
  uint8_t id;
} Voice;

const Voice drums[] = {
  {  "Acoustic BD",                    35 },
  {  "BD 1",                           36 },
  {  "Acoustic SD",                    38 },
  {  "Electric SD",                    40 },
  {  "Low Flr Tom",                    41 },
  {  "High Flr Tom",                   43 },
  {  "Low Tom",                        45 },
  {  "Low-Mid Tom",                    47 },
  {  "High-Mid Tom",                   48 },
  {  "High Tom",                       50 },
  {  "High Bongo",                     60 }, 
  {  "Low Bongo",                      61 },
  {  "Hi Mute Conga",                  62 },
  {  "Open Hi Conga",                  63 },
  {  "Low Conga",                      64 },
  {  "High Timbale",                   65 },
  {  "Low Timbali",                    66 },
  {  "Mute Surdo",                     86 },
  {  "Open Surdo",                     87 }
};

const Voice cymbals[] = {
  {  "CH",                             42 },
  {  "Pedal HH",                       44 },
  {  "OH",                             46 },
  {  "Crash 1",                        49 },
  {  "Ride 1",                         51 },
  {  "China Cymbal",                   52 },
  {  "Ride Bell",                      53 },
  {  "Tamborine",                      54 },
  {  "Crash 2",                        57 },
  {  "Ride 2",                         59 }
};

const Voice woods[] = {
  {  "Sticks",                         31 },
  {  "Square Click",                   32 },
  {  "Metronome Click",                33 },
  {  "Metronome Bell",                 34 },
  {  "Side Stick",                     37 },
  {  "HC",                             39 },
  {  "High Agogo",                     67 },
  {  "Low Agogo",                      68 },
  {  "Claves",                         75 },
  {  "High Wood Block",                76 },
  {  "Low Wood Block",                 77 }
};

const Voice specials[] = {
  {  "Slap",                           28 },
  {  "Scratch Push",                   29 },
  {  "Scratch Pull",                   30 },
  {  "Splash",                         55 },
  {  "Cowbell",                        56 },
  {  "Vibra Slap",                     58 },
  {  "Cabasa",                         69 },
  {  "Maracas",                        70 },
  {  "Short Whistle",                  71 },
  {  "Long Whistle",                   72 },
  {  "Short Guiro",                    73 },
  {  "Long Guiro",                     74 },
  {  "Mute Cuica",                     78 },
  {  "Open Cuica",                     79 },
  {  "Mute Triangle",                  80 },
  {  "Open Triangle",                  81 },
  {  "Shaker",                         82 },
  {  "Jingle Bells",                   83 },
  {  "Bell Tree",                      84 },
  {  "Castanets",                      85 }
};

typedef struct Instrument {
  uint8_t bank = 0;
  bool melodic = true;
  uint8_t defaultNote = 127;
  Voice voice;
} Instrument;

class Instruments {

  public:

  Instruments(const char *type, uint8_t bank, bool melodic, uint8_t defaultNote, uint8_t defaultVelocity, const Voice *voices, uint8_t numVoices) :
    _type(type), _bank(bank), _melodic(melodic), _defaultNote(defaultNote), _defaultVelocity(defaultVelocity), _voices(voices), _numVoices(numVoices)
  {}

  Instrument getDefaultInstrument() {
    return getInstrumentByIndex(0);
  }

  Instrument getInstrumentByIndex(uint8_t index) {
    Instrument i;
    
    if(index >= _numVoices) {
      // return the last one instead
      return getInstrumentByIndex(_numVoices-1);
    }

    if(_melodic) {
      i = { _bank, _melodic, _defaultNote, _voices[index] };
    } else {
      i = { _bank, _melodic, _voices[index].id, _voices[index] };
    }

    return i;
  }

  int indexOf(uint8_t voiceId) {
    for (int i = 0; i < _numVoices; i++) {
      if (voiceId == _voices[i].id) {
        return i;
      }
    }
    return -1; 
  }

  uint8_t getNumVoices() {
    return _numVoices;
  }

  protected:
  const char *_type;
  uint8_t _bank;
  bool _melodic;
  uint8_t _defaultNote;
  uint8_t _defaultVelocity;
  const Voice *_voices;
  uint8_t _numVoices;
};

#define LEN(N) (sizeof(N) / sizeof(N[0]))

  Instruments drumsCollection(    "Drums",    0x78, false, drums[0].id,    127, drums,    LEN(drums)   );
  Instruments cymbalsCollection(  "Cymbals",  0x78, false, cymbals[0].id,  127, cymbals,  LEN(cymbals) );
  Instruments woodsCollection(    "Woods",    0x78, false, woods[0].id,    127, woods,    LEN(woods)   );
  Instruments specialsCollection( "Specials", 0x78, false, specials[0].id, 127, specials, LEN(specials));

Instruments *AllInstruments[4] = { &drumsCollection, &cymbalsCollection, &woodsCollection, &specialsCollection };

#endif
