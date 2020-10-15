#include <iostream>
#include <wiringPi.h>
#include "robot.h"

int main()
{
    wiringPiSetup();

    Robot robot;
    robot.make_signal();
    robot.draw_rectangle();
    robot.drive_independently_with_manual_sensor();
    robot.drive_manually();
    robot.drive_independently_with_light_sensors();
    return 0;
}
