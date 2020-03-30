int waterPumpPin = 1;
int waterLevelPin = A0;
int humidityPin = A1;

// Get water level
int getWaterLevel() {
  int sensorValue = analogRead(waterLevelPin);
  return sensorValue;
}

// Get flower pot humidity
int getHumidity() {
  int sensorValue = analogRead(humidityPin);
  return sensorValue;
}

//
void startWaterPump() {
  // Wait 12h before starting water pump
  delay(4320000);
  digitalWrite(waterPumpPin, HIGH);
  delay(10000);
  digitalWrite(waterPumpPin, LOW);
}



// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.println(getWaterLevel());
  if (getWaterLevel() < 200) {
    tone(13, 1000, 200);
  }
  if (getHumidity() < 200) {
    startWaterPump();
  }
  delay(1);        // delay in between reads for stability
}
