const int dirPin = 10; // Direction pin for the stepper motor
const int stepPin = 9; // Step pin for the stepper motor
const int enPin = 8;   // Enable pin for the stepper motor

void setup() {
    pinMode(stepPin, OUTPUT); // Set step pin as an output
    pinMode(dirPin, OUTPUT);  // Set direction pin as an output
    pinMode(enPin, OUTPUT);   // Set enable pin as an output
    digitalWrite(enPin, LOW); // Enable the motor
    Serial.begin(9600);       // Initialize serial communication
}

void loop() {
    // Move motor in one direction for 1000 steps
    for (int x = 1; x < 1000; x++) {
        digitalWrite(dirPin, HIGH);    // Set direction to HIGH
        digitalWrite(stepPin, HIGH);   // Take a step
        delayMicroseconds(500);        // Wait for 500 microseconds
        digitalWrite(stepPin, LOW);    // Reset step pin
        delayMicroseconds(500);        // Wait for 500 microseconds
    }

    // Move motor in the opposite direction for 1000 steps
    for (int x = 1; x < 1000; x++) {
        digitalWrite(dirPin, LOW);     // Set direction to LOW
        digitalWrite(stepPin, HIGH);   // Take a step
        delayMicroseconds(500);        // Wait for 500 microseconds
        digitalWrite(stepPin, LOW);    // Reset step pin
        delayMicroseconds(500);        // Wait for 500 microseconds
    }

    delay(400); // Wait for 400 milliseconds before repeating the loop
}
