int pinSensor = 11;
int pinLED = 13;
int val = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(pinLED, OUTPUT);
  pinMode(pinSensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(pinSensor);
  if (val == HIGH) {
    digitalWrite(pinLED, HIGH);
    delay(val);
    digitalWrite(pinLED, LOW);
    delay(val);
    Serial.println(val, DEC);
    val = -1;
  } else {
    Serial.println("Nothing!");
  }
}
