#pragma once
#include "output_pin.h"

class Buzzer
{
    Output_pin output_pin;
    int pin;

public:
    Buzzer(int set_pin);
    void set_state(int led_state);
};
