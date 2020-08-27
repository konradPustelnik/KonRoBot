#Makefile

SOURCES=$(wildcard *.cpp)

main:	clean
	g++ -lwiringPi ${SOURCES} -o main; ./main

clean:
	rm -f main

.SILENT:

