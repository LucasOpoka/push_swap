/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:39:11 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/17 17:12:37 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static inline int	ft_read_cmnd(char *line)
{
	int		i;
	int		ret;
	char	c;

	i = 0;
	ret = read(0, &c, 1);
	while (ret && c && i < 6)
	{
		line[i++] = c;
		if (c == 10)
			break ;
		ret = read(0, &c, 1);
	}
	line[i] = 0;
	return (i);
}

static inline int	ft_sorted(t_stack *stack)
{
	int	i;
	int	val;
	int	next_val;

	i = 1;
	val = stack->arr[stack->start];
	while (i < stack->end)
	{
		next_val = stack->arr[ft_rot_ind(stack->start, i, stack->size)];
		if (val > next_val)
			return (0);
		val = next_val;
		i++;
	}
	return (1);
}

static inline int	ft_perform_cmnd(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		ft_sa(a, b);
	else if (!ft_strcmp(line, "sb\n"))
		ft_sb(a, b);
	else if (!ft_strcmp(line, "ss\n"))
		ft_ss(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		ft_pa(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		ft_pb(a, b);
	else if (!ft_strcmp(line, "ra\n"))
		ft_ra(a, b);
	else if (!ft_strcmp(line, "rb\n"))
		ft_rb(a, b);
	else if (!ft_strcmp(line, "rr\n"))
		ft_rr(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		ft_rra(a, b);
	else if (!ft_strcmp(line, "rrb\n"))
		ft_rrb(a, b);
	else if (!ft_strcmp(line, "rrr\n"))
		ft_rrr(a, b);
	else
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	line[7];

	ft_init_both_stacks(&a, &b, ac, av);
	while (ft_read_cmnd(line))
	{
		if (ft_perform_cmnd(&a, &b, line))
		{
			ft_free(&a, &b);
			ft_exit();
		}
	}
	if (ft_sorted(&a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free(&a, &b);
	return (0);
}
