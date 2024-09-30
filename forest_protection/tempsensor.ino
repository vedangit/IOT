#include <DHT.h>
#include <DHT_U.h>
#include "tempsensor.h"

#define DHTPIN 2      // Pin connected to the DHT22 data pin
#define DHTTYPE DHT22 // Define the type of sensor

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setupTemperatureSensor() {
    Serial.begin(9600);
    Serial.println("DHT22 sensor initializing...");
    dht.begin();
}

float readTemperature() {
    float t = dht.readTemperature();
    if (isnan(t)) {
        Serial.println("Failed to read temperature!");
        return -1; // Return -1 if reading fails
    }
    return t;
}

float readHumidity() {
    float h = dht.readHumidity();
    if (isnan(h)) {
        Serial.println("Failed to read humidity!");
        return -1; // Return -1 if reading fails
    }
    return h;
}

void printReadings(float temperature, float humidity) {
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" *C");
}

bool isFireDetected(float temperature) {
    return temperature > 45.0; // Example threshold for fire detection
}
