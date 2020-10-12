#include <iostream>
#include "buzzer.h"

Buzzer::Buzzer(int rpi_pin) : output_pin(rpi_pin, led_state), rpi_pin(rpi_pin) {};

void Buzzer::set_state(int led_state)
{
    output_pin.write_state(led_state);
}
