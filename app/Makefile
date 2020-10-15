#Makefile

SOURCES=$(wildcard *.cpp)

all:	clean
	g++ -lwiringPi -std=c++17 ${SOURCES} -o app

clean:
	rm -f app

.SILENT:

