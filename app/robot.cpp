#include <iostream>
#include <chrono>
#include <thread>
#include "file.h"
#include "robot.h"

auto constexpr diode_pin{21};
auto constexpr buzzer_pin{20};
auto constexpr right_sensor_pin{0};
auto constexpr left_sensor_pin{26};
auto constexpr right_motor_pwm{23};
auto constexpr right_motor_dir{24};
auto constexpr left_motor_pwm{26};
auto constexpr left_motor_dir{22};

auto constexpr default_speed{100};
auto constexpr path_to_manual_control{"/home/pi/KonRoBot/manualControl"};

auto constexpr state_off{0};
auto constexpr state_on{1};

Robot::Robot() :
    right_motor(right_motor_pwm, right_motor_dir),
    left_motor(left_motor_pwm, left_motor_dir),
    right_button(right_sensor_pin),
    left_button(left_sensor_pin),
    diode(diode_pin),
    buzzer(buzzer_pin) {}

Robot::~Robot() { stop(); }

void Robot::make_signal()
{
    diode.set_state(state_on);
    buzzer.set_state(state_on);
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    diode.set_state(state_off);
    buzzer.set_state(state_off);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Robot::draw_rectangle()
{
    make_signal();
    for (int i=0; i<4; i++)
    {
        go_forward(default_speed);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        stop();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        go_right(default_speed);
     }  
}

void Robot::drive_independently_with_manual_sensor()
{
    go_forward(default_speed);
    if(left_button.is_pressed() == state_on)
    {
        make_signal();
        go_back(default_speed);
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        go_right(default_speed);
    }
    if(right_button.is_pressed() == state_on)
    {
        make_signal();
        go_back(default_speed);
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        go_left(default_speed);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void Robot::drive_manually()
{
    int direction{state_off};

    File file_control(path_to_manual_control);
    auto file_content = file_control.read();
    do
    {
        switch (file_content = file_control.read(); stoi(*file_content))
        {
            case 8:
                go_forward(default_speed);
                break;
            case 4:
                go_left(default_speed);
                file_control.write("5");
                break;
            case 6:
                go_right(default_speed);
                file_control.write("5");
                break;
            case 2:
                go_back(default_speed);
                break;
            default:
                stop();
                file_control.write("0");
                break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    } while (stoi(*file_content) != state_off);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Robot::drive_independently_with_light_sensors()
{
    auto path_to_analog = "/home/pi/KonRoBot/sensor";
    File file(path_to_analog);

    if(file.read() == "0")
    {
        go_forward(60);
    }
    else if(file.read() > "0")
    {
        go_right(100,100);
    }
    else if(file.read() < "0")
    {
        go_left(100,100);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Robot::stop()
{
    buzzer.set_state(state_off);
    left_motor.action(state_off);
    right_motor.action(state_off);
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
    left_motor.action(state_off);
    right_motor.action(speed);
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
    right_motor.action(state_off);
}

void Robot::go_left(int speed, int sleep)
{
    right_motor.action(state_off);
    left_motor.action(-speed);
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
    left_motor.action(state_off);
}
