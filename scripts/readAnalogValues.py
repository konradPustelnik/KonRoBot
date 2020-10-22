import os
import time
import busio
import digitalio
import board
import adafruit_mcp3xxx.mcp3008 as MCP 
from adafruit_mcp3xxx.analog_in import AnalogIn

# create the spi bus, chip select, mcp object and analog input channel on pin 0 and 1
spi = busio.SPI(clock=board.SCK, MISO=board.MISO, MOSI=board.MOSI)
cs = digitalio.DigitalInOut(board.D22)
mcp = MCP.MCP3008(spi, cs)

chan0 = AnalogIn(mcp, MCP.P0)
chan1 = AnalogIn(mcp, MCP.P1)

def remap_range(value, left_min, left_max, right_min, right_max):
    # this remaps a value from original (left) range to new (right) range
    left_span = left_max - left_min
    right_span = right_max - right_min

    # convert the left range into a 0-1 range (int)
    valueScaled = int(value - left_min) / int(left_span)

    # convert the 0-1 range into a value in the right range.
    return int(right_min + (valueScaled * right_span))

while True:
    # read the analog pins
    left_sensor = chan0.value
    right_sensor = chan1.value

    # convert 16bit adc0 (0-65535) trim pot read into 0-100 volume level
    left_value = remap_range(left_sensor, 0, 65535, 0, 100)
    right_value= remap_range(right_sensor, 0, 65535, 0, 100)

    #write this value difference to /home/pi/sensor
    with open("/home/pi/KonRoBot/sensor", 'w') as myfile:
        myfile.write('{volume}' .format(volume = right_value-left_value))

    time.sleep(0.5)
