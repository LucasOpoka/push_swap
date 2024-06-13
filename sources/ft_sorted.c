/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:47:02 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/13 22:26:07 by lucas            ###   ########.fr       */
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
