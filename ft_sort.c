/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:18:25 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/06 23:47:14 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    ft_push_to_b(t_stack **stack_a, t_stack **stack_b)
{
    int size;
    int i;
    int is_pushed;
    
    size = ft_size(*stack_a);
    is_pushed = 0;
    i = 0;
    while (size > 6 && i < size && is_pushed < size / 2)
    {
        if ((*stack_a)->index <= size / 2)
        {
            ft_pb(stack_a, stack_b);
            is_pushed++;
        }
        else
            ft_ra(stack_a);
        i++;
    }
    while (size - is_pushed > 3)
    {
        ft_pb(stack_a, stack_b);
        is_pushed++;
    }
}
void    ft_sort(t_stack **stack_a, t_stack **stack_b)
{
    ft_push_to_b(stack_a, stack_b);
    ft_sort_three(stack_a);
    while (*stack_b)
    {
        ft_assign_pos(stack_a, stack_b);
        ft_cost(stack_a, stack_b);
        ft_cheapest(stack_a, stack_b);
    }
    if (!ft_is_sorted(*stack_a))
    {
        
    }
}