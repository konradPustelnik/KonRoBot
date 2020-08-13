#include <iostream>
#include <wiringPi.h>

int main()
{
    wiringPiSetup();
    pinMode(29, OUTPUT);

    digitalWrite(29, 1);
    delay(500); 
    digitalWrite(29, 0);
    
    return 0;
}