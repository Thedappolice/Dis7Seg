#include <Dis7Seg.h>

// pins in order (A, B, C, D, E, F, G, DP)
int pins[] = {2, 3, 4, 5, 6, 7, 8, 9};

// variables
int reset = 0;
float seconds = 0;
int minutes;
int shift = 0;
int c;

// constuctor
Dis7Seg dis('-', pins, 1);
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
  minutes = seconds / 60;
  checktime();
  // display();
  // dis.scan();
  findnum();

}

void checktime()
{
  seconds = seconds + 0.01;
  if (seconds > 60)
  {
    if (shift != 1)
    {
      shift = 1;
    }
  }
  if (minutes > 9)
  {
    if (shift != 2)
    {
      shift = 2;
    }
  }
}

int findnum()
{
  int numbers[4];
  int num;
  for (c = 1; c < 5; c++)
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
    numbers[c  - 1] = num ;
  }
  Serial.print(numbers[0]);
  Serial.print(" , ");
  Serial.print(numbers[1]);
  Serial.print(" , ");
  Serial.print(numbers[2]);
  Serial.print(" , ");
  Serial.print(numbers[3]);
  Serial.println("");
  return numbers;
}

// void display()
// {
//   for (c = 1; c < 5; c++)
//   {
//     outport();
//     findnum();
//     outnum();
//     if (c == (2 + shift) || c == shift)
//     {
//       digitalWrite(9, HIGH);
//     }
//     delay(5);
//   }
// }
