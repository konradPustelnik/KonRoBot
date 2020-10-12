#include "button.h"

Button::Button(int rpi_pin) : input_rpi_pin(rpi_pin), rpi_pin(rpi_pin) {};

bool  Button::is_pressed()
{
    if (input_rpi_pin.read_state(rpi_pin) == "1")
        return 1;
    else
        return 0;
}
