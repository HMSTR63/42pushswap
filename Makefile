NAME_M = push_swap
NAME_B = checker
SRC_M = mandatory/ft_atoi.c mandatory/ft_best_move.c mandatory/ft_cost.c mandatory/ft_fill.c mandatory/ft_list.c mandatory/ft_parsing_utils.c mandatory/ft_parsing.c mandatory/ft_pos.c mandatory/ft_push.c mandatory/ft_reverse_rotate.c mandatory/ft_rotate.c mandatory/ft_sort_three.c mandatory/ft_sort.c mandatory/ft_split.c mandatory/ft_stack.c mandatory/ft_strjoin.c mandatory/ft_swap.c mandatory/push_swap_utils.c mandatory/push_swap.c
SRC_B = bonus/checker_bonus.c bonus/ft_atoi.c bonus/ft_fill.c bonus/ft_list.c bonus/ft_parsing_utils.c bonus/ft_parsing.c bonus/ft_push.c bonus/ft_reverse_rotate.c bonus/ft_rotate.c bonus/ft_split.c bonus/ft_stack.c bonus/ft_swap.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c bonus/push_swap_utils.c
OBJ_M = $(SRC_M:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
RM = rm -rf
INCLUDE_M = mandatory/push_swap.h
INCLUDE_B = bonus/push_swap_bonus.h

all: $(NAME_M)

$(NAME_M): $(OBJ_M)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(INCLUDE_M)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_B)

$(NAME_B): $(OBJ_B)
	$(CC) $(CFLAGS) $^ -o $@

%_bonus.o: %_bonus.c $(INCLUDE_B)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_M) $(OBJ_B)

fclean: clean
	$(RM) $(NAME_M) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re bonus
