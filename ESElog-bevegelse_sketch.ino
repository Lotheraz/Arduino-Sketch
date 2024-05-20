const int dirPin = 4;
const int stepPin = 3;
const int enPin = 2;
const int sensorDigitalPin =32;

void setup() {
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    pinMode(enPin, OUTPUT);
    pinMode(sensorDigitalPin, INPUT);
    digitalWrite(enPin, LOW); // Aktiverer motoren
    Serial.begin(9600);
}

void loop() {
    int sensorValue = digitalRead(sensorDigitalPin); // Les verdien fra sensoren
    digitalWrite(dirPin, HIGH);
    while (digitalRead(sensorDigitalPin) == LOW) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(200);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(200);
    }
    
    // Hvis sensoren er utløst, stopp motoren og forbered deg på å bevege den nedover
    if (sensorValue == HIGH) {
        Serial.println("Grensen nådd, beveger seg ned");
        moveMotor(false, 10300); // Bytt retning og beveg deg ned
        delay(2000); // Vent 2 sekunder ved første stopp-posisjon
        moveMotor(false, 1050); // Beveg deg nedover
        delay(2000); // Vent 2 sekunder ved andre stopp-posisjon
        moveMotor(false, 1050); // Beveg deg nedover
        delay(2000); // Vent 2 sekunder ved tredje stopp-posisjon
         moveMotor(false, 1050); // Beveg deg nedover
        delay(2000); // Vent 2 sekunder ved fjerde stopp-posisjon
         moveMotor(false, 1050); // Beveg deg nedover
        delay(2000); // Vent 2 sekunder ved femte stopp-posisjon
         moveMotor(false, 1050); // Beveg deg nedover
        delay(2000); // Vent 2 sekunder ved sjette stopp-posisjon
         moveMotor(false, 1050); // Beveg deg nedover
        delay(2000); // Vent 2 sekunder ved sivene stopp-posisjon
         moveMotor(false, 1050); // Beveg deg nedover
        delay(2000); // Vent 2 sekunder ved åttende stopp-posisjon
        // Fortsett med andre stopp-posisjoner etter behov
    } else {
        moveMotor(true, 200); // Fortsett å bevege deg opp
    }
    delay(200);
}

void moveMotor(bool directionUp, int steps) {
    digitalWrite(enPin, LOW); // Aktiverer motoren
    digitalWrite(dirPin, directionUp ? HIGH : LOW); // Setter retning

    // Utfør steg
    int x = 0;
    while (x < steps) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(200);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(200);
        x++;
    }

    // Valgfritt kan du deaktivere motoren etter bevegelsen
    // digitalWrite(enPin, HIGH);
}


//I denne koden legger vi til flere `moveMotor`-kall etter det første `moveMotor(false, 8000);`-kallet.
// Hver `moveMotor`-funksjon har en tilsvarende forsinkelse (i dette tilfellet 2 sekunder) før du beveger deg videre til neste
//stopp-posisjon. vi kan justere forsinkelsen og antall steg for hver stopp-posisjon etter behov.
