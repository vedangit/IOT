#include "flexsensor.h"

void setupFlexSensor() {
    pinMode(FLEX_PIN, INPUT);
}

int readFlexSensor() {
    return analogRead(FLEX_PIN);
}

bool isTreeCutDetected(int flexValue, int threshold) {
    return flexValue < threshold; // Assuming lower values indicate more bending
}
