const int dirPin = 4;          // Direction pin for the stepper motor
const int stepPin = 3;         // Step pin for the stepper motor
const int enPin = 2;           // Enable pin for the stepper motor
const int sensorDigitalPin = 32; // Digital pin for the sensor

void setup() {
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    pinMode(enPin, OUTPUT);
    pinMode(sensorDigitalPin, INPUT);
    digitalWrite(enPin, LOW); // Enable the motor
    Serial.begin(9600);
}

void loop() {
    int sensorValue = digitalRead(sensorDigitalPin); // Read the sensor value
    digitalWrite(dirPin, HIGH); // Set direction to HIGH
    while (digitalRead(sensorDigitalPin) == LOW) { // While sensor is not triggered
        digitalWrite(stepPin, HIGH); // Step the motor
        delayMicroseconds(200);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(200);
    }
    
    // If the sensor is triggered, stop the motor and prepare to move it down
    if (sensorValue == HIGH) {
        Serial.println("Limit reached, moving down");
        moveMotor(false, 10300); // Reverse direction and move down
        delay(2000); // Wait 2 seconds at the first stop position
        moveMotor(false, 1050); // Move down
        delay(2000); // Wait 2 seconds at the second stop position
        moveMotor(false, 1050); // Move down
        delay(2000); // Wait 2 seconds at the third stop position
        moveMotor(false, 1050); // Move down
        delay(2000); // Wait 2 seconds at the fourth stop position
        moveMotor(false, 1050); // Move down
        delay(2000); // Wait 2 seconds at the fifth stop position
        moveMotor(false, 1050); // Move down
        delay(2000); // Wait 2 seconds at the sixth stop position
        moveMotor(false, 1050); // Move down
        delay(2000); // Wait 2 seconds at the seventh stop position
        moveMotor(false, 1050); // Move down
        delay(2000); // Wait 2 seconds at the eighth stop position
        // Continue with additional stop positions as needed
    } else {
        moveMotor(true, 200); // Continue moving up
    }
    delay(200);
}

void moveMotor(bool directionUp, int steps) {
    digitalWrite(enPin, LOW); // Enable the motor
    digitalWrite(dirPin, directionUp ? HIGH : LOW); // Set direction

    // Perform steps
    int x = 0;
    while (x < steps) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(200);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(200);
        x++;
    }

    // Optionally, you can disable the motor after the move
    // digitalWrite(enPin, HIGH);
}
