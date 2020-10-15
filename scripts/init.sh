#!/bin/bash

#install all packages for node js 
cd ../webServer && npm install express && npm install ejs && npm install multer && cd -

#pull-up resistors for buttons
gpio -g mode 17 up
gpio -g mode 26 up
gpio -g mode 0 up

#enable the control of light sensors
sudo python3 readAnalogValues.py &
