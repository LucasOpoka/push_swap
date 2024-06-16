/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:30:34 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/16 10:15:50 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static inline void	ft_prep_a(int moves, t_stack *a, t_stack *b, int reverse)
{
	if (!reverse)
	{
		while (moves > 0)
		{
			ft_ra(a, b);
			moves--;
		}
	}
	else
	{
		while (moves > 0)
		{
			ft_rra(a, b);
			moves--;
		}
	}
}

void	ft_push_to_a(t_stack *a, t_stack *b)
{
	t_nix	target;
	t_nix	max;
	t_nix	min;

	while (b->end != 0)
	{
		max = ft_stack_max(a);
		min = ft_stack_min(a);
		if (b->arr[b->start] > max.n)
			target = min;
		else
			target = ft_lwst_bgr(b->arr[b->start], a);
		if (target.ix < (a->end - target.ix))
			ft_prep_a(target.ix, a, b, 0);
		else
			ft_prep_a(a->end - target.ix, a, b, 1);
		ft_pa(a, b);
	}
}
