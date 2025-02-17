/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:29:48 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/17 23:45:58 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
