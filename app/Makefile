#Makefile

SOURCES=$(wildcard *.cpp)

all:	clean
	gpio -g mode 17 up
	gpio -g mode 26 up
	gpio -g mode 0 up
	sudo python3 ../scripts/readAnalogValues.py &
	g++ -lwiringPi -std=c++17 ${SOURCES} -o app

clean:
	rm -f app

.SILENT:

