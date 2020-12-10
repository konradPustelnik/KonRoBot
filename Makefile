#Makefile

SRCS = ${wildcard src/*.cpp}

CFLAGS ?= -lwiringPi -Wall -Wextra -Werror -std=c++17

INCS = \
	-Isrc/file_manager/include \
	-Isrc/gpio_devices/include \
	-Isrc/pin/include \
	-Isrc/robot/include

LIBS = \
	lib/libfile.a \
	lib/librobot.a \
	lib/libgpiodevices.a \
	lib/libpin.a

OBJS = \
	${SRCS:.cpp=.o}

.SILENT:

default: app

#C++ Error: undefined reference to `main' -c flag

app: libfile_manager libgpio_devices libpin librobot
	g++ $(CFLAGS) $(INCS) -c ${SRCS} -o src/main.o
	g++ ${OBJS} ${CFLAGS} ${LIBS} -o bin/KonRoBot

libfile_manager:
	$(MAKE) -C src/file_manager

libgpio_devices:
	$(MAKE) -C src/gpio_devices

libpin:
	$(MAKE) -C src/pin

librobot:
	$(MAKE) -C src/robot

clean:
	$(RM) *.o bin/KonRoBot lib/*.a
	$(MAKE) clean -C src/file_manager
	$(MAKE) clean -C src/gpio_devices
	$(MAKE) clean -C src/pin
	$(MAKE) clean -C src/robot
