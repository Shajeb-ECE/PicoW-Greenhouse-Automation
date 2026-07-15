#include <DHT.h>
#include <Adafruit_NeoPixel.h>

#define DHTPIN 4
#define DHTTYPE DHT22
#define LDR_PIN 26
#define SOIL_PIN 27   // New direct pin
#define TANK_PIN 28   // New direct pin
#define RELAY_PIN 15
#define LED_PIN 16
#define NUMPIXELS 16

DHT dht(DHTPIN, DHTTYPE);
Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  dht.begin();
  pixels.begin();
  pixels.clear();
  pixels.show();
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  Serial.println("System Initialized...");
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int lightLevel = analogRead(LDR_PIN);

  // Read the potentiometers directly!
  int soilRaw = analogRead(SOIL_PIN);
  int tankRaw = analogRead(TANK_PIN);
  int soilMoisture = map(soilRaw, 0, 1023, 0, 100);
  int tankLevel = map(tankRaw, 0, 1023, 0, 100);

  if (lightLevel > 2000) {
    for(int i=0; i<NUMPIXELS; i++) { pixels.setPixelColor(i, pixels.Color(150, 150, 150)); }
  } else {
    pixels.clear();
  }
  pixels.show();

  if (soilMoisture < 20) { digitalWrite(RELAY_PIN, HIGH); }
  else { digitalWrite(RELAY_PIN, LOW); }

  Serial.print("--- TELEMETRY --- | ");
  if (isnan(temperature) || isnan(humidity)) {
    Serial.print("Temp: Error | RH: Error | ");
  } else {
    Serial.print("Temp: "); Serial.print(temperature); Serial.print("C | ");
    Serial.print("RH: "); Serial.print(humidity); Serial.print("% | ");
  }
  Serial.print("Light: "); Serial.print(lightLevel); Serial.print(" | ");
  Serial.print("Soil Moisture: "); Serial.print(soilMoisture); Serial.print("% | ");
  Serial.print("Tank Level: "); Serial.print(tankLevel); Serial.println("%");

  delay(2000);
}
