# source/Makefile
CC=gcc
CFLAGS=-I../include -Wall -Wextra

OBJS=main.o PramCheck.o BlockCur.o ProcessCreate.o Waiting.o
TARGET=copy_main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)
