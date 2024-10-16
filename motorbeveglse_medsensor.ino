const int dirPin = 10;          // Direction pin for the stepper motor
const int stepPin = 9;          // Step pin for the stepper motor
const int enPin = 8;            // Enable pin for the stepper motor
const int sensorDigitalPin = 31; // Digital pin for the sensor

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
        delayMicroseconds(500);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(500);
    }
    
    // If the sensor is triggered, stop the motor and prepare to move it down
    if (sensorValue == HIGH) {
        Serial.println("Limit reached, moving down");
        moveMotor(false, 16000); // Reverse direction and move down
    } else {
        moveMotor(true, 200); // Keep moving up
    }
    delay(400);
}

void moveMotor(bool directionUp, int steps) {
    digitalWrite(enPin, LOW); // Enable the motor
    digitalWrite(dirPin, directionUp ? HIGH : LOW); // Set direction

    // Perform steps
    int x = 0;
    while (x < steps) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(500);
        x++;
    }

    // Optionally, you can disable the motor after the move
    // digitalWrite(enPin, HIGH);
}
