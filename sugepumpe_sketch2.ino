const int dirPin = 7;  // Direction pin for the stepper motor
const int stepPin = 6; // Step pin for the stepper motor
const int enPin = 5;   // Enable pin for the stepper motor

void setup() {
  pinMode(stepPin, OUTPUT); // Set step pin as an output
  pinMode(dirPin, OUTPUT);  // Set direction pin as an output
  pinMode(enPin, OUTPUT);   // Set enable pin as an output
  digitalWrite(enPin, LOW); // Enable the motor
  Serial.begin(9600);       // Initialize serial communication
}

void loop() {
  sugePumpe(7, 6, 5, 6000); // Call function to run the pump for 60 seconds
}

void sugePumpe(int dirPin, int stepPin, int enPin, unsigned long tid) {
  // Activate the pump (send continuous step signals) for 60 seconds
  unsigned long startTime = millis(); // Store the start time
  digitalWrite(dirPin, HIGH); // Set direction to suck
  while (millis() - startTime < 60000) { // As long as 60 seconds have not passed
    // Send a step signal
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500); // Adjust this to change the step speed
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500); // Adjust this to change the step speed
  }

  // Turn off the pump after 60 seconds
  digitalWrite(enPin, HIGH); // Disable the motor

  // Stop the loop, so the code does not run again
  while (true) {}
}
