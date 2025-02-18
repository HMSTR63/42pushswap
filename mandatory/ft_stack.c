/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:13:22 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/10 18:36:06 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_full_space(char *s)
{
	while (*s == ' ')
		s++;
	if (*s == '\0')
		return (1);
	return (0);
}
static char	*ft_join_args(char **v)
{
	char	*tmp;
	int		i;

	i = 1;
	tmp = ft_strdup("");
	while (v[i])
	{
		if (ft_is_full_space(v[i]))
			return (NULL);
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
