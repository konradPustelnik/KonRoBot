#include <iostream>
#include <wiringPi.h>
#include "robot.h"

int main()
{
    wiringPiSetup();

    Robot robot;
    robot.draw_rectangle();

    return 0;
}
