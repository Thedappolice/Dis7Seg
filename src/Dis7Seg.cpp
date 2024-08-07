#include "Dis7Seg.h"

// public:

Dis7Seg::Dis7Seg(char modeSymbol, int pins[8], int digit, int bitpins[4])
{
    if (modeSymbol != '+' && modeSymbol != '-')
    {
        Serial.begin(9600);
        Serial.println("Error: Invalid mode symbol. Use \'+\' or \'-\'.");
    }

    if (modeSymbol == '+')
    {
        activePull = LOW;
        passivePull = HIGH;
    }
    else if (modeSymbol == '-')
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
        digitalWrite(BitPins[i], HIGH);
    }

    ScanNums = new int[digits];
}

void Dis7Seg::test()
{
    for (int d = 0; d < digits; d++)
    {
        gotodigit(d);
        for (int i = 0; i < 8; i++)
        {
            digitalWrite(Pins[i], activePull);
            delay(100);
        }
        for (int i = 0; i < 8; i++)
        {
            digitalWrite(Pins[i], passivePull);
            delay(100);
        }
    }
}

void Dis7Seg::write(int number, bool dot)
{
    if (number != -1)
    {
        if (number < 0)
        {
            memory = 0;
        }
        else if (number > 9)
        {
            memory = 9;
        }
        else
        {
            memory = number;
        }

        if (dot == true)
        {
            digitalWrite(Pins[7], activePull);
        }
        switch (number)
        {
        case 0:
            char0();
            break;
        case 1:
            char1();
            break;
        case 2:
            char2();
            break;
        case 3:
            char3();
            break;
        case 4:
            char4();
            break;
        case 5:
            char5();
            break;
        case 6:
            char6();
            break;
        case 7:
            char7();
            break;
        case 8:
            char8();
            break;
        case 9:
            char9();
            break;
        }
        Clear();
    }
}

void Dis7Seg::scan(int numbers[4], bool Ondot[4])
{
    for (int i = 0; i < digits; i++)
    {
        ScanNums[i] = numbers[i];
    }

    for (int i = 0; i < digits; i++)
    {
        gotodigit(i);
        if (Ondot != nullptr && Ondot[i] == true)
        {
            write(ScanNums[i], true);
        }
        else
        {
            write(ScanNums[i]);
        }
    }
}

// private :
void Dis7Seg::char0()
{
    for (int i = 0; i < 7; i++)
    {
        if (i != 6)
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
        if (i != 2 && i != 5)
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
        if (i != 4 && i != 5)
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
        digitalWrite(BitPins[i], activePull);
    }
    digitalWrite(BitPins[digit], passivePull);
}

void Dis7Seg::Clear()
{
    delay(2);
    for (int i = 0; i < 8; i++)
    {
        digitalWrite(Pins[i], passivePull);
    }
}
