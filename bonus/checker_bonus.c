/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:23:07 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/18 16:15:59 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	free_arr(char **v)
{
	int	i;

	i = 0;
	while (v[i])
	{
		free(v[i]);
		i++;
	}
	free(v);
}

static void	ft_operations(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(line, "sa\n"))
		ft_sa(stack_a);
	else if (!ft_strcmp(line, "sb\n"))
		ft_sb(stack_b);
	else if (!ft_strcmp(line, "ss\n"))
		ft_ss(stack_a, stack_b);
	else if (!ft_strcmp(line, "pa\n"))
		ft_pa(stack_a, stack_b);
	else if (!ft_strcmp(line, "pb\n"))
		ft_pb(stack_a, stack_b);
	else if (!ft_strcmp(line, "ra\n"))
		ft_ra(stack_a);
	else if (!ft_strcmp(line, "rb\n"))
		ft_rb(stack_b);
	else if (!ft_strcmp(line, "rr\n"))
		ft_rr(stack_a, stack_b);
	else if (!ft_strcmp(line, "rra\n"))
		ft_rra(stack_a);
	else if (!ft_strcmp(line, "rrb\n"))
		ft_rrb(stack_b);
	else if (!ft_strcmp(line, "rrr\n"))
		ft_rrr(stack_a, stack_b);
	else
		ft_error();
}

void	ft_read(char *line, t_stack **stack_a, t_stack **stack_b)
{
	line = get_next_line(0);
	while (line)
	{
		if (!line)
			break ;
		ft_operations(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (ft_is_sorted(*stack_a) && !(*stack_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int c, char **v)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**str;
	char	*line;

	str = NULL;
	line = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (c > 1)
	{
		str = ft_stack(v);
		ft_parsing(str);
		ft_fill_stack(str, &stack_a);
		free_arr(str);
		ft_read(line, &stack_a, &stack_b);
		ft_free_stack(&stack_a);
		ft_free_stack(&stack_b);
	}
	return (0);
}
