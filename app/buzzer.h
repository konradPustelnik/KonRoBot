#pragma once
#include "output_pin.h"

class Buzzer
{
    int rpi_pin, led_state;
    Output_pin output_pin;
public:
    Buzzer(int rpi_pin);
    void set_state(int led_state);
};
