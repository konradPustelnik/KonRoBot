#Makefile

SRCS = ${wildcard src/*.cpp}

# include for motor.h and robot.h
# file_manager/include for file.h
# gpio_devices/include for diode.h, buzzer.h and button.h
# pin/include for output_pin.h
INCS = \
	-Iinclude \
	-I../file_manager/include \
	-I../gpio_devices/include \
	-I../pin/include

CFLAGS ?= -Wall -Wextra -Werror -Wshadow -pedantic -std=c++17 -c

default: librobot

librobot: ${SRCS:.cpp=.o}
	ar rcs ../../lib/librobot.a ${SRCS:.cpp=.o}

%.o: %.cpp
	g++ ${CFLAGS} ${INCS} -o $@ $<

clean:
	$(RM) src/*.o

.SILENT:
