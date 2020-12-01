#pragma once
#include "output_pin.h"

class Buzzer
{
    Output_pin output_pin;
    int rpi_pin;

public:
    Buzzer(int rpi_pin);
    void set_state(int led_state);
};
