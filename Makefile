NAME = push_swap
SRC = mandatory/ft_atoi.c mandatory/ft_best_move.c mandatory/ft_cost.c mandatory/ft_fill.c mandatory/ft_list.c mandatory/ft_parsing_utils.c mandatory/ft_parsing.c mandatory/ft_pos.c mandatory/ft_push.c mandatory/ft_reverse_rotate.c mandatory/ft_rotate.c mandatory/ft_sort_three.c mandatory/ft_sort.c mandatory/ft_split.c mandatory/ft_stack.c mandatory/ft_strjoin.c mandatory/ft_swap.c mandatory/push_swap_utils.c mandatory/push_swap.c  
OBJ = $(SRC:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror# -fsanitize=address
RM = rm -rf
INCLUDE = mandatory/push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re