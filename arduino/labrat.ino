#include "hcsr04.h"

// The PING Ultrasound sensor ECHO pin.
#define PIN_US_ECHO 2

// The PING Ultrasound sensor TRIG pin.
#define PIN_US_TRIG 3

Hcsr04 hcsr04(PIN_US_TRIG, PIN_US_ECHO);

float distance = 0;

void
setup()
{
  Serial.begin(9600);
}

void
loop()
{
  distance = hcsr04.getDistanceInches();

  Serial.print(distance);
  Serial.println(" in");

  delay(50);
}
