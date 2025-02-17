/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:20:12 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/12 18:05:49 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
    int value;
    int index;
    int pos;
    int target;
    int cost_a;
    int cost_b;
    struct s_stack *next;
}               t_stack;

// operations
void    ft_sa(t_stack **stack_a);
void    ft_sb(t_stack **stack_b);
void    ft_ss(t_stack **stack_a, t_stack **stack_b);
void    ft_pa(t_stack **stack_a, t_stack **stack_b);
void    ft_pb(t_stack **stack_a, t_stack **stack_b);
void    ft_ra(t_stack **stack_a);
void    ft_rb(t_stack **stack_b);
void    ft_rr(t_stack **stack_a, t_stack **stack_b);
void    ft_rra(t_stack **stack_a);
void    ft_rrb(t_stack **stack_b);
void    ft_rrr(t_stack **stack_a, t_stack **stack_b);

// utils
void    ft_putstr_fd(char *str, int fd);
void	ft_putchar_fd(char c, int fd);
int     ft_is_digit(char c);
int     ft_is_signed(char c);
size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s1);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
int ft_abs(int n);

// parsing
char	*ft_strjoin(char *s1, const char *s2);
void    ft_parsing(char **v);
char    **ft_stack(char **v);
int     ft_atoi(const char *str);
char    **ft_split(const char *s, char c);
int     ft_is_sorted(t_stack *stack);
void ft_error(void);
// stack
void    ft_fill_stack(char **str, t_stack **stack);
void    ft_free_stack(t_stack **stack);
t_stack *ft_last(t_stack *stack);
t_stack *ft_before_last(t_stack *stack);
t_stack *ft_lst_new(int value);
int     ft_size(t_stack *stack);
void    ft_lst_add_back(t_stack **stack, t_stack *new);

// sort
void    ft_sort_three(t_stack **stack_a);
void    ft_sort(t_stack **stack_a, t_stack **stack_b);
void    ft_index_stack(t_stack *stack_a, int size);
void    ft_assign_pos(t_stack **stack_a, t_stack **stack_b);
void    ft_cost(t_stack **stack_a, t_stack **stack_b);
void    ft_cheapest(t_stack **stack_a, t_stack **stack_b);
void	ft_best_move(t_stack **stack_a, t_stack **stack_b, int a_cost, int b_cost);
void    ft_positon(t_stack **stack);


#endif