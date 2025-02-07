/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:12:20 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/02 21:51:03 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_w(const char *s, char c)
{
	size_t	count;
	size_t	is_w;
	size_t	i;

	count = 0;
	is_w = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			is_w = 1;
		else if (is_w == 1)
		{
			count++;
			is_w = 0;
		}
		i++;
	}
	return (count);
}

static void	ft_free_list(char **list)
{
	size_t	i;

	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
}
static char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_l;
	char	*sub;

	if (!s)
		return (NULL);
	s_l = ft_strlen(s);
	if (start >= s_l)
		return (ft_strdup(""));
	if (len > (s_l - start))
		len = s_l - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], len + 1);
	sub[len] = '\0';
	return (sub);
}
static char	**ft_stor_list(char **list, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (j < i)
		{
			list[x] = ft_substr(s, j, i - j);
			if (list[x] == NULL)
				return (ft_free_list(list), NULL);
			x++;
		}
	}
	list[x] = NULL;
	return (list);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	size_t	new_word;

	if (s == NULL)
		return (NULL);
	new_word = ft_count_w(s, c);
	list = malloc((new_word + 1) * sizeof(char *));
	if (list == NULL)
		return (NULL);
	list = ft_stor_list(list, s, c);
	return (list);
}
