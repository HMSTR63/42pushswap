/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:29:48 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/16 16:37:33 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_fill_stack(char **str, t_stack **stack)
{
    long int value;
    int i;

    *stack = NULL;
    i = 0;
    while (str[i])
    {
        value = ft_atoi(str[i]);
        if (value > INT_MAX || value < INT_MIN)
            ft_error();
        ft_lst_add_back(stack, ft_lst_new(value));
        i++;
    }
}

void    ft_index_stack(t_stack *stack_a, int size)
{
    t_stack *temp;
    t_stack *high;
    int value;
    while (size-- > 0)
    {
        temp = stack_a;
        value = INT_MIN;
        high = NULL;
        while (temp)
        {
            if (temp->value == INT_MIN && temp->index == 0)
                temp->index = 1;
            if (temp->value > value && temp->index == 0)
            {
                value = temp->value;
                high = temp;
            }
            else
                temp = temp->next;
        }
        if (high)
            high->index = size;
    }
}
