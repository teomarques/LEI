CC = gcc
AS = as

prog: odd_numbers.o
	$(CC) odd_numbers.o -o prog

odd_numbers.o: odd_numbers.c
	$(CC) -c -g odd_numbers.c -o odd_numbers.o

clean:
	rm -f prog odd_numbers.o

