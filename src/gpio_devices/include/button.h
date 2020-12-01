#pragma once
#include "input_pin.h"

class Button
{
    Input_pin input_rpi_pin;
    int rpi_pin;

public:
    Button(int rpi_pin);
    bool is_pressed();
};
