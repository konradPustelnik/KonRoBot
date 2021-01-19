#Makefile

SRCS = ${wildcard src/*.cpp}

# include for pin.h
# pin/include for input_pin.h and output_pin.h
INCS = \
	-Iinclude \
	-I../pin/include \

CFLAGS ?= -Wall -Wextra -Werror -Wshadow -pedantic -std=c++17 -c

default: libgpiodevices

libgpiodevices: ${SRCS:.cpp=.o}
	ar rcs ../../lib/libgpiodevices.a ${SRCS:.cpp=.o}

%.o: %.cpp
	g++ ${CFLAGS} ${INCS} -o $@ $<

clean:
	$(RM) src/*.o

.SILENT:
