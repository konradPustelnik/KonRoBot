#pragma once

class Pin
{
public:
    Pin(int rpi_pin);
    ~Pin();

//protected should be under the public
protected:
    int pin;
};
