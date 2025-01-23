# mod/Makefile
CC=gcc
CFLAGS=-I../include -Wall -Wextra

TARGET=copy

all: $(TARGET)

copy: Copy.o
	$(CC) $^ -o $@

clean:
	rm -f *.o $(TARGET)
