#pragma once
#include "pin.h"

class Output_pin :public Pin
{
    int rpi_pin;
    int pin_state;

public:
    Output_pin(int rpi_pin);
    ~Output_pin();
    void write_state(int pin_state);
};
