const int dirPin = 7;  // Direction pin for the stepper motor
const int stepPin = 6; // Step pin for the stepper motor
const int enPin = 5;   // Enable pin for the stepper motor
const int tid = 2000;  // Time duration for each operation in milliseconds (10 seconds)

void setup() {
    pinMode(stepPin, OUTPUT); // Set step pin as an output
    pinMode(dirPin, OUTPUT);  // Set direction pin as an output
    pinMode(enPin, OUTPUT);   // Set enable pin as an output
    digitalWrite(enPin, LOW); // Enable the motor
    Serial.begin(9600);       // Initialize serial communication
}

void loop() {
    runPump(dirPin, stepPin, enPin, tid, true);  // Call function to suck
    delay(400); // Wait 2 seconds between operations
    runPump(dirPin, stepPin, enPin, tid, false); // Call function to push
    delay(400); // Wait 2 seconds between operations
}

void runPump(int dirPin, int stepPin, int enPin, unsigned long tid, bool suck) {
    // Activate the pump (send continuous step signals) for the specified time
    unsigned long startTime = millis(); // Store the start time
    digitalWrite(dirPin, suck ? HIGH : LOW); // Set direction based on the operation

    while (millis() - startTime < tid) { // As long as the specified time has not passed
        // Send a step signal
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(325); // Adjust this to change the step speed
        digitalWrite(stepPin, LOW);
        delayMicroseconds(325); // Adjust this to change the step speed
    }

    // Turn off the pump after the specified time
    digitalWrite(enPin, HIGH); // Disable the motor
    delay(100); // Short delay to ensure the motor is properly turned off
    digitalWrite(enPin, LOW); // Re-enable the motor for the next operation
}
