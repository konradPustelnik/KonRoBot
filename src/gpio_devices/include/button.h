#pragma once
#include "input_pin.h"

class Button
{
    Input_pin input_rpi_pin;
    int pin;

public:
    Button(int set_pin);
    bool is_pressed();
};
