#pragma once
#include "motor.h"
#include "diode.h"
#include "buzzer.h"
#include "button.h"

class Robot
{
    int speed;
    Motor right_motor;
    Motor left_motor;
    Button right_button;
    Button left_button;
    Diode diode;
    Buzzer buzzer;

public:
    Robot(int speed);
    ~Robot();
    void make_signal();
    void draw_rectangle();
    void drive_independently_with_manual_sensor();
    void drive_manually();
    void drive_independently_with_light_sensors();
    void stop();
    void set_speed(int set_speed);

private:
    void go_forward(int speed);
    void go_back(int speed);
    void go_right(int speed, int sleep=400);
    void go_left(int speed, int sleep=400);
};
