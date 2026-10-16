#include <LiquidCrystal.h>

// LCD connections: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// PT100 circuit output
const int sensorPin = A0;

// Quadratic calibration coefficients
const float a = -0.0038928;
const float b = 2.51821;
const float c = -225.5925;

// ADC smoothing parameters
float smoothedADC = 0.0;
const float oldWeight = 0.85;
const float newWeight = 0.15;

// Number of ADC samples
const int sampleCount = 64;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);

  // Initialize the ADC reading
  long sum = 0;

  for (int i = 0; i < sampleCount; i++) {
    sum += analogRead(sensorPin);
    delay(2);
  }

  smoothedADC = (float)sum / sampleCount;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PT100 Thermometer");

  lcd.setCursor(0, 1);
  lcd.print("Initializing...");

  delay(1000);
  lcd.clear();
}

void loop() {
  long sum = 0;

  // Collect ADC readings
  for (int i = 0; i < sampleCount; i++) {
    sum += analogRead(sensorPin);
    delayMicroseconds(250);
  }

  // Calculate average ADC value
  float currentAvg = (float)sum / sampleCount;

  // Apply smoothing filter
  smoothedADC =
      (oldWeight * smoothedADC) +
      (newWeight * currentAvg);

  // Calculate temperature
  float x = smoothedADC;

  float temperature =
      (a * x * x) +
      (b * x) +
      c;

  // Display temperature on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.write((uint8_t)223);
  lcd.print("C   ");

  // Display ADC value
  lcd.setCursor(0, 1);
  lcd.print("ADC: ");
  lcd.print((int)smoothedADC);
  lcd.print("       ");

  // Print readings to Serial Monitor
  Serial.print("ADC: ");
  Serial.print(smoothedADC, 2);

  Serial.print(" | Temperature: ");
  Serial.print(temperature, 2);
  Serial.println(" C");

  delay(200);
}