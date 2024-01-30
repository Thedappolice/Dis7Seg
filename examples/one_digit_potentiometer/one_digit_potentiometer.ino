#include <Dis7Seg.h>

// allocate potentiometer with A0 pin
#define pot A0

// pins in order (A, B, C, D, E, F, G, DP)
int pins[] = {2, 3, 4, 5, 6, 7, 8, 9};

// variables
int value;
int num;

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
  value = analogRead(pot);          // read analog pin
  num = map(value, 0, 1023, 0, 10); // mapping values
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
