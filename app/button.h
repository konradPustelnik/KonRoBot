#pragma once
#include "input_pin.h"

class Button
{
    int rpi_pin;
    Input_pin input_rpi_pin;
    
public:
    Button(int rpi_pin);
    bool is_pressed();
};