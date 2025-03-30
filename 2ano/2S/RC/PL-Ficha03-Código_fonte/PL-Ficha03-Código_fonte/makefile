# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -save-temps

# Default target: compile both server and client
all: tcp_server_ex1 tcp_client_ex1
	tcp_server_ex2 tcp_client_ex2

# Rule to compile the server
tcp_server_ex1: tcp_server_ex1.c
	$(CC) $(CFLAGS) -o tcp_server_ex1 tcp_server_ex1.c

tcp_server_ex2: tcp_server_ex2.c
	$(CC) $(CFLAGS) -o tcp_server_ex2 tcp_server_ex2.c

# Rule to compile the client
tcp_client_ex1: tcp_client_ex1.c
	$(CC) $(CFLAGS) -o tcp_client_ex1 tcp_client_ex1.c

tcp_client_ex2: tcp_client_ex2.c
	$(CC) $(CFLAGS) -o tcp_client_ex2 tcp_client_ex2.c

# Clean target to remove compiled executables
clean:
	rm -f tcp_server_ex1 tcp_client_ex1
	rm -f tcp_server_ex2 tcp_client_ex2

# Declare phony targets
.PHONY: all clean
