#  Parent Makefile

TARGET = Stack
SRC = src/main.c
INC = inc
USER_LIBS = lib/libops.so
#LDLIBS = lib/libops.so
CFLAGS  = -g -Wall
INCLUDES = inc/operations.h

Stack: src/main.o
	echo "Build starting..."
	gcc -L lib/ -Wall -o Stack src/main.o -lops 
	echo "Build Completed"

main.o: src/main.c inc/operations.h
#	echo " Main build starting... "
#	export $LD_LIBRARY_PATH=$PWD/lib
#	gcc -g -Wall inc/operations.h $(USER_LIBS) $(LDLIBS) -c src/main.c
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${SRC} ${USER_LIBS}
#	echo " Main build completed "

clean: 
	rm -rf src/*.o Stack

#libops.so:
#	cd lib && $(MAKE) 
