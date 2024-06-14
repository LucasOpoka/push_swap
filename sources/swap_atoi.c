/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:49:35 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/14 14:58:30 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	ft_swap_atoi(const char *str, t_stack *a)
{
	long	res;
	long	sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		free(a->arr);
		ft_exit();
	}
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + *str - 48;
		if ((res * sign < -2147483648) 
				|| (res * sign > 2147483647))
		{
			free(a->arr);
			ft_exit();
		}
		str++;
	}
	return ((int)(res * sign));
}
