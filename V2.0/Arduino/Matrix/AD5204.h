#ifndef BM_AD5204_H
#define BM_AD5204_H

class AD5204 {

  public:

  AD5204(int cs_pin) : _cs(cs_pin) 
  {
       pinMode(_cs, OUTPUT);
       digitalWrite(_cs, HIGH);
  }

  void write(int address, int value) {
    SPI1.beginTransaction(SPISettings(400000, MSBFIRST, SPI_MODE0));
      digitalWrite(_cs,LOW);
      delayMicroseconds(10);
      
      SPI1.transfer(address & 0x03);
      SPI1.transfer(value);
      digitalWrite(_cs, HIGH);
    SPI1.endTransaction();
  }

  protected:
    int _cs;

};
#endif
