#Makefile

SRCS = ${wildcard src/*.cpp}

# include for pin.h
# file_manager/include for file.h
INCS = \
	-Iinclude \
	-I../file_manager/include \

CFLAGS ?= -Wall -Wextra -Werror -Wshadow -pedantic -std=c++17 -c

default: libpin

libpin: ${SRCS:.cpp=.o}
	ar rcs ../../lib/libpin.a ${SRCS:.cpp=.o}

%.o: %.cpp
	g++ ${CFLAGS} ${INCS} -o $@ $<

clean:
	$(RM) src/*.o

.SILENT:
