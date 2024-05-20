const int dirPin = 33;  // Direction pin for the stepper motor
const int stepPin = 12; // Step pin for the stepper motor
const int enPin = 11;   // Enable pin for the stepper motor

void setup() {
  pinMode(stepPin, OUTPUT); // Set step pin as an output
  pinMode(dirPin, OUTPUT);  // Set direction pin as an output
  pinMode(enPin, OUTPUT);   // Set enable pin as an output
  digitalWrite(enPin, LOW); // Enable the motor
  Serial.begin(9600);       // Initialize serial communication
}

void loop() {
  dyttePumpe(33, 12, 11, 1000); // Call function to run the pump
}

void dyttePumpe(int dirPin, int stepPin, int enPin, unsigned long tid) {
  // Activate the pump (send continuous step signals) for 10 seconds
  unsigned long startTime = millis(); // Store the start time

  // Set direction to push the liquid
  digitalWrite(dirPin, HIGH);

  while (millis() - startTime < 10000) { // As long as 10 seconds have not passed
    // Send a step signal
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(400); // Adjust this to change the step speed
    digitalWrite(stepPin, LOW);
    delayMicroseconds(400); // Adjust this to change the step speed
  }
  
  // Turn off the pump after 10 seconds
  digitalWrite(enPin, HIGH); // Disable the motor

  // Stop the loop, so the code does not run again
  while (true) {}
}
