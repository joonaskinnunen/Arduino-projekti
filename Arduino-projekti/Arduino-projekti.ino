#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define DEBUG 1

// Initialize variables for pins
int waterPumpPin = 8, waterLevelPin = A0, humidityPin = A1;

// Get water level
int getWaterLevel() {
  int sensorValue = analogRead(waterLevelPin);
  #if DEBUG
    Serial.print("Water level: ");
    Serial.println(sensorValue);
  #endif
  return sensorValue;
}

// Get flower pot humidity
int getHumidity() {
  int sensorValue = analogRead(humidityPin);
  #if DEBUG
    Serial.print("Humidity: ");
    Serial.println(sensorValue);
  #endif
  return sensorValue;
}

// Function to start water pump
void startWaterPump() {
  digitalWrite(waterPumpPin, HIGH);
  #if DEBUG
    Serial.println("Water pump started");
  #endif
  delay(3000);
  digitalWrite(waterPumpPin, LOW);
  #if DEBUG
    Serial.println("Water pump turned off");
  #endif
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
  
  // Initialize variables for sensor values
  static int waterLevel = getWaterLevel(), humidity = getHumidity();
  
  // Clear screen if water level or humidity is below 100
  if (getWaterLevel() < 100 || getHumidity() < 100) {
    lcd.clear();
  }
  
  // Update the values of the variables if the values of the sensors change enough. This prevents the screen from flashing unnecessarily and the display values are easier to read.
  if(getWaterLevel() < waterLevel - 10 || getWaterLevel() > waterLevel + 10) {
    waterLevel = getWaterLevel();
  }

  if(getHumidity() < humidity - 10 || getHumidity() > humidity + 10) {
    humidity = getHumidity();
  }

  // print values to lcd
  lcd.setCursor(0, 0);
  lcd.print("Veden maara: ");
  lcd.print(waterLevel);
  lcd.setCursor(0, 1);
  lcd.print("Kosteus: ");
  lcd.print(humidity);

  // Play tone if water level drops
  if (waterLevel < 300) {
    #if DEBUG
      Serial.println("Water level too low. Playing tone");
    #endif
    tone(13, 1000, 200);
  }

  // Start water pump is humidity is too low
  if (humidity < 200) {
    #if DEBUG
      Serial.println("Humidity too low. Starting water pump");
    #endif
    startWaterPump();
  }

  delay(1);        // delay in between reads for stability
}
