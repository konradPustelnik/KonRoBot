#include <iostream>
#include <chrono>
#include <thread>
#include <wiringPi.h>
#include "robot.h"
#include "button.h"
#include "file.h"

int main()
{
    wiringPiSetup();

    auto constexpr button_pin{17};
    auto constexpr path_to_control{"/home/pi/KonRoBot/tools/machineState"};

    Robot robot;
    Button stop_button(button_pin);
    File file(path_to_control);

    while (not stop_button.is_pressed())
    {
        if (auto machine_state = file.read(); machine_state)
        {
            switch(stoi(*machine_state))
            {
                case 1:
                    robot.make_signal();
                    file.write("0");
                    break;
                case 2:
                    robot.draw_rectangle();
                    file.write("0");
                    break;
                case 3:
                    robot.drive_independently_with_manual_sensor();
                    break;
                case 4:
                    robot.drive_manually();
                    break;
                case 5:
                    robot.drive_independently_with_light_sensors();
                    break;
                default:
                    robot.stop();
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    break;
            }
        }
    }
    return 0;
}
