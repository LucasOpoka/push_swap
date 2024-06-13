/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:30:34 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/13 16:00:19 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static inline t_nix	ft_lwst_bgr(int target, t_stack *stack)
{
	int		i;
	int		val;
	t_nix	lwst_bgr;

	i = 0;
	lwst_bgr.n = INT_MAX;
	while (i < stack->end)
	{
		val = stack->arr[ft_rot_ind(stack->start, i, stack->size)];
		if (val > target && val < lwst_bgr.n)
		{
			lwst_bgr.n = val;
			lwst_bgr.ix = i;
		}
		i++;
	}
	return (lwst_bgr);
}

static inline void	ft_prep_a(int moves, t_stack *a, int reverse)
{
	if (!reverse)
	{
		while (moves > 0)
		{
			ft_ra(a);
			moves--;
		}
	}
	else
	{
		while (moves > 0)
		{
			ft_rra(a);
			moves--;
		}
	}
}

void	ft_move_to_a(t_stack *a, t_stack *b)
{
	t_nix	target;
	t_nix	max;
	t_nix	min;

	while (b->end != 0)
	{
		max = ft_stack_max(a);
		min = ft_stack_min(a);
		if (b->arr[b->start] > max.n || b->arr[b->start] < min.n)
			target = min;
		else
			target = ft_lwst_bgr(b->arr[b->start], a);
		if (target.ix < (a->end - target.ix))
			ft_prep_a(target.ix, a, 0);
		else
			ft_prep_a(a->end - target.ix, a, 1);
		ft_pa(a, b);
	}
}
