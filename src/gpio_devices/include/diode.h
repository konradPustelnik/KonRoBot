#pragma once
#include "output_pin.h"

class Diode
{
    Output_pin output_pin;
    int pin;

public:
    Diode(int set_pin);
    void set_state(int led_state);
};
