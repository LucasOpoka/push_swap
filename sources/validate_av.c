/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:36:40 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/13 17:11:12 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static inline void	ft_exit(void)
{
	ft_printf_fd(2, "Error\n");
	exit (1);
}

static inline void	ft_stack_add_num(int i, int ac, char **av, t_stack *a)
{
	a->arr[--a->start] = ft_atoi(&av[ac][i + 1]);
	a->end++;
}

static inline int	ft_skip_whitespaces(int i, int ac, char **av)
{
	while (i >= 0 && av[ac][i] == ' ')
		i--;
	return (i);
}

static inline int	ft_get_num_start(int i, int ac, char **av)
{
	while (i >= 0 && av[ac][i] != ' ')
	{
		if (!ft_isdigit(av[ac][i]) && av[ac][i] != '-' && av[ac][i] != '+')
			ft_exit();
		i--;
	}
	return (i);
}

int	ft_validate_av(int ac, char **av, t_stack *a)
{
	int	i;
	int	count;
	int	tmp;

	ac--;
	tmp = ac;
	count = 0;
	while (ac > 0)
	{
		i = ft_strlen(av[ac]) - 1;
		i = ft_skip_whitespaces(i, ac, av);
		while (i >= 0)
		{
			i = ft_get_num_start(i, ac, av);
			if (a)
				ft_stack_add_num(i, ac, av, a);
			count++;
			i = ft_skip_whitespaces(i, ac, av);
		}
		ac--;
	}
	if (count < tmp)
		ft_exit();
	return (count);
}
