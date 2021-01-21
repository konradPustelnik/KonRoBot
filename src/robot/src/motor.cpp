#include <algorithm>
#include <wiringPi.h>
#include "motor.h"

Motor::Motor(int set_pwm_pin, int set_dir_pin) : pwm_pin(set_pwm_pin), dir_pin(set_dir_pin)
{   
    pinMode(dir_pin, OUTPUT);
    pinMode(pwm_pin, PWM_OUTPUT);
}

Motor::~Motor()
{
    pinMode(pwm_pin, 0);
}

void Motor::action(int speed)
{
    if (std::clamp(speed, 0, 100)) go_forward(speed);
    else if (std::clamp(speed, -100, 0)) go_back(abs(speed));
    else if (speed == 0) stop();
}

void Motor::go_forward(int speed)
{
    digitalWrite(dir_pin, 0);
    pwmWrite(pwm_pin, pwm_range * speed);
}

void Motor::go_back(int speed)
{
    digitalWrite(dir_pin, 1);
    pwmWrite(pwm_pin, pwm_range * speed);
}

void Motor::stop()
{
    pwmWrite(pwm_pin, 0);
}
