//tredje test
#define HEATER_PIN 13     // Pin for spenningsforsyning til varmeelement
#define TEMPERATURE_PIN A0 // Pin for temperatursensor

double Setpoint = 38.0; // Ønsket temperatur i Celsius
double Hysteresis = 0.5; // Dødband rundt Setpoint
int WindowSize = 5000;  // Vindustid for regulering (i millisekunder)
int P_value = 50;       // Proporsjonal konstant

unsigned long windowStartTime; // Variabel for lagring av starttidspunktet for regulering

// Deklarasjon av funksjonen
double readTemperature();

void setup() {
  Serial.begin(9600); // Start seriell kommunikasjon
  pinMode(HEATER_PIN, OUTPUT); // Sett varmeelementpinne som utgang
  windowStartTime = millis();    // Lagre starttidspunktet for regulering
}

void loop() {
  double temperature = readTemperature(); // Les temperatur fra sensoren
  
  // Beregn feil mellom ønsket temperatur og målt temperatur
  double error = Setpoint - temperature;
  
  // Proporsjonal regulering
  int output = P_value * error;
  
  // Sett en grense for lavere regulert utgang
  if (output < 0) {
    output = 0;
  }
  
  // Skru på varmeelementet basert på regulert utgang og dødband
  if (temperature < Setpoint - Hysteresis) {
    digitalWrite(HEATER_PIN, HIGH);
  } else if (temperature > Setpoint + Hysteresis || output > millis() - windowStartTime) {
    analogWrite(HEATER_PIN, min(output, 255)); // PWM-styring av varmeelement
    windowStartTime = millis(); // Oppdater starttidspunktet for regulering
  } else {
    digitalWrite(HEATER_PIN, LOW);
  }
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C, Output: ");
  Serial.println(output);
  
  delay(1000); // Vent 1 sekund før du leser temperaturen igjen
}

// Definisjon av funksjonen
double readTemperature() {
  int sensorValue = analogRead(TEMPERATURE_PIN); // Les analog verdi fra temperatursensoren
  double temperature = sensorValue * (5.0 / 1023.0 * 100.0); // Konverter analog verdi til temperatur i Celsius
  return temperature;
}
