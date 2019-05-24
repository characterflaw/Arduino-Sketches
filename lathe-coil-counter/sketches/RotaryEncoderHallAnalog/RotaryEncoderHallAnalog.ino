int pinSensor = A5;
int pinSwitch = 11;
int pinLED = 13;
int sensorValue = 0;

int ctr = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinSwitch, INPUT);
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(pinSensor);
  Serial.println(sensorValue, DEC);

  if (sensorValue < 500)
    if (pinSwitch  == HIGH)
      ctr++;
    else 
      ctr--;
      
  Serial.print("Counter: ");
  Serial.println(ctr, DEC);
  
  delay(250);
}


/*  switch circuit
      - one side to D11
      - one side to ~680k resistor, then ground
 */
