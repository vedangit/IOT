#ifndef FLEXSENSOR_H
#define FLEXSENSOR_H

#include <Arduino.h>

#define FLEX_PIN A0 // Pin where the flex sensor is connected

void setupFlexSensor();
int readFlexSensor();
bool isTreeCutDetected(int flexValue, int threshold);

#endif
