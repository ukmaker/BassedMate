#ifndef BM_AD5204_H
#define BM_AD5204_H

class AD5204 {

  public:

  AD5204(int cs_pin, int clk_pin, int sdi_pin) :
    _cs(cs_pin), _clk(clk_pin), _sdi(sdi_pin) 
  {
       pinMode(_cs, OUTPUT);
       pinMode(_clk, OUTPUT);
       pinMode(_sdi, OUTPUT);
       digitalWrite(_cs, HIGH);
       digitalWrite(_clk, HIGH);
       digitalWrite(_sdi, HIGH);
    }


  void write(int address, int value) {
     digitalWrite(_cs,LOW);
     // shift out the address
     for(int i=7; i>=0; i--) {
        if(address & (1 << i)) {
          digitalWrite(_sdi,HIGH);
        } else {
          digitalWrite(_sdi,LOW);
        }
        
        digitalWrite(_clk,LOW);
        digitalWrite(_clk,HIGH); 
     }
     // shift out the data
     for(int i=7; i>=0; i--) {
        if(value & (1 << i)) {
          digitalWrite(_sdi,HIGH);
        } else {
          digitalWrite(_sdi,LOW);
        }
        
        digitalWrite(_clk,LOW);
        digitalWrite(_clk,HIGH); 
     }
      digitalWrite(_cs,HIGH);
  }


  protected:
    int _cs, _clk, _sdi;
};
#endif
