#pragma once
#include <optional>
#include "pin.h"

class Input_pin :public Pin
{
public:
    Input_pin(int pin);
    ~Input_pin();
    std::optional<std::string> read_state(int pin);
};
