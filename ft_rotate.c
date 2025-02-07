/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:38:40 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/02 00:49:16 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    ft_rotate(t_stack **stack)
{
    t_stack *temp;
    t_stack *last;

    if (!*stack || !(*stack)->next)
        return ;
    temp = *stack;
    *stack = (*stack)->next;
    last = ft_last(*stack);
    temp->next = NULL;
    last->next = temp;
}

void  ft_ra(t_stack **stack_a)
{
    ft_rotate(stack_a);
    ft_putstr_fd("ra\n", 1);
}

void  ft_rb(t_stack **stack_b)
{
    ft_rotate(stack_b);
    ft_putstr_fd("rb\n", 1);
}

void  ft_rr(t_stack **stack_a, t_stack **stack_b)
{
    ft_rotate(stack_a);
    ft_rotate(stack_b);
    ft_putstr_fd("rr\n", 1);
}