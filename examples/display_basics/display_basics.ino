#include <Dis7Seg.h>

// pins in order (A, B, C, D, E, F, G, DP)
int segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

// digit pins from left to right
int digitPins[] = {10, 11, 12, 13};

// array for output
int output[] = {2, 4, 7, 9};

// array for dot position
bool dot_place[] = {false, true, false, true};

// constuctor
Dis7Seg dis('-', segmentPins, 4, digitPins);
/*
class_name Object_name
(
  common cathode '+' / common anode '-',
  segment_array,
  number_of_digits,
  digit_pin_array
)
*/

void setup()
{
  dis.test(); // tests each segment of each digit.
}

void loop()
{
  dis.write(5, true); // writes a specified number ( 0 - 9 ),
  // with or without a decimal point (true / false) (optional)

  dis.scan(output, dot_place); // refresh display with given number
                               // and dots' positions (optional)
}