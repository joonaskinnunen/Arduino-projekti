#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define DEBUG 1

// Define distance sensor pins
#define TRIG_PIN 6
#define ECHO_PIN 7

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

float getHeight()
{
  // The distance sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  float duration = pulseIn(ECHO_PIN, HIGH);

  // convert the time into a distance in centimeters. Sound velocity in air: 343 m/s -> 0,0343 cm/us.
  float cm = (duration / 2) * 0.0343;
  
  // height = zero point - measured distance. Zero point: sensor distance from plant's stem.
  float zpoint = 50;
  float height = zpoint - cm;

#if DEBUG
  Serial.print("Echo reading:\t");
  Serial.println(duration);
  Serial.print("Measured distance in cm:\t");
  Serial.println(cm);
  Serial.print("Calculated height in cm:\t");
  Serial.println(height);  
#endif

  return height;
}

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // Set TRIG_PIN to output mode
  pinMode(TRIG_PIN, OUTPUT);
  // Set ECHO_PIN to input mode
  pinMode(ECHO_PIN, INPUT);
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
  if (getWaterLevel() < waterLevel - 10 || getWaterLevel() > waterLevel + 10) {
    waterLevel = getWaterLevel();
  }

  if (getHumidity() < humidity - 10 || getHumidity() > humidity + 10) {
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

  delay(5000);        // delay before changing display output

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pituus: ");
  lcd.print(getHeight());
  lcd.setCursor(14,0);
  lcd.print("cm");

  delay(5000);        // delay before changing display output
}
