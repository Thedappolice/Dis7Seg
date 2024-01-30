#ifndef Dis7Seg_H
#define Dis7Seg_H

#include <Arduino.h>

class Dis7Seg
{
public:
    Dis7Seg(char modeSymbol, int pins[8], int digit, int bitpins[4]);
    Dis7Seg(char modeSymbol, int pins[8], int digit = 1);
    void write( int number, bool dot = false, int place = 0);
    void scan(int number1, int number2, int number3, int number4, bool dot, int dotplace1 = 0, int dotplace2 = 0, int dotplace3 = 0, int dotplace4 = 0);
    void scan(int number1, int number2, int number3, int number4);

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
