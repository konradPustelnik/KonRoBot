#pragma once

class Motor
{
    int pwm_pin, dir_pin;
    const float pwm_range{6.5};

public:
    Motor(int set_pwm_pin, int set_dir_pin);
    ~Motor();
    void action(int speed);

private:
    void go_forward(int speed);
    void go_back(int speed);
    void stop();
};
