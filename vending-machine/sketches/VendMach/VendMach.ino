long baudRate = 9600;
int digitalPin = 11;
int delayTime = 500;
String keyword = "dispense";

void setup() {
    //  set up digital pin to relay
    pinMode(digitalPin, OUTPUT);

  // Open serial communications and wait for port to open:
  Serial.begin(baudRate);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() { // run over and over
  if (Serial.available() > 0) {
    if (Serial.readString() == keyword ) {

      // respond with acknowledgement
      Serial.println("ACK");

      digitalWrite(digitalPin, HIGH);
      delay(delayTime);
      digitalWrite(digitalPin, LOW);

    }
  }
}
