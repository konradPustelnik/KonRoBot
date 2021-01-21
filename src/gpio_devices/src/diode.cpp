#include "diode.h"

Diode::Diode(int set_pin) : output_pin(set_pin), pin(set_pin) {}

void Diode::set_state(int led_state)
{
    output_pin.write_state(led_state);
}
