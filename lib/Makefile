# Library makefile
CC = gcc
SRC = operations.c
TARGET_LIB = libops.so
INC = ../inc
CFLAGS = -Wall
GFLAGS = -Werror -fPIC
SHARED = -shared
DEBUGG = -g
OBJ = operations.o

$(TARGET_LIB): $(OBJ)
	echo "Library build starting..."
	$(CC) $(SHARED) $(DEBUGG) -o $(TARGET_LIB) $(OBJ)
	echo "Library build completed"

$(OBJ): $(SRC)
	gcc $(DEBUGG) $(CFLAGS) $(GFLAGS) -c $(SRC)

clean:
	rm -rf *.so *.o

