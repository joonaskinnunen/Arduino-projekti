int waterPumpPin = 1;

// Get water level
int getWaterLevel() {
  int sensorValue = analogRead(A0)
  return sensorValue;
}

// Get flower pot humidity
int getHumidity() {
  int sensorValue = analogRead(A0)
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
  
}

// the loop routine runs over and over again forever:
void loop() {
    if(getHumidity() < 100) {
    startWaterPump();
  }

  }
  delay(1);        // delay in between reads for stability
}
