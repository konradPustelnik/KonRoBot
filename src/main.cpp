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

    Button stop_button(17);
    File file_control("/home/pi/KonRoBot/tools/machineState");
    File file_speed("/home/pi/KonRoBot/tools/speed");
    Robot robot(stoi(*file_speed.read()));

    while (not stop_button.is_pressed())
    {
        robot.set_speed(stoi(*file_speed.read()));

        if (auto machine_state = file_control.read(); machine_state)
        {
            switch(stoi(*machine_state))
            {
                case 1:
                    robot.make_signal();
                    file_control.write("0");
                    break;
                case 2:
                    robot.draw_rectangle();
                    file_control.write("0");
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
