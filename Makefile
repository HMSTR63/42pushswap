NAME = push_swap
SRC = ft_atoi.c ft_best_move.c ft_cost.c ft_fill.c ft_list.c ft_parsing_utils.c ft_parsing.c ft_pos.c ft_push.c ft_reverse_rotate.c ft_rotate.c ft_sort_three.c ft_split.c ft_stack.c ft_strjoin.c ft_swap.c push_swap_utils.c push_swap.c  
OBJ = $(SRC:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
INCLUDE = push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re