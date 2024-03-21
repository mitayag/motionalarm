/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-2-channel-relay-module
 */

#define PIN_RELAY_1  3 // the Arduino pin, which connects to the IN1 pin of relay module


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);

  // initialize digital pin as an output.
  pinMode(PIN_RELAY_1, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
  Serial.println("Turn on both relays");
  digitalWrite(PIN_RELAY_1, HIGH);
  
  delay(2000);

  Serial.println("Turn off both relays");
  digitalWrite(PIN_RELAY_1, LOW);
  
  delay(2000);
}
