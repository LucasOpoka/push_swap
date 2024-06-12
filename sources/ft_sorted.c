/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:47:02 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/12 13:01:08 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	ft_sorted(t_stack *stack)
{
	int	i;
	int	val;
	int	next_val;

	i = 1;
	val = stack->arr[stack->start];

	while (i < stack->end - 1)
	{
		next_val = stack->arr[ft_rot_ind(i, 1, stack->size)];
		if (val > next_val)
			return (0);
		val = next_val;
		i++;
	}
	return (1);
}
