Here is the current code

// Define the LED pin
int ledPin = 13; // Most Arduinos have an on-board LED on pin 13

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  // Start serial communication at a baud rate of 9600
  Serial.begin(9600);
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Read the incoming byte
    char receivedChar = Serial.read();
    // If '1' is received, turn on the LED
    if (receivedChar == '1') {
      digitalWrite(ledPin, HIGH); // Turn on the LED
    }
    // If '0' is received, turn off the LED
    else if (receivedChar == '0') {
      digitalWrite(ledPin, LOW); // Turn off the LED
    }
  }
}
