/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atollst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:36:40 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/10 15:16:33 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include <stdio.h>

t_node	*ft_atollst(int ac, char **av)
{
	int	i;
	

	if (ac == 2)
	{
		i = ft_strlen(av[1]) - 1;
		while (i >= 0)
		{
			while (i > 0 && av[1][i] != ' ')
				i--;	
			ft_printf("%d\n", ft_atoi(&av[1][i]));
			while (av[1][i] == ' ')
				i--;
		}
	}
	return (0);
	}

int main(int ac, char **av)
{
	ft_atollst(ac, av);
	return (0);
}

