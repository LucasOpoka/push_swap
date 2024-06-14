/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:04:49 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/14 12:13:05 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	ft_find_optimal_moves(t_stack *a, t_stack *b, int i, t_nix target)
{
	int	cost;
	int	tmp;

	cost = MAX(i, target.ix);
	tmp = MAX(a->end - i, b->end - target.ix);
	if (tmp < cost)
		cost = tmp;
	tmp = i + b->end - target.ix;
	if (tmp < cost)
		cost = tmp;
	tmp = target.ix + a->end - i;
	if (tmp < cost)
		cost = tmp;
	return (cost + 1);
}

t_nix	ft_min_cost(t_stack *a, t_stack *b)
{
	t_cst	c;

	c.i = 0;
	c.cost = -1;
	c.max = ft_stack_max(b);
	c.min = ft_stack_min(b);
	while (c.i < a->end)
	{
		c.val = a->arr[ft_rot_ind(a->start, c.i, a->size)];
		if (c.val > c.max.n || c.val < c.min.n)
			c.tmp = ft_find_optimal_moves(a, b, c.i, c.max);
		else
			c.tmp = ft_find_optimal_moves(a, b, c.i, ft_bgst_lwr(c.val, b));
		if (c.cost == -1 || c.tmp < c.cost)
		{
			c.cost = c.tmp;
			c.lwst_cst.n = c.val;
			c.lwst_cst.ix = c.i;
		}
		c.i++;
	}
	return (c.lwst_cst);
}

void	ft_perform_optimal_move(t_stack *a, t_stack *b,
			t_nix lwst_cst, t_nix target)
{
	int	plpl;
	int	mimi;
	int	plmi;
	int	mipl;

	plpl = MAX(a->end - lwst_cst.ix, b->end - target.ix);
	mimi = MAX(lwst_cst.ix, target.ix);
	plmi = (a->end - lwst_cst.ix) + target.ix;
	mipl = lwst_cst.ix + (b->end - target.ix);
	if (plpl < mimi && plpl < plmi && plpl < mipl)
		ft_rrr_case(a, b, lwst_cst, target);
	else if (mimi < plpl && mimi < plmi && mimi < mipl)
		ft_rr_case(a, b, lwst_cst, target);
	else if (plmi < plpl && plmi < mimi && plmi < mipl)
		ft_rra_rb_case(a, b, lwst_cst, target);
	else
		ft_ra_rrb_case(a, b, lwst_cst, target);
}

void	ft_push_on_budget(t_stack *a, t_stack *b, t_nix lwst_cst)
{
	t_nix	target;
	t_nix	min;
	t_nix	max;

	max = ft_stack_max(b);
	min = ft_stack_min(b);
	if (lwst_cst.n > max.n || lwst_cst.n < min.n)
		target = max;
	else
		target = ft_bgst_lwr(lwst_cst.n, b);
	ft_perform_optimal_move(a, b, lwst_cst, target);
}

void	ft_push_to_b(t_stack *a, t_stack *b)
{
	t_nix	lwst_cst;

	if (a->end > 3 && !ft_sorted(a))
		ft_pb(a, b);
	if (a->end > 3 && !ft_sorted(a))
		ft_pb(a, b);
	while (a->end > 3 && !ft_sorted(a))
	{
		lwst_cst = ft_min_cost(a, b);
		ft_push_on_budget(a, b, lwst_cst);
	}
}
