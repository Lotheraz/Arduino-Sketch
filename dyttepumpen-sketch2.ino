//kode for dytte som fungerte
const int dirPin = 33;
const int stepPin = 12;
const int enPin = 11;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);
  Serial.begin(9600);
}

void loop() {
  dyttePumpe(33,12,11, 1000);
}
void dyttePumpe(int dirPin, int stepPin, int endPin, unsigned long tid){
  // Aktiverer pumpen (sender kontinuerlige stegsignaler) i 10 sekunder
  unsigned long startTime = millis(); // Lagrer starttiden

  // Setter retning til å dytte væsken
  digitalWrite(dirPin, HIGH);

  while (millis() - startTime < 10000) { // Så lenge det ikke har gått 10 sekunder
    // Sender et stegsignal
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(400); // Du kan endre denne for å justere steghastigheten
    digitalWrite(stepPin, LOW);
    delayMicroseconds(400); // Du kan endre denne for å justere steghastigheten
  }
  
  // Slår av pumpen etter 10 sekunder
  digitalWrite(enPin, HIGH); // Slår av motoren

  // Stopper loopen, slik at koden ikke kjører igjen
  while (true) {}
}
