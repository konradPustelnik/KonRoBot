#include <iostream>
#include "file.h"
#include "pin.h"

Pin::Pin(int rpi_pin) : rpi_pin(rpi_pin)
{
    File file("/sys/class/gpio/export");
    file.write(std::to_string(rpi_pin));
};

Pin::~Pin()
{
    File file("/sys/class/gpio/unexport");
    file.write(std::to_string(rpi_pin));
};