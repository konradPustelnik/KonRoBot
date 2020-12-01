#pragma once
#include "output_pin.h"

class Diode
{
    Output_pin output_pin;
    int rpi_pin;

public:
    Diode(int rpi_pin);
    void set_state(int led_state);
};
