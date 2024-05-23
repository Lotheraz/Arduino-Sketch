#include <Wire.h>

byte val = 0;

void setup() {
  
  Wire.begin(); // Join I2C bus
  Serial.begin(9600);

  byte address = 0x2A;
  // configure ADC
  Wire.beginTransmission(address);
  Wire.write(0x02);
  Wire.write(0x06);
  Wire.write(0xC0);
  Wire.endTransmission();  

  byte channel;
  int channel_number = 1;
  switch (channel_number){
    case 1:
      channel = 0x01;
      break;
    case 2:
      channel = 0x02;
      break;
    case 3:
      channel = 0x04;
      break;
    case 4:
      channel = 0x08;
      break;
  }


  select_channel(address, channel);
  
  Wire.requestFrom(0x2A, 1); 
  delay(5); 
  uint8_t buf[1];
  Wire.readBytes(buf, 1);
  Serial.println("channel configuration:");
  readbyte(buf[0]);
  Serial.println();
}

void loop() {

  
  Wire.beginTransmission(0x2A);    // Get the slave's attention, tell it we're sending a command byte
  Wire.write(0x00);
  Wire.endTransmission();  

  delay(50);
  
  int N_channels = 1;
  Serial.println("new measurement:");
  for (int n = 1; n<=N_channels; n++){

    Wire.requestFrom(0x2A,2,true); // This register is 16 bits = 2 bytes long
    delay(5); // Wait for data to be available
    
    uint8_t by1[2];
    int counter = 0;
    while(Wire.available()) {
          by1[counter] = Wire.read();    // Receive a byte as character
          //Serial.print("Byte number");
          //Serial.print(counter);
          //Serial.print(" : ");
          //Serial.println(by1[counter],BIN); 

          //readbyte(by1[counter]);
          //Serial.println();

          
          counter ++;       // Print the character
    }
    getchannel(by1[0]);
    get_value(by1[0],by1[1]);
    Serial.println();
    
}
    

      Serial.println();
      Serial.println();
    
   delay(2000);
}

void readbyte(uint8_t byte_in){
  for (int b = 7; b >=0 ; b--) {
        byte bit = bitRead(byte_in, b);
        Serial.print(bit);
  }
}

void getchannel(uint8_t byte1){
  Serial.print("channel number:");
  for (int b = 7; b >=4; b--) {
        byte bit = bitRead(byte1, b);
        Serial.print(bit);
  }
  Serial.println();
}

void get_value(uint8_t byte1, uint8_t byte2){
  //Serial.println("value:");

  uint16_t pressure_value;
  for (int b = 3; b >=0 ; b--) {
        byte bit = bitRead(byte1, b);
        bitWrite(pressure_value,b+8,bit);
        //Serial.print(bit);
  }
  for (int b = 7; b >=0 ; b--) {
        byte bit = bitRead(byte2, b);
        bitWrite(pressure_value,b,bit);

        //Serial.print(bit);
  }

  Serial.println();
  Serial.print("pressure value = ");
  Serial.println(pressure_value);

  //for (int b=15;b>=0;b--){
  //  Serial.print(bitRead(pressure_value,b));
  //}
}

void select_channel(byte address, byte channel) {
  Serial.println("configure channel");
  Wire.beginTransmission(address);   
  Wire.write(0x01);
  Wire.write(channel);
  Wire.endTransmission();  
}