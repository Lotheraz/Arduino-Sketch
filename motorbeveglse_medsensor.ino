const int dirPin = 9;
const int stepPin = 10;
const int enPin = 11;
const int sensorDigitalPin = 8;

void setup() {
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    pinMode(enPin, OUTPUT);
    pinMode(sensorDigitalPin, INPUT);
    digitalWrite(enPin, LOW); // Enable the motor
    Serial.begin(9600);
}

void loop() {
    // Check if data is available to read
    if (Serial.available() > 0) {
        // Read the incoming string
        String receivedString = Serial.readStringUntil('\n');

        // Check if the received string is "11"
        if (receivedString == "11") {
            moveMotorUpUntilSensorTriggered();
            moveMotorDownAfterTrigger();
        }
    }
}

void moveMotorUpUntilSensorTriggered() {
    // Move up until the sensor is triggered
    digitalWrite(dirPin, HIGH); // Set direction up
    while(digitalRead(sensorDigitalPin) == LOW) {
        // Sensor has not triggered yet, keep moving
        digitalWrite(stepPin, HIGH);
        Serial.println("Calibration in progress");
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(1000);
    }
    Serial.println("Limit reached");
}

void moveMotorDownAfterTrigger() {
    // Move down a certain number of steps after the sensor is triggered
    Serial.println("Calibration in progress");
    moveMotor(false, 16000); // Reverse direction and move down
}

void moveMotor(bool directionUp, int steps) {
    digitalWrite(enPin, LOW); // Enable the motor
    digitalWrite(dirPin, directionUp ? HIGH : LOW); // Set direction

    // Perform steps
    for (int x = 0; x < steps; x++) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(1000);
    }
    // Optionally, you can disable the motor after the move
    // digitalWrite(enPin, HIGH); // Disable the motor
}
