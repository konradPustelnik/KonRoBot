#include <iostream>
#include "buzzer.h"

Buzzer::Buzzer(int set_pin) : output_pin(set_pin), pin(set_pin) {}

void Buzzer::set_state(int led_state)
{
    output_pin.write_state(led_state);
}
