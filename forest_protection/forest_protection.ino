#include <Arduino.h>
#include "tempsensor.h"
#include "rfid.h"
#include "servo.h"
#include "flex.h"

void setup() {
    // Call the setup functions for the sensors
    setupTemperatureSensor();
    setupRFID();
    setupServo();
    setupFlexSensor();
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

    int flexValue = readFlexSensor();
    Serial.print("Flex Sensor Value: ");
    Serial.println(flexValue);

    // Set a threshold for tree cutting detection
    int threshold = 300; // Adjust this value based on your testing
    if (isTreeCutDetected(flexValue, threshold)) {
        Serial.println("Tree cutting detected!");
        // Implement actions if needed
    }

    delay(1000); // Delay for readability
}
