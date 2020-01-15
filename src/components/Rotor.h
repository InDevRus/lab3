#include <Servo.h>
#include <Math.h>

class Rotor
{
private:
    Servo servo;
    int angleDifference = 1;
    int currentAngle = 0;

public:
    Rotor(int motorPin);
    ~Rotor();

    void stepRotate();
    int getAngle();
};

Rotor::Rotor(int motorPin)
{
    servo.attach(motorPin);
    servo.write(currentAngle);
}

Rotor::~Rotor()
{
}

void Rotor::stepRotate()
{
    currentAngle += angleDifference;

    if (currentAngle == 180 || currentAngle == 0)
        angleDifference *= -1;

    servo.write(currentAngle);
}

int Rotor::getAngle()
{
    return currentAngle;
}
