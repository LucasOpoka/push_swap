/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:49:35 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/15 12:02:04 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static inline void	ft_check_overflow(long n, t_stack *a)
{
	if (n < -2147483648 || n > 2147483647)
	{
		free(a->arr);
		ft_exit();
	}
}

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
		ft_check_overflow(res * sign, a);
		str++;
	}
	return ((int)(res * sign));
}
