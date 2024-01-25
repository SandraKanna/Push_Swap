NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
#-fsanitize=address 
#-Ibonus

CFILES = src/push_swap.c src/core.c src/circular.c\
	utils/utils.c utils/ft_split.c utils/check_params.c utils/clean.c \
	ops/push_ops.c ops/rev_ops.c ops/rot_ops.c ops/swap_ops.c 

#BONUS_FILES = bonus/bonus.c 

OBJ = $(CFILES:.c=.o)
#BONUS_OBJ = $(BONUS_FILES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CFILES) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ) 
#$(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

#bonus: clean
#$(CC) $(CFLAGS) $(OBJ) $(BONUS_FILES) -o $(NAME)

.PHONY: all clean fclean re bonus
