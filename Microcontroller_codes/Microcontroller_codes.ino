#include <SoftwareSerial.h>

#define GSM_TX_PIN 2
#define GSM_RX_PIN 3

const int relayPin1 = 7;
const int relayPin2 = 6;

SoftwareSerial gsmSerial(GSM_TX_PIN, GSM_RX_PIN);

void setup() {
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  
  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, LOW);

  Serial.begin(9600);
  gsmSerial.begin(9600);
  delay(1000);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      digitalWrite(relayPin1, !digitalRead(relayPin1));
      if (digitalRead(relayPin1) == HIGH) {
        sendSMS("Relay 1 triggered");
      }
    }
    else if (command == '2') {
      digitalWrite(relayPin2, !digitalRead(relayPin2));
      if (digitalRead(relayPin2) == HIGH) {
        sendSMS("Relay 2 triggered");
      }
    }
  }
}

void sendSMS(String message) {
  gsmSerial.println("AT+CMGF=1");
  delay(1000);
  
  gsmSerial.print("AT+CMGS=\"");
  gsmSerial.print("RECIPIENT_PHONE_NUMBER");
  gsmSerial.println("\"");
  delay(1000);
  
  gsmSerial.print(message);
  gsmSerial.write(0x1A);
  delay(1000);
}
