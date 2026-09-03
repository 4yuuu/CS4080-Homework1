CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: hello list

hello: hello.c
	$(CC) $(CFLAGS) hello.c -o hello

list: list.c
	$(CC) $(CFLAGS) list.c -o list

clean:
	rm -f hello list
