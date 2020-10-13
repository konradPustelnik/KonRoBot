#include <iostream>
#include <chrono>
#include <thread>
#include "robot.h"

auto diodePin {21};
auto buzzerPin {20};
auto buttonPin {17};
auto rightSensorPin {0};
auto leftSensorPin {26};
auto rightMotorPwm {23};
auto rightMotorDir {24};
auto leftMotorPwm {26};
auto leftMotorDir {22};

auto defaultSpeed {100};

Robot::Robot() : 
    right_motor(rightMotorPwm, rightMotorDir),
    left_motor(leftMotorPwm, leftMotorDir),
    stop_button(buttonPin),
    right_button(rightSensorPin),
    left_button(leftSensorPin),
    diode(diodePin),
    buzzer(buzzerPin) {}
Robot::~Robot() { stop(); }

void Robot::draw_rectangle()
{
    make_signal();
    for (int i=0; i<4; i++)
    {
        go_forward(defaultSpeed);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        stop();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        go_right(defaultSpeed);
     }  
}

void Robot::drive_independently_with_manual_sensor()
{
    for (int i=0; i<2; i++) make_signal();

    while (stop_button.is_pressed())
    {
        go_forward(defaultSpeed);
        if(left_button.is_pressed() == 0)
        {
            make_signal();
            go_back(defaultSpeed);
            std::this_thread::sleep_for(std::chrono::milliseconds(400));
            go_right(defaultSpeed);
        }
        if(right_button.is_pressed() == 0)
        {
            make_signal();
            go_back(defaultSpeed);
            std::this_thread::sleep_for(std::chrono::milliseconds(400));
            go_left(defaultSpeed);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    stop();
}

void Robot::drive_manually()
{

    int direction{0};

    for (int i=0; i<3; i++) make_signal();

    while (stop_button.is_pressed())
    {
        std::cin >> direction;
        switch (direction)
        {
            case 8:
                go_forward(defaultSpeed);
                break;
            case 4:
                go_left(defaultSpeed);
                break;
            case 6:
                go_right(defaultSpeed);
                break;
            case 2:
                go_back(defaultSpeed);
                break;
            default:
                stop();
                break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    stop();
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
    left_motor.action(0);
    right_motor.action(speed);
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
    right_motor.action(0);
}

void Robot::go_left(int speed, int sleep)
{
    right_motor.action(0);
    left_motor.action(-speed);
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
    left_motor.action(0);
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
