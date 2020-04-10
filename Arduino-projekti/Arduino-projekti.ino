#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Initialize variables for pins
int waterPumpPin = 8, waterLevelPin = A0, humidityPin = A1;

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
  Serial.println(waterPumpPin);
  digitalWrite(waterPumpPin, HIGH);
  delay(1000);
  digitalWrite(waterPumpPin, LOW);
}

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // Set pin 13 to output mode for speaker
  pinMode(13, OUTPUT);
  // Set pin 8 to output mode for water pump
  pinMode(8, OUTPUT);
  // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  lcd.begin(16, 2);
}

// the loop routine runs over and over again forever:
void loop() {

  // Clear screen if water level or humidity is below 100
  if (getWaterLevel() < 100 || getHumidity() < 100) {
    lcd.clear();
  }

  // print values to lcd
  lcd.setCursor(0, 0);
  lcd.print("Veden maara: ");
  lcd.setCursor(0, 1);
  lcd.print("Kosteus: ");
  lcd.setCursor(12, 0);
  lcd.print(getWaterLevel());
  lcd.setCursor(12, 1);
  lcd.print(getHumidity());


  // Play tone if water level drops
  if (getWaterLevel() < 300) {
    tone(13, 1000, 200);
  }

  // Start water pump is humidity is too low
  if (getHumidity() < 200) {
    startWaterPump();
  }

  delay(1);        // delay in between reads for stability
}
