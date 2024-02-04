TESTS = test1 test2 test3 test4 test5
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Isrc

SRC = $(wildcard ../src/*.c) $(wildcard ../src/utils/*.c ../src/ops/*.c)

OBJ = $(SRC:.c=.o)

all: $(TESTS)
	@echo "Compiling...done"

test1: $(OBJ) test_input.o
	@$(CC) $(CFLAGS) -o $@ $^

test2: $(OBJ) test_core.o
	@$(CC) $(CFLAGS) -o $@ $^

test3: $(OBJ) test_circular.o
	@$(CC) $(CFLAGS) -o $@ $^

test4: $(OBJ) test_ops.o
	@$(CC) $(CFLAGS) -o $@ $^

test5: $(OBJ) test_algo.o
	@$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) /*.o *.o

fclean: clean
	@rm -f $(TESTS)

re: fclean all

.PHONY: all clean fclean re
