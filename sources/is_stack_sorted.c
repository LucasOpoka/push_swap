/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:08:25 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/15 14:39:50 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	ft_circ_sorted(t_stack *stack)
{
	t_nix	min;
	int		i;
	int		val;
	int		next_val;

	min = ft_stack_min(stack);
	i = (min.ix + 1) % (stack->end);
	val = min.n;
	while (i != min.ix)
	{
		next_val = stack->arr[ft_rot_ind(stack->start, i, stack->size)];
		if (val > next_val)
			return (0);
		val = next_val;
		i = (i + 1) % (stack->end);
	}
	return (1);
}
