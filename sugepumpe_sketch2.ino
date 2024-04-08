//kode for suge som fungerte
const int dirPin =33;
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
    
  sugePumpe(33,12,11,6000);
}
void sugePumpe(int dirPin, int stepPin, int endPin, unsigned long tid){
   // Aktiverer pumpen (sender kontinuerlige stegsignaler) i 60 sekunder
  unsigned long startTime = millis(); // Lagrer starttiden
  digitalWrite(dirPin, HIGH);
  while (millis() - startTime < 60000) { // Så lenge det ikke har gått 60 sekunder
    // Sender et stegsignal
    digitalWrite(dirPin, HIGH); // Sett retning til å suge
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500); // Du kan endre denne for å justere steghastigheten
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500); // Du kan endre denne for å justere steghastigheten
     }
  
  // Slår av pumpen etter 60 sekunder
  digitalWrite(enPin, HIGH); // Slår av motoren

  // Stopper loopen, slik at koden ikke kjører igjen
  while (true) {}
}