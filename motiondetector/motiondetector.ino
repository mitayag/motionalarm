/*

Program: Motion Detector with Alarm and SMS

*/

#include <SoftwareSerial.h>


//Configure the GMS settings
SoftwareSerial sim(10, 11);
int _timeout;
String _buffer;
String number = "+639978264419"; //-> change with your number






#define PIN_PIRSENSOR 2
int alarmSwitch=7;


#define PIN_RELAY_1  3 // the Arduino pin, which connects to the IN1 pin of relay module


void setup() {
  Serial.begin(9600); // start serial connection to print out messages to the serial monitor
  pinMode(PIN_PIRSENSOR, INPUT); 
  pinMode(alarmSwitch, OUTPUT);
  pinMode(PIN_RELAY_1, OUTPUT);
  digitalWrite(alarmSwitch, LOW); // switch off the Arduino's in-built LED 
  Serial.println("Switch OFF.");
  digitalWrite(PIN_RELAY_1, LOW);

  sim.begin(9600);
   _buffer.reserve(50);
  Serial.println("System Started...");

  
}

void loop() {

  //MOTION DETECTION LOOP
  int movement_detected = digitalRead(PIN_PIRSENSOR);  
  if (movement_detected) {
    // movement has been detected by the HC-SR501 PIR sensor
    digitalWrite(alarmSwitch, HIGH); // switch on the Arduino's in-built LED 
    Serial.println("Movement detected.");
    //Code to trigger SMS


    //Code to trigger Alarm
    Serial.println("Turn on relays");
    digitalWrite(PIN_RELAY_1, HIGH);
    delay(2000);
    //Serial.println("Turn off relays");
    //digitalWrite(PIN_RELAY_1, LOW);
    
    SendMessage();
    //callNumber();

  } else {
    digitalWrite(alarmSwitch, LOW); // switch off the Arduino's in-built LED 
    Serial.println("Movement not detected.");

    Serial.println("Turn off relays");
    //digitalWrite(PIN_RELAY_1, LOW);

    

  }
  delay(1000); // wait for one second until the next check

}

void callNumber() {
  Serial.println("Calling Number");
  sim.print("ATD");
  sim.print(number);
  sim.print(";\r\n");
  delay(1000); // Wait for the call to be initiated
  //_buffer = _readSerial();
  Serial.println(_buffer);
}

void SendMessage() {
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  sim.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  sim.print("AT+CMGS=\"+639978264419\"\r");  //Your phone number don't forget to include your country code, example +212123456789"
  delay(500);
  sim.print("Intruder Detected");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
  sim.print((char)26);// (required according to the datasheet)
  delay(500);
  sim.println();
  Serial.println("Text Sent.");
  delay(500);

}