#include "button.h"

Button::Button(int rpi_pin) : input_rpi_pin(rpi_pin), rpi_pin(rpi_pin) {};

bool  Button::is_pressed()
{
    return input_rpi_pin.read_state(rpi_pin) == "0";
}
