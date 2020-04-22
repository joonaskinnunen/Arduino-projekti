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
  delay(2000);
  digitalWrite(waterPumpPin, LOW);
  #if DEBUG
    Serial.println("Water pump turned off");
  #endif
}
  //Function for playing tone if water level drops
 void startSpeaker() {
    #if DEBUG
      Serial.println("Water level too low. Playing tone");
    #endif
    tone(13, 880, 300);
     delay(450);
    tone(13, 784, 300);
     delay(450);
    tone(13, 659, 550);
     delay(1000);
    tone(13, 880, 150);
     delay(200);
    tone(13, 784, 200);
     delay(450);
    tone(13, 659, 550);
     delay(1300);
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
  
  // Update the values of the variables if the values of the sensors change enough. This prevents the screen from flashing unnecessarily and the display values are easier to read.
  if(getWaterLevel() < waterLevel - 10 || getWaterLevel() > waterLevel + 10) {
    waterLevel = getWaterLevel();
    lcd.setCursor(13, 0);
    lcd.print("   ");
    lcd.setCursor(9, 1);
    lcd.print("   ");
  }
    
  if(getHumidity() < humidity - 10 || getHumidity() > humidity + 10) {
    humidity = getHumidity();
    lcd.setCursor(7, 0);
    lcd.print("    ");
    lcd.setCursor(10, 1);
    lcd.print("    ");
  }

  // print values to lcd
  lcd.setCursor(0, 0);
  lcd.print("Water: ");
  lcd.print((float)waterLevel / 630 * 100, 0);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Moisture: ");
  lcd.print((float)humidity / 630 * 100, 0);
  lcd.print("%");

  // Start water pump is humidity is too low
  if (humidity < 120) {
    #if DEBUG
      Serial.println("Humidity too low. Starting water pump");
    #endif
    startWaterPump();
  }
  
  //Play tone if water level is too low
  if (waterLevel < 200) {
    startSpeaker();
  }

  delay(1);        // delay in between reads for stability
}
