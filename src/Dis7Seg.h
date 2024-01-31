#ifndef Dis7Seg_H
#define Dis7Seg_H

#include <Arduino.h>

class Dis7Seg
{
public:
    Dis7Seg(char modeSymbol, int pins[8], int digit = 1, int bitpins[4] = nullptr);
    void write( int number, bool dot = false, int place = 0);
    void scan(int numbers[4], bool dot = false, bool Ondot[4] = nullptr);

private:
    int activePull;
    int passivePull;

    int *Pins;

    int digits;
    int *BitPins;

    int *ScanNums;

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

    void gotodigit(int digit);

    void Clear();
};

#endif
