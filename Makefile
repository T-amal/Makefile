#  Parent Makefile

TARGET = Stack
SRC = src/main.c
INC = inc
USER_LIBS = lib/libops.so

CFLAGS  = -g -Wall
INCLUDES = inc/operations.h

Stack: src/main.o
	echo "Build starting..."
	gcc -L lib/ -Wall -o Stack src/main.o -lops 
	echo "Build Completed"

main.o: src/main.c inc/operations.h

	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${SRC} ${USER_LIBS}

clean: 
	rm -rf src/*.o Stack


