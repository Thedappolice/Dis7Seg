#include "Dis7Seg.h"

// public:

Dis7Seg::Dis7Seg(char modeSymbol, int pins[8], int digit, int bitpins[4])
{
    static_assert(modeSymbol == '+' || modeSymbol == '-', "First parameter must be either \'+\' or \'-\'. ");

    Pins = new int[8];
    for (int i = 0; i < 8; i++)
    {
        Pins[i] = pins[i];
        pinMode(Pins[i], OUTPUT);
    }

    digits = digit;

    BitPins = new int[4];
    for (int i = 0; i < 4; i++)
    {
        BitPins[i] = bitpins[i];
    }
    mode = modeSymbol;
}

Dis7Seg::Dis7Seg(char modeSymbol, int pins[8], int digit)
{
    static_assert(modeSymbol == '+' || modeSymbol == '-', "First parameter must be either \'+\' or \'-\'. ");

    Pins = new int[8];
    for (int i = 0; i < 8; i++)
    {
        Pins[i] = pins[i];
        pinMode(Pins[i], OUTPUT);
    }

    digits = digit;

    mode = modeSymbol;
}

void Dis7Seg::write(int number, String dot)
{
    if(dot == "dot")
    {
        digitalWrite(Pins[7], HIGH);
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
}

// private :
void Dis7Seg::char0()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 5)
        {
            digitalWrite(Pins[i], HIGH);
        }
        else
        {
            digitalWrite(Pins[i], LOW);
        }
    }
    Clear();
}
void Dis7Seg::char1()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 1 && i != 2)
        {
            digitalWrite(Pins[i], LOW);
        }
        else
        {
            digitalWrite(Pins[i], HIGH);
        }
    }
    Clear();
}
void Dis7Seg::char2()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 2 && i != 6)
        {
            digitalWrite(Pins[i], HIGH);
        }
        else
        {
            digitalWrite(Pins[i], LOW);
        }
    }
    Clear();
}
void Dis7Seg::char3()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 4 && i != 6)
        {
            digitalWrite(Pins[i], HIGH);
        }
        else
        {
            digitalWrite(Pins[i], LOW);
        }
    }
    Clear();
}
void Dis7Seg::char4()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 0 && i != 3 && i != 4)
        {
            digitalWrite(Pins[i], HIGH);
        }
        else
        {
            digitalWrite(Pins[i], LOW);
        }
    }
    Clear();
}
void Dis7Seg::char5()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 1 && i != 4)
        {
            digitalWrite(Pins[i], HIGH);
        }
        else
        {
            digitalWrite(Pins[i], LOW);
        }
    }
    Clear();
}
void Dis7Seg::char6()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 1)
        {
            digitalWrite(Pins[i], HIGH);
        }
        else
        {
            digitalWrite(Pins[i], LOW);
        }
    }
    Clear();
}
void Dis7Seg::char7()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 0 && i != 1 && i != 2)
        {
            digitalWrite(Pins[i], LOW);
        }
        else
        {
            digitalWrite(Pins[i], HIGH);
        }
    }
    Clear();
}
void Dis7Seg::char8()
{
    for (int i = 0; i < 7; i++)
    {
        digitalWrite(Pins[i], HIGH);
    }
    Clear();
}
void Dis7Seg::char9()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 4)
        {
            digitalWrite(Pins[i], HIGH);
        }
        else
        {
            digitalWrite(Pins[i], LOW);
        }
    }
    Clear();
}

void Dis7Seg::Clear()
{
    if (mode == '+')
    {
        for (int i = 0; i < 8; i++)
        {
            digitalWrite(Pins[i], HIGH);
        }
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            digitalWrite(Pins[i], LOW);
        }
    }
}
