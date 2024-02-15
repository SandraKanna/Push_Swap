TESTS = test1 test2 test3 test4 test5
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Isrc

LIBFT = ../libft/libft3.a
LIBFT_DIR = ../libft

SRC = $(wildcard ../src/*.c) $(wildcard ../src/utils/*.c ../src/ops/*.c)

OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)
	@echo "---compiled with libft---"

all: $(LIBFT)
	@echo "Run one test at a time. Available tests: $(TESTS)"

test1: $(OBJ) test_input.o
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
	@./$@

test2: $(OBJ) test_core.o
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
	@./$@

test3: $(OBJ) test_circular.o
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
	@./$@

test4: $(OBJ) test_ops.o
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
	@./$@

test5: $(OBJ) test_algo.o
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
	@./$@

clean:
	@rm -f $(OBJ) *.o

fclean: clean
	@rm -f $(TESTS)
	@make --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re test1 test2 test3 test4 test5
