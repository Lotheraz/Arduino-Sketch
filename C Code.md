Here is the current code


void setup() {
  // Start serial communication at a baud rate of 9600
  Serial.begin(9600);
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Read the incoming string
    String receivedString = Serial.readStringUntil('\n');

    // Print the received string to the Serial Monitor
    Serial.println(receivedString);

    // Check if the received string is "11"
    if (receivedString == "11") {
      // Send back the integer 17
      Serial.println(17);
    }
    // Check if the received string is "12"
    else if (receivedString == "12") {
      // Send back the integer 18
      Serial.println(18);
    }
    // Check if the received string is "13"
    else if (receivedString == "13") {
      // Send back the integer 22
      Serial.println(22);
    }
  }
}
