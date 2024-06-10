/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atollst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:36:40 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/10 20:50:50 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include <stdio.h>

t_node	*ft_atollst(char **av, int i)
{
	int	j;

	i--;
	while (i > 0)
	{
		j = ft_strlen(av[i]) - 1;
		while (j >= 0)
		{
			while (j >= 0 && av[i][j] != ' ')
			{
				if (!ft_isdigit(av[i][j]) && av[i][j] != '-' && av[i][j] != '+')
				{
					ft_printf_fd(2, "Invalid number passed as argument\n");
					exit (1);
				}
				j--;
			}
			ft_printf("%d\n", ft_atoi(&av[i][j + 1]));
			while (j >= 0 && av[i][j] == ' ')
				j--;
		}
		i--;
	}
	return (0);
}

int	main(int ac, char **av)
{
	ft_atollst(av, ac);
	return (0);
}
