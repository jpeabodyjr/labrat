#include "hcsr04.h"

Hcsr04::Hcsr04(int triggerPin, int echoPin)
{
  // Configure the trigger pin as output.
  pinMode(triggerPin, OUTPUT);

  // Configure the echo pin as input.
  pinMode(echoPin, INPUT);

  // Store the pin definitions.
  m_triggerPin = triggerPin;
  m_echoPin = echoPin;
}



float
Hcsr04::getDistanceInches()
{
  // A scale factor used to convert the measured response time to inches.
  static const int INCHES_SCALE_FACTOR = 148.0;

  // A timeout value, in microseconds, that limits the range of the measurement.
  static const int TIMEOUT_US = 5000;

  // A variable to store the length of the response pulse from the PING Ultrasound sensor.
  float responsePulseTime = 0;

  // A variable to store the distance to the detected object.
  float distance = 0;

  // Create an ultrasound pulse, 10ms long.
  digitalWrite(m_triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(m_triggerPin, LOW);

  // Measure the amount of time the ECHO pin is HIGH after sending out the ultrasound pulse.
  responsePulseTime = pulseIn(m_echoPin, HIGH, TIMEOUT_US);

  // Converte the response time to inches.
  distance = responsePulseTime / 148.0;

  return distance;
}
