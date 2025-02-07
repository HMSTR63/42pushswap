/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:23:20 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/02 22:29:18 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void ft_error(void)
{
    ft_putstr_fd("Error\n", 2);
    exit(1);
}
int ft_is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int ft_is_signed(char c)
{
    return (c == '-' || c == '+');
}
