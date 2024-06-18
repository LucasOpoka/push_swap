/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:36:40 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/18 18:48:51 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static inline void	ft_stack_add_num(int i, int ac, char **av, t_stack *a)
{
	int	j;

	j = ft_swap_atoi(&av[ac][i + 1]);
	if (a)
	{
		a->arr[--a->start] = j;
		a->end++;
	}
}

static inline int	ft_skip_whitespaces(int i, int ac, char **av)
{
	while (i >= 0 && (av[ac][i] == ' '
		|| (av[ac][i] >= '\t' && av[ac][i] <= '\r')))
		i--;
	return (i);
}

static inline int	ft_get_num_start(int i, int ac, char **av)
{
	int	has_digit;

	has_digit = 0;
	while (i >= 0 && av[ac][i] != ' ')
	{
		if (!ft_isdigit(av[ac][i]) && av[ac][i] != '-' && av[ac][i] != '+')
			ft_exit();
		if (!has_digit && (av[ac][i] == '-' || av[ac][i] == '+'))
			ft_exit();
		if (ft_isdigit(av[ac][i]))
			has_digit = 1;
		i--;
	}
	return (i);
}

int	ft_validate_av(int ac, char **av, t_stack *a)
{
	int	i;
	int	count;

	ac--;
	count = 0;
	while (ac > 0)
	{
		i = ft_strlen(av[ac]) - 1;
		i = ft_skip_whitespaces(i, ac, av);
		while (i >= 0)
		{
			i = ft_get_num_start(i, ac, av);
			ft_stack_add_num(i, ac, av, a);
			count++;
			i = ft_skip_whitespaces(i, ac, av);
		}
		ac--;
	}
	if (count == 0)
		exit(0);
	return (count);
}
