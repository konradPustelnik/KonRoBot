#include <iostream>
#include <chrono>
#include <thread>
#include "file.h"
#include "diode.h"

int main()
{
    auto rpiPin {21};

    Diode diode(rpiPin);
    diode.set_state(1);
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
    diode.set_state(0);

    return 0;
}