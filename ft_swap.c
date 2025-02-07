/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:23:02 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/02 00:48:52 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *stack)
{
	int temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void  ft_sa(t_stack **stack_a)
{
	ft_swap(*stack_a);
	ft_putstr_fd("sa\n", 1);
}

void  ft_sb(t_stack **stack_b)
{
	ft_swap(*stack_b);
	ft_putstr_fd("sb\n", 1);
}

void  ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(*stack_a);
	ft_swap(*stack_b);
	ft_putstr_fd("ss\n", 1);
}