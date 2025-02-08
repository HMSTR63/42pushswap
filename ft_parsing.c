/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:15:12 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/09 00:46:36 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int  ft_is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}
int ft_valid_args(char **v) 
{
    int i;
    int j;
    
    i = 0;
    while (v[i])
    {
        j = 0;
        while (v[i][j])
        {
            if (!ft_is_digit(v[i][j]))
            {
                if (v[i][j] == '-' || v[i][j] == '+')
                {
                    if (ft_is_digit(v[i][j - 1]) || !ft_is_digit(v[i][j + 1]))
                        return (0);
                }
                else 
                    return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}
static int  ft_is_duplicated(char **v)
{
    int i;
    int j;

    i = 0;
    while (v[i])
    {
        j = i + 1;
        while (v[j])
        {
            if (ft_atoi(v[i]) == ft_atoi(v[j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

static int ft_is_space(char **v)
{
    int i;
    int j;

    i = 0;
    while (v[i])
    {
        j = 0;
        while (v[i][j])
        {
            if ((v[i][j] >= '\t' && v[i][j] <= '\r') || v[i][j] == ' ')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

void    ft_parsing(char **v)
{
    if (!v)
        return(ft_error(), free(v), exit(1));
    if (!ft_valid_args(v))
        return(ft_error(), free(v), exit(1));
    if (!ft_is_duplicated(v))
        return(ft_error(), free(v), exit(1));
    if (!ft_is_space(v))
        return(ft_error(), free(v), exit(1));
}
