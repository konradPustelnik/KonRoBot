#Makefile

SRCS = \
	main.cpp

CFLAGS ?= -lwiringPi -Wall -Wextra -Werror -std=c++17

INCS = \
	-Ifile_manager/include \
	-Igpio_devices/include \
	-Ipin/include \
	-Irobot/include

LIBS = \
	file_manager/libfile.a \
	robot/librobot.a \
	gpio_devices/libgpiodevices.a \
	pin/libpin.a

OBJS = \
	${SRCS:.cpp=.o}

.SILENT:

default: app

#C++ Error: undefined reference to `main' -c flag

app: libfile_manager libgpio_devices libpin librobot
	g++ $(CFLAGS) $(INCS) -c ${SRCS} -o main.o
	g++ ${OBJS} ${CFLAGS} ${LIBS} -o ../bin/KonRoBot

libfile_manager:
	$(MAKE) -C file_manager

libgpio_devices:
	$(MAKE) -C gpio_devices

libpin:
	$(MAKE) -C pin

librobot:
	$(MAKE) -C robot

clean:
	$(RM) *.o ../bin/KonRoBot
	$(MAKE) clean -C file_manager
	$(MAKE) clean -C gpio_devices
	$(MAKE) clean -C pin
	$(MAKE) clean -C robot
