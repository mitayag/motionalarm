#include <SoftwareSerial.h>
SoftwareSerial sim(10, 11);
int _timeout;
String _buffer;
String number = "+639978264419"; //-> change with your number

void setup() {
  Serial.begin(9600);
  _buffer.reserve(50);
  Serial.println("System Started...");
  sim.begin(9600);
  delay(1000);
  Serial.println("Type 's' to send an SMS, 'r' to receive an SMS, 'c' to make a call, or 'a' to enter AT command mode");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    switch (command) {
      case 's':
        SendMessage();
        break;
      case 'r':
        ReceiveMessage();
        break;
      case 'c':
        callNumber();
        break;
      case 'a':
        ATCommandMode();
        break;
    }
  }

  while (sim.available() > 0) {
    Serial.write(sim.read());
  }
}

void SendMessage() {
  Serial.println("Sending Message");
  sim.println("AT+CMGF=1\r"); // Set SMS mode to text
  delay(100);
  //sim.println("AT+CMGS=\"" + number + "\""); // Set the recipient's number
  sim.println("AT+CMGS=\"+639978264419\"\r");
  delay(100);
  String SMS = "Hello, how are you? Greetings from miliohm.com admin";
  sim.println(SMS);
  delay(100);
  sim.println((char)26); // End of message character (ASCII code of CTRL+Z)
  delay(1000); // Wait for the module to send the message
  _buffer = _readSerial();
  Serial.println(_buffer);
}

void ReceiveMessage() {
  Serial.println("Receiving Message");
  sim.println("AT+CMGF=1"); // Set SMS mode to text
  delay(100);
  sim.println("AT+CNMI=1,2,0,0,0"); // Set to receive SMS automatically
  delay(1000); // Wait for the module to respond
  _buffer = _readSerial();
  Serial.println(_buffer);
}

String _readSerial() {
  _timeout = 0;
  while (!sim.available() && _timeout < 5000) {
    delay(10);
    _timeout += 10;
  }
  if (sim.available()) {
    return sim.readString();
  }
  return "";
}

void callNumber() {
  Serial.println("Calling Number");
  sim.print("ATD");
  sim.print(number);
  sim.print(";\r\n");
  delay(1000); // Wait for the call to be initiated
  _buffer = _readSerial();
  Serial.println(_buffer);
}

void ATCommandMode() {
  Serial.println("Entering AT Command Mode. Enter AT command:");
  while (true) {
    if (Serial.available() > 0) {
      char c = Serial.read();
      sim.write(c);
      if (c == '\r' || c == '\n') {
        Serial.println();
        break;
      }
    }
    if (sim.available() > 0) {
      Serial.write(sim.read());
    }
  }
}
