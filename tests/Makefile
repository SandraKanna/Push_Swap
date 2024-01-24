TESTS = test1 test2 test3
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Isrc

SRC = $(wildcard ../src/*.c) $(wildcard ../utils/*.c)

OBJ = $(SRC:.c=.o)

all: $(TESTS)

test1: $(OBJ) test_input.o
	$(CC) $(CFLAGS) -o $@ $^

test2: $(OBJ) test_classic.o
	$(CC) $(CFLAGS) -o $@ $^

test3: $(OBJ) test_circular.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) /*.o *.o

fclean: clean
	rm -f $(TESTS)

re: fclean all

.PHONY: all clean fclean re
