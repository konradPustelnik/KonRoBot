#include <iostream>
#include <chrono>
#include <thread>
#include "robot.h"

auto diodePin {21};
auto buzzerPin {20};
auto buttonPin {17};
auto rightMotorPwm {23};
auto rightMotorDir {24};
auto leftMotorPwm {26};
auto leftMotorDir {22};

Robot::Robot() : 
    right_motor(rightMotorPwm, rightMotorDir),
    left_motor(leftMotorPwm, leftMotorDir),
    stop_button(buttonPin),
    diode(diodePin),
    buzzer(buzzerPin) {}
Robot::~Robot() { stop(); }

void Robot::draw_rectangle()
{
    make_signal();
    for (int i=0; i<4; i++)
    {
        go_forward(100);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        stop();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        go_right(100);
     }  
}

void Robot::go_forward(int speed)
{
    right_motor.action(-speed);
    left_motor.action(speed);
}

void Robot::go_back(int speed)
{
    right_motor.action(speed);
    left_motor.action(-speed);
}

void Robot::go_right(int speed, int sleep)
{
    right_motor.action(0);
    left_motor.action(speed);
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
    left_motor.action(0);
}

void Robot::go_left(int speed, int sleep)
{
    left_motor.action(0);
    right_motor.action(-speed);
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
    right_motor.action(0);
}

void Robot::stop()
{
    left_motor.action(0);
    right_motor.action(0);
}

void Robot::make_signal()
{
    diode.set_state(1);
    buzzer.set_state(1);
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    diode.set_state(0);
    buzzer.set_state(0);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
