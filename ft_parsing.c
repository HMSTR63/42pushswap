/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:15:12 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/02 23:28:26 by sojammal         ###   ########.fr       */
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
static int     ft_valid_args(char **v) // this function will check if the arguments are valid
{
    int i;
    int j;

    i = 0;
    while (v[i]) // while the character is not null
    {
        j = 0;
        if (ft_is_signed(v[i][j])) // if the character is signed
        {
            if (v[i][++j] == '0')
                return (0);
        }
        if (v[i][j] == '\0') // if the character is null
            return (0); 
        if (v[i][j] == '0' && v[i][j + 1] != '\0') // if the character is 0 and the next character is not null
            return (0);
        while (v[i][j]) // while the character is not null
        {
            if (!ft_is_digit(v[i][j])) // if the character is not a digit and not signed
                return (0);
            j++;
        }
        i++;
    }
    if (i == 0) // if the character is null
        return (0);
    return (1);
}
static int  ft_is_duplicated(char **v) // this function will check if the arguments are duplicated
{
    int i;
    int j;

    i = 0;
    while (v[i]) // while the character is not null
    {
        j = i + 1;
        while (v[j]) // while the character is not null
        {
            if (ft_atoi(v[i]) == ft_atoi(v[j])) // if the first argument is equal to the second argument
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
    while (v[i]) // while the character is not null
    {
        j = 0;
        while (v[i][j]) // while the character is not null
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
        return(ft_error(), free(v));
    else if (!ft_valid_args(v))
        return(ft_error(), free(v));
    else if (!ft_is_duplicated(v))
        return(ft_error(), free(v));
    else if (!ft_is_space(v))
        return(ft_error(), free(v));
}

