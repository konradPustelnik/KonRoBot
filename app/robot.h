#pragma once
#include "motor.h"
#include "diode.h"
#include "buzzer.h"
#include "button.h"

class Robot
{
    Button stop_button;
    Button right_button;
    Button left_button;
    Motor right_motor;
    Motor left_motor;
    Diode diode;
    Buzzer buzzer;

public:
    Robot();
    ~Robot();
    void draw_rectangle();
    void drive_independently_with_manual_sensor();
    void drive_manually();

private:
    void go_forward(int speed);
    void go_back(int speed);
    void go_right(int speed, int sleep=400);
    void go_left(int speed, int sleep=400);
    void stop();
    void make_signal();
};
