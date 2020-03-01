#ifndef hcsr04_h
#define hcsr04_h

#include "Arduino.h"

class Hcsr04
{
public:

  /// Constructor.
  Hcsr04(int triggerPin, int echoPin);

  /// Get the distance, in inches.
  float getDistanceInches();

private:
  /// The trigger pin.
  int m_triggerPin;

  /// The echo pin
  int m_echoPin;
};

#endif
