// Include necessary libraries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define pin numbers for sensors and solenoid valves
const int phSensorPin = A0;
const int tdsSensorPin = A1;
const int solenoidValvePin = 2;

// Other global variables and constants
float phValue = 0.0;
float tdsValue = 0.0;

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);

  // Initialize LCD
  LiquidCrystal_I2C lcd(0x27, 16, 2);
  lcd.init();
  lcd.backlight();

  // Initialize solenoid valve pin
  pinMode(solenoidValvePin, OUTPUT);
}

void loop() {
  // Read sensor values
  phValue = analogRead(phSensorPin);
  tdsValue = analogRead(tdsSensorPin);

  // Perform necessary actions based on sensor readings
  if (phValue < PH_THRESHOLD && tdsValue < TDS_THRESHOLD) {
    activateSolenoidValve();
  } else {
    deactivateSolenoidValve();
  }

  // Display sensor readings on LCD
  displaySensorReadings(phValue, tdsValue);

  // Delay for stability
  delay(1000);
}

void activateSolenoidValve() {
  digitalWrite(solenoidValvePin, HIGH);
}

void deactivateSolenoidValve() {
  digitalWrite(solenoidValvePin, LOW);
}

void displaySensorReadings(float ph, float tds) {
  Serial.print("pH: ");
  Serial.print(ph);
  Serial.print("\tTDS: ");
  Serial.println(tds);
}
