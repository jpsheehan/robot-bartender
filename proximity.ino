#define MINIMUM_DISTANCE 4
#define MAXIMUM_DISTANCE 6

static uint8_t triggerPin;
static uint8_t echoPin;

// proximitySetup initialises the pins of the proximity sensor
// 
// trigger is the pin for the trigger
// echo is the pin for the echo
void proximitySetup(uint8_t echo, uint8_t trigger) {
  triggerPin = trigger;
  echoPin = echo;
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// proximityGetDistance returns the detected distance in cm
//   if the returned distance is zero, the object is out of range
long proximityGetDistance() {
  long duration, distance;

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2.00f) / 29.1f;
  return distance;
}

// proximityIsCupDetected returns true if a cup is detected based on the MINIMUM_DISTANCE
//   and MAXIMUM_DISTANCE macros
bool proximityIsCupDetected() {
  long distance = proximityGetDistance();
  return (distance >= MINIMUM_DISTANCE && distance <= MAXIMUM_DISTANCE);
}

