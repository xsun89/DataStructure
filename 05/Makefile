.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=main
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
main:findnode.o
	$(CC) $(CFLAGS) $^ -o $@
clean:
	rm -f *.o $(BIN)

