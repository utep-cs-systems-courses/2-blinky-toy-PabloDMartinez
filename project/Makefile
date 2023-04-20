#Makefile configuration
COMMON_OBJECTS 	= main.o
CPU 		= msp430g2553
CFLAGS 		= -mmcu=${CPU} -I../h
LDFLAGS 	= -L/opt/ti/msp430_gcc/inlcude

#Switch the compiler
CC 		= msp430-elf-gcc
AS 		= msp430-elf-as

all:led.elf buzzer.elf button.elf

led.elf: ${COMMON_OBJECTS}
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a

buzzer.elf: ${COMMON_OBJECTS} buzzer.o main.o ../lib/libTimer.a
	${CC} ${CFLAGS} -o $@ $^

button.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o led.o switches.o main.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: led.elf buzzer.elf button.elf
	msp430loader.sh led.elf buzzer.elf button.elf

clean:
	rm -f *.o *.elf

main.o: led.h

wdInterruptHandler.o: led.h
