#include "Dis7Seg.h"

// public:

Dis7Seg::Dis7Seg(char modeSymbol, int pins[8], int digit, int bitpins[4])
{
    static_assert(modeSymbol == '+' || modeSymbol == '-', "First parameter must be either \'+\' or \'-\'. ");

    if (modeSymbol == '+')
    {
        activePull = LOW;
        passivePull = HIGH;
    }
    else
    {
        activePull = HIGH;
        passivePull = LOW;
    }

    Pins = new int[8];
    for (int i = 0; i < 8; i++)
    {
        Pins[i] = pins[i];
        pinMode(Pins[i], OUTPUT);
    }

    digits = digit;

    BitPins = new int[digits];
    for (int i = 0; i < digits; i++)
    {
        BitPins[i] = bitpins[i];
        pinMode(BitPins[i], OUTPUT);
    }

    ScanNums = new int[digits];
}

Dis7Seg::Dis7Seg(char modeSymbol, int pins[8], int digit)
{
    static_assert(modeSymbol == '+' || modeSymbol == '-', "First parameter must be either \'+\' or \'-\'. ");

    if (modeSymbol == '+')
    {
        activePull = LOW;
        passivePull = HIGH;
    }
    else
    {
        activePull = HIGH;
        passivePull = LOW;
    }

    Pins = new int[8];
    for (int i = 0; i < 8; i++)
    {
        Pins[i] = pins[i];
        pinMode(Pins[i], OUTPUT);
    }

    digits = digit;

    ScanNums = new int[digits];
}

void Dis7Seg::write(int place, int number, bool dot)
{
    gotodigit(place);
    if (dot == true)
    {
        digitalWrite(Pins[7], activePull);
    }
    if (number == 0)
    {
        char0();
    }
    else if (number == 1)
    {
        char1();
    }
    else if (number == 2)
    {
        char2();
    }
    else if (number == 3)
    {
        char3();
    }
    else if (number == 4)
    {
        char4();
    }
    else if (number == 5)
    {
        char5();
    }
    else if (number == 6)
    {
        char6();
    }
    else if (number == 7)
    {
        char7();
    }
    else if (number == 8)
    {
        char8();
    }
    else if (number == 9)
    {
        char9();
    }
    Clear();
}

void Dis7Seg::scan(int number1, int number2, int number3, int number4, bool dot = false, int dotplace1 = 0, int dotplace2 = 0, int dotplace3 = 0, int dotplace4 = 0)
{
    ScanNums[0] = number1;
    ScanNums[1] = number2;
    ScanNums[2] = number3;
    ScanNums[3] = number4;

    for (int i = 0; i < digits; i++)
    {
        gotodigit(i);
        if (dot && (dotplace1 == i + 1 || dotplace2 == i + 1 || dotplace3 == i + 1 || dotplace4 == i + 1))
        {
            write(i + 1, ScanNums[i], true);
        }
        else
        {
            write(i + 1, ScanNums[i]);
        }
    }
}

// private :
void Dis7Seg::char0()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 5)
        {
            digitalWrite(Pins[i], activePull);
        }
        else
        {
            digitalWrite(Pins[i], passivePull);
        }
    }
}
void Dis7Seg::char1()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 1 && i != 2)
        {
            digitalWrite(Pins[i], passivePull);
        }
        else
        {
            digitalWrite(Pins[i], activePull);
        }
    }
}
void Dis7Seg::char2()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 2 && i != 6)
        {
            digitalWrite(Pins[i], activePull);
        }
        else
        {
            digitalWrite(Pins[i], passivePull);
        }
    }
}
void Dis7Seg::char3()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 4 && i != 6)
        {
            digitalWrite(Pins[i], activePull);
        }
        else
        {
            digitalWrite(Pins[i], passivePull);
        }
    }
}
void Dis7Seg::char4()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 0 && i != 3 && i != 4)
        {
            digitalWrite(Pins[i], activePull);
        }
        else
        {
            digitalWrite(Pins[i], passivePull);
        }
    }
}
void Dis7Seg::char5()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 1 && i != 4)
        {
            digitalWrite(Pins[i], activePull);
        }
        else
        {
            digitalWrite(Pins[i], passivePull);
        }
    }
}
void Dis7Seg::char6()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 1)
        {
            digitalWrite(Pins[i], activePull);
        }
        else
        {
            digitalWrite(Pins[i], passivePull);
        }
    }
}
void Dis7Seg::char7()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 0 && i != 1 && i != 2)
        {
            digitalWrite(Pins[i], passivePull);
        }
        else
        {
            digitalWrite(Pins[i], activePull);
        }
    }
}
void Dis7Seg::char8()
{
    for (int i = 0; i < 7; i++)
    {
        digitalWrite(Pins[i], activePull);
    }
}
void Dis7Seg::char9()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 4)
        {
            digitalWrite(Pins[i], activePull);
        }
        else
        {
            digitalWrite(Pins[i], passivePull);
        }
    }
}

void Dis7Seg::gotodigit(int digit)
{
    for (int i = 0; i < digits; i++)
    {
        digitalWrite(BitPins[i], passivePull);
    }
    digitalWrite(BitPins[digit], activePull);
}

void Dis7Seg::Clear()
{
    delay(10);
    for (int i = 0; i < 8; i++)
    {
        digitalWrite(Pins[i], passivePull);
    }
}
