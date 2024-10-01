#include <Arduino.h>
#include "tempsensor.h"
#include "rfid.h"

void setup() {
    // Call the setup functions for the sensors
    setupTemperatureSensor();
    setupRFID();
    setupServo();
}

void loop() {
    // Read temperature and humidity
    float temperature = readTemperature();
    float humidity = readHumidity();
    
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" *C ");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Read and print the card UID
    readCardUID();

    delay(1000); // Delay to prevent spamming the output
}
