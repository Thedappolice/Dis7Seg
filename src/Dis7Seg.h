#ifndef Dis7Seg_H
#define Dis7Seg_H

#include <Arduino.h>

class Dis7Seg
{
public:
    Dis7Seg(char modeSymbol,int pins[8], int digit = 1, int bitpins[4]);
    Dis7Seg(char modeSymbol, int pins[8], int digit = 1);
    void write(int number);
    

private:
char mode;
    int *Pins;
    int digits;
    int *BitPins;

    void char0();
    void char1();
    void char2();
    void char3();
    void char4();
    void char5();
    void char6();
    void char7();
    void char8();
    void char9();

    void Clear();
};

#endif
