#include <iostream>
#include <chrono>
#include <thread>
#include "file.h"
#include "diode.h"
#include "buzzer.h"
#include "button.h"

int main()
{
    auto diodePin {21};
    auto buzzerPin {20};

    Button button(17);
    while (button.is_pressed())
    {
        Diode diode(diodePin);
        diode.set_state(1);
        std::this_thread::sleep_for(std::chrono::milliseconds(2500));
        diode.set_state(0);

        Buzzer buzzer(buzzerPin);
        buzzer.set_state(1);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        buzzer.set_state(0);
    }
    return 0;
}