#include <Dis7Seg.h>

// pins in order (A, B, C, D, E, F, G, DP)
int pins[] = {2, 3, 4, 5, 6, 7, 8, 9};

// variable
int num = 0;
unsigned long updatetime;

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
  if (num != 11)
  {
    updatetime = millis();
    while (millis() - updatetime < 2000)// show for 2 seconds
    {
      if (num != 10)
      {
        dis.write(num); // write number
        // object_name.write(number)
      }
      else
      {
        num = 9;
        dis.write(num, true);
        /*object_name.write(number,
                            turn on/off dot at the digit's place
                            )*/
      }
    }
    num++;
  }
  else
  {
    num = 0;
  }
}