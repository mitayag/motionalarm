/*
MIT License
Copyright 2021 Michael Schoeffler (https://www.mschoeffler.com)
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
/*
* This example source code is part of a tutorial on how to use the HC-SR501 PIR sensor with an Arduino Uno. 
*/

#define PIN_PIRSENSOR 2
//#define PIN_LED 
//int PINLED=7;
int alarmSwitch=7;



void setup() {
  Serial.begin(9600); // start serial connection to print out messages to the serial monitor
  pinMode(PIN_PIRSENSOR, INPUT); 
  pinMode(alarmSwitch, OUTPUT);
  digitalWrite(alarmSwitch, LOW); // switch off the Arduino's in-built LED 
}

void loop() {

  //MOTION DETECTION LOOP
  int movement_detected = digitalRead(PIN_PIRSENSOR);  
  if (movement_detected) {
    // movement has been detected by the HC-SR501 PIR sensor
    digitalWrite(alarmSwitch, HIGH); // switch on the Arduino's in-built LED 
    Serial.println("Movement detected.");
    //Code for triggering Alarm and sending SMS





  } else {
    digitalWrite(alarmSwitch, LOW); // switch off the Arduino's in-built LED 
    Serial.println("Movement not detected.");
    

  }
  delay(1000); // wait for one second until the next check


}