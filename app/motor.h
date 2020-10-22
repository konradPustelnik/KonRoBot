#pragma once

class Motor
{
    int pwm_pin, dir_pin;
    const float pwm_range{6.5};

public:
    Motor(int pwm_pin, int dir_pin);
    ~Motor();
    void action(int speed);

private:
    void go_forward(int speed);
    void go_back(int speed);
    void stop();
};