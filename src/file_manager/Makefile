#Makefile

SRCS = \
	src/file.cpp

# include for pin.h
# pin/include for input_pin.h and output_pin.h
INCS = \
	-Iinclude \

CFLAGS ?= -Wall -Wextra -Werror -std=c++17 -c

default: libfile

libfile: ${SRCS:.cpp=.o}
	ar rcs libfile.a ${SRCS:.cpp=.o}

%.o: %.cpp
	g++ ${CFLAGS} ${INCS} -o $@ $<

clean:
	$(RM) *.a src/*.o

.SILENT:
