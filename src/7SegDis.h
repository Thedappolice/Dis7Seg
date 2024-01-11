#ifndef 7SegDis_H
#define 7SegDis_H

#include <Arduino.h>

class 7SegDis
{
public:
   7SegDis(int pins[8], int bits = 1, int bitpins[]);
   7SegDis(int pins[8], int bits = 1);
   pubic write(int number);
private:
    int* Pins;

    void 1();
    void 2();
    void 3();
    void 4();
    void 5();
    void 6();
    void 7();
    void 8();
    void 9();

};

#endif
