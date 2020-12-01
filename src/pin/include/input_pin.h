#pragma once
#include <optional>
#include "pin.h"

class Input_pin :public Pin
{
    int rpi_pin;

public:
    Input_pin(int rpi_pin);
    ~Input_pin();
    std::optional<std::string> read_state(int rpi_pin);
};
