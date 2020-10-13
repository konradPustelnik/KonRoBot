#include <iostream>
#include <wiringPi.h>
#include "robot.h"

int main()
{
    wiringPiSetup();

    Robot robot;
    robot.draw_rectangle();
    robot.drive_independently_with_manual_sensor();
    return 0;
}
