#include <iostream>
#include "file.h"
#include "output_pin.h"

Output_pin::Output_pin(int rpi_pin) : Pin(rpi_pin)
{
    auto path_to_direction = "/sys/class/gpio/gpio" + std::to_string(pin) + "/direction";
    File file_direction(path_to_direction);
    file_direction.write("out");

    auto path_to_value = "/sys/class/gpio/gpio" + std::to_string(pin) + "/value";
    File file_value(path_to_value);
    file_value.write(std::to_string(0));
}

Output_pin::~Output_pin()
{
    auto path_to_reset = "/sys/class/gpio/gpio" + std::to_string(pin) + "/value";
    File file_reset(path_to_reset);
    file_reset.write(std::to_string(0));
}

void Output_pin::write_state(int pin_state)
{
    auto path_to_value = "/sys/class/gpio/gpio" + std::to_string(pin) + "/value";
    File file_write_state(path_to_value);
    file_write_state.write(std::to_string(pin_state));
}
