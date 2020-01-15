#include <Arduino.h>

#include "components/Rotor.h"
#include "components/Sensor.h"

const auto delayDuration = 20;
const auto distanceLimit = 40;

const auto echoPin = 10;
const auto triggerPin = 11;
const auto rotorPin = 20;

const auto monitorBaudRate = 115200;

Sensor sensor(echoPin, triggerPin);
Rotor rotor(rotorPin);

void setup()
{
    Serial.begin(monitorBaudRate);
}

void loop()
{
    auto angle = rotor.getAngle();
    auto distance = sensor.measure();
    if (distance <= distanceLimit)
        printData(angle, distance);

    delay(delayDuration);

    rotor.stepRotate();
}

void printData(int angle, float distance)
{
    auto string = String(angle) + String(5 - String(angle).length(), ' ') + String(distance);
    Serial.println(string);
}