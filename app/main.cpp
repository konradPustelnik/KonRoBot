#include <iostream>
#include <chrono>
#include <thread>
#include "file.h"
#include "diode.h"
#include "buzzer.h"
#include "button.h"
#include "motor.h"
#include <wiringPi.h>

auto diodePin {21};
auto buzzerPin {20};
auto buttonPin {17};
auto rightMotorPwm {23};
auto rightMotorDir {24};
auto leftMotorPwm {26};
auto leftMotorDir {22};

int main()
{
    wiringPiSetup();

    Motor right_motor(rightMotorPwm,rightMotorDir);
    Motor left_motor(leftMotorPwm,leftMotorDir);
    Button button(buttonPin);

    while (button.is_pressed())
    {
        right_motor.action(-100);
        left_motor.action(100);

        Diode diode(diodePin);
        diode.set_state(1);
        std::this_thread::sleep_for(std::chrono::milliseconds(2500));
        diode.set_state(0);

        Buzzer buzzer(buzzerPin);
        buzzer.set_state(1);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        buzzer.set_state(0);
    }
    left_motor.action(0);
    right_motor.action(0);

    return 0;
}
