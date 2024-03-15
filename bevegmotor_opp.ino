const int dirPin = 9;
const int stepPin = 10;
const int enPin = 11;
const int sensorDigitalPin = 8 ;
void setup() {
    pinMode(stepPin,OUTPUT);//output fordi de skal styre motoren
    pinMode(dirPin,OUTPUT);// output fordi de skal styre motoren
    pinMode(enPin,OUTPUT);//output fordi de skal styre motoren
    pinMode(sensorDigitalPin,INPUT);// input fordi den skal lese verdier fra nærhetssensor
    digitalWrite(enPin, LOW); // motor er aktivt
    Serial.begin(9600);   
    ;
}

void loop() {
  int sensorValue = digitalRead(sensorDigitalPin);// les sensorverdien
  if(sensorValue == HIGH){
    digitalWrite(enPin, HIGH); // stop motoren
    Serial.println("Pumpe stopper. water level reached");
  } else {
  }// fortsatt å kjøre pumpen hvis vannivået ikke er nådd
  // kode for å kjøre motoren


   for(int x = 1; x<1000; x++){
      digitalWrite(dirPin,HIGH);
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(500);
    }

    

     /*for(int x = 1; x<1000; x++){
      digitalWrite(dirPin,LOW);
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(500);
    
    }*/

  delay(400);
  }
