CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -IIncludes
#-fsanitize=address

GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

NAME = push_swap
COMMON_FILES = $(addprefix src/, initialize.c divide.c sort.c \
	utils/list_helpers.c utils/sort_helpers.c  utils/check_input.c utils/clean.c \
	ops/push_ops.c ops/rev_ops.c ops/rot_ops.c ops/swap_ops.c)
COMMON_OBJ = $(COMMON_FILES:.c=.o)

MANDATORY_MAIN = src/push_swap.c
MANDATORY_OBJ = $(MANDATORY_MAIN:.c=.o)

LIBFT = libft/libft3.a
LIBFT_DIR = libft/

$(NAME): $(COMMON_OBJ) $(MANDATORY_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(COMMON_OBJ) $(MANDATORY_OBJ) -o $(NAME) $(LIBFT)

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)
	@echo "\n$(GREEN)✔$(RESET) compiled with libft"

BONUS = checker
BONUS_FILES = src/bonus/checker.c
BONUS_OBJ = $(BONUS_FILES:.c=.o)
$(BONUS): $(COMMON_OBJ) $(BONUS_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(COMMON_OBJ) $(BONUS_OBJ) -o $(BONUS) $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "."

all: $(NAME)

bonus: $(BONUS)

clean:
	@rm -f $(COMMON_OBJ) $(BONUS_OBJ) 
	@echo "object files deleted"

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "binaries files deleted"

re: fclean all

test:
	sh test.sh

.PHONY: all clean fclean re bonus
