#include "button.h"

Button::Button(int set_pin) : input_rpi_pin(set_pin), pin(set_pin) {}

bool  Button::is_pressed()
{
    return input_rpi_pin.read_state(pin) == "0";
}
