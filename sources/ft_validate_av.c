/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_av.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:36:40 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/12 12:31:58 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	ft_validate_av(int ac, char **av, t_stack *a)
{
	int	i;
	int count;
	int	tmp;

	ac--;
	tmp = ac;
	count = 0;
	while (ac > 0)
	{
		i = ft_strlen(av[ac]) - 1;
		while (i >= 0 && av[ac][i] == ' ')
			i--;
		while (i >= 0)
		{
			while (i >= 0 && av[ac][i] != ' ')
			{
				if (!ft_isdigit(av[ac][i]) && av[ac][i] != '-' && av[ac][i] != '+')
				{
					ft_printf_fd(2, "Invalid number passed as argument\n");
					exit (1);
				}
				i--;
			}
			if (a)
			{
				a->arr[--a->start] = ft_atoi(&av[ac][i + 1]);
				a->end++;
			}
			count++;
			while (i >= 0 && av[ac][i] == ' ')
				i--;
		}
		ac--;
	}
	if (count < tmp)
	{
		ft_printf_fd(2, "Invalid number passed as argument\n");
		exit (1);
	}
	return (count);
}
