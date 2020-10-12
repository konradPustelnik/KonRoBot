#include <iostream>
#include <wiringPi.h>
#include "file.h"

int main()
{
    auto rpiPin {21};

    File exportFile("/sys/class/gpio/export");
    exportFile.write(std::to_string(rpiPin));

    auto path_to_direction = "/sys/class/gpio/gpio" + std::to_string(rpiPin) + "/direction";
    File file_direction(path_to_direction);
    file_direction.write("out");

    auto path_to_value = "/sys/class/gpio/gpio" + std::to_string(rpiPin) + "/value";
    File file_value(path_to_value);
    file_value.write(std::to_string(rpiPin));

    delay(1000);

    File unexportFile("/sys/class/gpio/unexport");
    unexportFile.write(std::to_string(rpiPin));

    return 0;
}