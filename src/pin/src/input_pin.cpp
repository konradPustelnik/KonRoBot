#include <iostream>
#include <wiringPi.h>
#include "file.h"
#include "pin.h"
#include "input_pin.h"

//can use pin from base class Pin
Input_pin::Input_pin(int rpi_pin) : Pin(rpi_pin)
{
    auto path_to_edge = "/sys/class/gpio/gpio" + std::to_string(pin) + "/edge";
    File file_edge(path_to_edge);
    file_edge.write("falling");
    //::foo(); from base class
}

Input_pin::~Input_pin()
{
    auto path_to_value = "/sys/class/gpio/gpio" + std::to_string(pin) + "/value";
    File file_value(path_to_value);
    file_value.write(std::to_string(0));
}

std::optional<std::string> Input_pin::read_state(int rpi_pin)
{
    auto path_to_reset = "/sys/class/gpio/gpio" + std::to_string(rpi_pin) + "/value";
    File file_reset(path_to_reset);
    return file_reset.read();
}
