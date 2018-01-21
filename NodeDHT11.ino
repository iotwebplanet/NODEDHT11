// sketch for various DHT humidity/temperature sensors
// orginally Written by ladyada, public domain

//code updated by
//https://github.com/iotwebplanet 
//for node mcu

//download following 2 library to use DHT11/DHT22 sensor

//https://github.com/adafruit/Adafruit_Sensor.git
//https://github.com/adafruit/DHT-sensor-library.git

#include "DHT.h"

//define pin for Uno or Node MCU we have used D6 on node mcu
#define DHTPIN 12     // what digital pin we're connected to arduino or mcu



// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V/+3V in Controller
// Connect pin 2 of the sensor to whatever your DHTPIN is
// ignore pin 3
// Connect pin 4 (on the right) of the sensor to GROUND

 //optional
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor for better response

// Initialize DHT sensor.

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  //setup of serial monitor
  Serial.begin(9600);
  Serial.println("DHTxx test!");

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements. dont reduce this time
  delay(2000);

  // Sensor readings may also be up to 2 seconds 
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
}
