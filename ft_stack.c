/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:13:22 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/09 00:47:13 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	ft_check_input(char *v)
{
	int	i;
	int flag;
	
	i = 0;
	flag = 0;
	while (v[i])
	{
		if (v[i] >= '0' && v[i] <= '9')
			flag = 1;
		i++;
	}
	if (flag == 0)
		ft_error();
}
static char	*ft_join_args(char **v)
{
	char	*tmp;
	int		i;

	i = 1;
	tmp = ft_strdup("");
	while (v[i])
	{
		ft_check_input(v[i]);
		tmp = ft_strjoin(tmp, v[i]);
		tmp = ft_strjoin(tmp, " ");
		i++;
	}
	return (tmp);
}
char	**ft_stack(char **v)
{
	char	**str;
	char	*s;

	s = NULL;
	s = ft_join_args(v);
	str = ft_split(s, ' ');
	free(s);
	return (str);
}

