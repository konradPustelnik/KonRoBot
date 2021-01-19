#pragma once
#include "pin.h"

class Output_pin :public Pin
{
public:
    Output_pin(int pin);
    ~Output_pin();
    void write_state(int pin_state);
};
