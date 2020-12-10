#Makefile

SRCS = ${wildcard src/*.cpp}

# include for pin.h
INCS = \
	-Iinclude \

CFLAGS ?= -Wall -Wextra -Werror -std=c++17 -c

default: libfile

libfile: ${SRCS:.cpp=.o}
	ar rcs ../../lib/libfile.a ${SRCS:.cpp=.o}

%.o: %.cpp
	g++ ${CFLAGS} ${INCS} -o $@ $<

clean:
	$(RM) src/*.o

.SILENT:
