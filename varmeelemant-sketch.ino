#define HEATER_PIN 13     // Pin for power supply to the heating element
#define TEMPERATURE_PIN A0 // Pin for the temperature sensor

double Setpoint = 40;    // Desired temperature in Celsius
double Hysteresis = 0.5; // Deadband around the Setpoint
int WindowSize = 5000;   // Window time for regulation (in milliseconds)
int P_value = 50;        // Proportional constant

unsigned long windowStartTime; // Variable for storing the start time of regulation

// Declaration of the function
double readTemperature();

void setup() {
  Serial.begin(9600);        // Start serial communication
  pinMode(HEATER_PIN, OUTPUT); // Set heater pin as output
  windowStartTime = millis();   // Store the start time of regulation
}

void loop() {
  double temperature = readTemperature(); // Read temperature from the sensor
  
  // Calculate error between desired temperature and measured temperature
  double error = Setpoint - temperature;
  
  // Proportional control
  int output = P_value * error;
  
  // Set a lower limit for regulated output
  if (output < 0) {
    output = 0;
  }
  
  // Turn on the heating element based on regulated output and deadband
  if (temperature < Setpoint - Hysteresis) {
    digitalWrite(HEATER_PIN, HIGH);
  } else if (temperature > Setpoint + Hysteresis || output > millis() - windowStartTime) {
    analogWrite(HEATER_PIN, min(output, 255)); // PWM control of the heating element
    windowStartTime = millis(); // Update the start time of regulation
  } else {
    digitalWrite(HEATER_PIN, LOW);
  }
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C, Output: ");
  Serial.println(output);
  
  delay(1000); // Wait 1 second before reading the temperature again
}

// Definition of the function
double readTemperature() {
  int sensorValue = analogRead(TEMPERATURE_PIN); // Read analog value from the temperature sensor
  double temperature = sensorValue * (5.0 / 1023.0 * 100.0); // Convert analog value to temperature in Celsius
  return temperature;
}
