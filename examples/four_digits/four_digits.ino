#include <Dis7Seg.h>

// pins in order (A, B, C, D, E, F, G, DP)
int pins[] = {2, 3, 4, 5, 6, 7, 8, 9};

// digit pins from left ro right
int digitpins[] = {10, 11, 12, 13};

// variables
int output[4];
bool Ondot[4] = {false, true, false, false};

char symbol = '-';
unsigned long updatetime;
float seconds = 0;
int minutes;

// constuctor
Dis7Seg dis(symbol, pins, 4, digitpins);
/*
class_name Object_name
(
  common cathode '+' / common anode '-',
  pin_array,
  number_of_digits
)
*/

void setup()
{
}

void loop()
{
  checktime();             // check for time
  getnum();                // get each numebr and record to memory
  dis.scan(output, Ondot); // refresh the display
}

void checktime()
{
  minutes = seconds / 60;
  seconds = seconds + 0.01;
  if (seconds > 60 && Ondot[1] == true)
  {
    movedot(1);
  }
  if (minutes > 9 && Ondot[2] == true)
  {
    movedot(2);
  }
}

void movedot(int digit)
{
  Ondot[digit] = false;
  Ondot[digit + 1] = true;
}

void getnum()
{
  int num;
  for (int c = 1; c < 5; c++)
  {
    if (seconds < 60)
    {
      if (c == 1)
      {
        num = (seconds / 10);
      }
      else if (c == 2)
      {
        num = seconds;
      }
      else if (c == 3)
      {
        num = seconds * 10;
      }
      else
      {
        num = seconds * 100;
      }
    }
    else
    {
      if (minutes < 10)
      {
        if (c == 1)
        {
          num = minutes;
        }
        else if (c == 2)
        {
          num = seconds / 10;
          if (num > 5)
          {
            num = num % 6;
          }
        }
        else if (c == 3)
        {
          num = seconds;
        }
        else
        {
          num = seconds * 10;
        }
      }
      else
      {
        if (c == 1)
        {
          num = (minutes / 10);
        }
        else if (c == 2)
        {
          num = minutes;
        }
        else if (c == 3)
        {
          num = seconds / 10;
          if (num > 5)
          {
            num = num % 6;
          }
        }
        else
        {
          num = seconds;
        }
      }
    }
    num = num % 10;
    output[c - 1] = num;
  }
}
