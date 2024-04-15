BONUS = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -IIncludes
#-fsanitize=address 

LIBFT = libft/libft3.a
LIBFT_DIR = libft/

ORIGINAL_FILES = $(addprefix src/, initialize.c sort.c divide.c \
	utils/list_helpers.c utils/sort_helpers.c  utils/check_input.c utils/clean.c \
	ops/push_ops.c ops/rev_ops.c ops/rot_ops.c ops/swap_ops.c)

BONUS_FILE = bonus/checker.c

OBJ = $(CFILES:.c=.o)

%.o: %.c
	@echo "compiling..."
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)
	@echo "---compiled with libft---" 
#pas de retour a la ligne: echo - n o printg (met pas de \n a la fin)

clean:
	@rm -f $(OBJ)
	@echo "object files deleted"

fclean: clean
	@rm -f $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "binaries files deleted"

re: fclean bonus

.PHONY: clean fclean re bonus
