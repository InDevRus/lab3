#include <Arduino.h>

class Sensor
{
private:
    const float soundSpeedMeterPerSecond = 340.0;
    const float soundSpeedCmPerSecond = soundSpeedMeterPerSecond / 10000.0;

    int echoPin, triggerPin;

public:
    Sensor(int echoPin, int triggerPin);
    ~Sensor();

    float measure();
};

Sensor::Sensor(int echoPin, int triggerPin)
{
    this->echoPin = echoPin;
    this->triggerPin = triggerPin;

    pinMode(echoPin, INPUT);
    pinMode(triggerPin, OUTPUT);
    digitalWrite(triggerPin, LOW);
}

Sensor::~Sensor()
{
}

float Sensor::measure()
{
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    auto duration = pulseIn(echoPin, HIGH);
    return duration * soundSpeedCmPerSecond / 2.0;
}