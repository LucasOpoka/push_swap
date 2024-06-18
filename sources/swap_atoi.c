/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:49:35 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/18 18:45:04 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static inline void	ft_check_overflow(long n)
{
	if (n < -2147483648 || n > 2147483647)
		ft_exit();
}

int	ft_swap_atoi(const char *str)
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
		ft_exit();
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + *str - 48;
		ft_check_overflow(res * sign);
		str++;
	}
	return ((int)(res * sign));
}
