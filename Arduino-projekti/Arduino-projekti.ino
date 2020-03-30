#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Initialize variables for pins
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

// Function to start water pump
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
  // Set pin 13 to output mode for speaker
  pinMode(13, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Veden maara: ");
  lcd.setCursor(0, 1);
  lcd.print("Kosteus: ");
}

// the loop routine runs over and over again forever:
void loop() {
  // print values to lcd
  lcd.setCursor(12, 0);
  lcd.print(getWaterLevel());
  lcd.setCursor(12, 1);
  lcd.print(getHumidity());
  // Play tone if water level drops
  if (getWaterLevel() < 200) {
    tone(13, 1000, 200);
  }
  if (getHumidity() < 200) {
    startWaterPump();
  }
  delay(1);        // delay in between reads for stability
}
