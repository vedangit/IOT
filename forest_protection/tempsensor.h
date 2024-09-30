#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

#include <DHT.h>
#include <DHT_U.h>

// Pin and type definitions
#define DHTPIN 2      // Pin connected to the DHT22 data pin
#define DHTTYPE DHT22 // Define the type of sensor

// Function declarations
void setupTemperatureSensor();
float readTemperature();
float readHumidity();
void printReadings(float temperature, float humidity);
bool isFireDetected(float temperature);

#endif // TEMPSENSOR_H
