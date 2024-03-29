#include <Dis7Seg.h>

// pins in order (A, B, C, D, E, F, G, DP)
int segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

// digit pins from left to right
int digitpins[] = {10, 11, 12, 13};

// variables
int output[4];
bool Ondot[] = {false, true, false, false};

float seconds = 0;
int minutes;

// constuctor
Dis7Seg dis('-', segmentPins, 4, digitpins);
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
  seconds = seconds + 0.0208;
  if (seconds > 60 && Ondot[1] == true)
  {
     Ondot[0] = true;
    Ondot[1] = false;
  Ondot[2] = true;
 
  }
  if (minutes > 9 && Ondot[2] == true)
  {
    Ondot[0] = false;
  Ondot[1] = true;
  Ondot[2] = false; 
  }
}

void movedot(int digit)
{
  
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
