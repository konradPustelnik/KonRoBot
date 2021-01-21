#include <thread>
#include "file.h"
#include "robot.h"

auto static constexpr diode_pin{21};
auto static constexpr buzzer_pin{20};
auto static constexpr right_sensor_pin{0};
auto static constexpr left_sensor_pin{26};
auto static constexpr right_motor_pwm{23};
auto static constexpr right_motor_dir{24};
auto static constexpr left_motor_pwm{26};
auto static constexpr left_motor_dir{22};

auto static constexpr state_off{0};
auto static constexpr state_on{1};

Robot::Robot(int set_speed) :
    speed(set_speed),
    right_motor(right_motor_pwm, right_motor_dir),
    left_motor(left_motor_pwm, left_motor_dir),
    right_button(right_sensor_pin),
    left_button(left_sensor_pin),
    diode(diode_pin),
    buzzer(buzzer_pin) {}

Robot::~Robot() { stop(); }

void Robot::set_speed(int set_speed)
{
    speed = (set_speed * 60) / 100 + 40;
}

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
    for (int i = 0; i < 4; i++)
    {
        go_forward(speed);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        stop();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        go_right(speed);
     }  
}

void Robot::drive_independently_with_manual_sensor()
{
    go_forward(speed);
    if(left_button.is_pressed() == state_on)
    {
        make_signal();
        go_back(speed);
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        go_right(speed);
    }
    if(right_button.is_pressed() == state_on)
    {
        make_signal();
        go_back(speed);
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        go_left(speed);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void Robot::drive_manually()
{
    File file_control("/home/pi/KonRoBot/tools/manualControl");
    auto file_content = file_control.read();
    do
    {
        switch (file_content = file_control.read(); stoi(*file_content))
        {
            case 8:
                go_forward(speed);
                break;
            case 4:
                go_left(speed);
                file_control.write("5");
                break;
            case 6:
                go_right(speed);
                file_control.write("5");
                break;
            case 2:
                go_back(speed);
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
    File file("/home/pi/KonRoBot/tools/sensor");

    if(file.read() == "0")
    {
        go_forward(speed);
    }
    else if(file.read() > "0")
    {
        go_right(speed, 100);
    }
    else if(file.read() < "0")
    {
        go_left(speed, 100);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Robot::stop()
{
    buzzer.set_state(state_off);
    left_motor.action(state_off);
    right_motor.action(state_off);
}

void Robot::go_forward(int set_speed)
{
    right_motor.action(-set_speed);
    left_motor.action(set_speed);
}

void Robot::go_back(int set_speed)
{
    right_motor.action(set_speed);
    left_motor.action(-set_speed);
}

void Robot::go_right(int set_speed, int sleep)
{
    left_motor.action(state_off);
    right_motor.action(set_speed);
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
    right_motor.action(state_off);
}

void Robot::go_left(int set_speed, int sleep)
{
    right_motor.action(state_off);
    left_motor.action(-set_speed);
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
    left_motor.action(state_off);
}
