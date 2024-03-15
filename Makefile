NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -IIncludes
#-fsanitize=address 
#-Ibonus

LIBFT = libft/libft3.a
LIBFT_DIR = libft/

CFILES = $(addprefix src/, push_swap.c sort_1.c sort_2.c initialize.c\
	utils/list_helpers.c utils/check_input.c utils/clean.c \
	ops/core.c ops/push_ops.c ops/rev_ops.c ops/rot_ops.c ops/swap_ops.c)

#BONUS_FILES = bonus/bonus.c 

OBJ = $(CFILES:.c=.o)
#BONUS_OBJ = $(BONUS_FILES:.c=.o)

%.o: %.c
	@echo "compiling..."
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)
	@echo "---compiled with libft---" 
#pas de retour a la ligne: echo - n o printg (met pas de \n a la fin)

clean:
	@rm -f $(OBJ)
	@echo "object files deleted"
#$(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "binaries files deleted"

re: fclean all

test:
	sh test.sh

#bonus: clean
#$(CC) $(CFLAGS) $(OBJ) $(BONUS_FILES) -o $(NAME)

.PHONY: all clean fclean re
