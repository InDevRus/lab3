#include <Arduino.h>
#include <Servo.h>

#include "components/Sensor.h"

const auto delayDuration = 30;

const auto echoPin = 10;
const auto triggerPin = 11;
const auto servoPin = 35;

const auto monitorBaudRate = 115200;

Sensor sensor(echoPin, triggerPin);
Servo servo;

void setup()
{
    Serial.begin(monitorBaudRate);
    servo.attach(servoPin);
}

void loop()
{
    for (auto angle = 0; angle <= 180; angle++)
    {
        servo.write(angle);
        auto distance = sensor.measure();
        printData(angle, distance);

        delay(delayDuration);
    }

    for (int angle = 180; angle >= 0; angle--)
    {
        servo.write(angle);
        auto distance = sensor.measure();
        printData(angle, distance);

        delay(delayDuration);
    }
}

void printData(int angle, float distance)
{
    auto string = String(angle) + "\t" + String(distance);
    Serial.println(string);
}