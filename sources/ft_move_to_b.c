/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:04:49 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/12 21:34:44 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

t_nix	ft_bgst_lwr(int target, t_stack *stack)
{
	int		i;
	int		val;
	t_nix	bgst_lwr;

	i = 0;
	bgst_lwr.n = INT_MIN;
	while (i < stack->end)
	{
		val = stack->arr[ft_rot_ind(stack->start, i, stack->size)];
		if (val < target && val > bgst_lwr.n)
		{
			bgst_lwr.n = val;
			bgst_lwr.ix = i;
		}
		i++;
	}
	return (bgst_lwr);
}

t_nix	ft_stack_max(t_stack *stack)
{
	t_nix	max;
	int		val;
	int		i;

	i = 0;
	max.n = INT_MIN;
	while (i < stack->end)
	{
		val = stack->arr[ft_rot_ind(stack->start, i, stack->size)];
		if (val > max.n)
		{
			max.n = val;
			max.ix = i;
		}
		i++;
	}
	return (max);
}	

t_nix	ft_stack_min(t_stack *stack)
{
	t_nix	min;
	int		val;
	int		i;

	i = 0;
	min.n = INT_MAX;
	while (i < stack->end)
	{
		val = stack->arr[ft_rot_ind(stack->start, i, stack->size)];
		if (val < min.n)
		{
			min.n = val;
			min.ix = i;
		}
		i++;
	}
	return (min);
}	

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
	t_nix	lwst_cst;
	t_nix	target;
	t_nix	min;
	t_nix	max;
	int		i;
	int		val;
	int		cost;
	int		tmp;

	i = 0;
	cost = INT_MAX;
	max = ft_stack_max(b);
	min = ft_stack_min(b);
	while (i < a->end)
	{
		val = a->arr[ft_rot_ind(a->start, i, a->size)];
		if (val > max.n || val < min.n)
			target = max;
		else
			target = ft_bgst_lwr(val, b);
		tmp = ft_find_optimal_moves(a, b, i, target);
		//ft_printf("COST for %d is %d\n", val, tmp);
		if (tmp < cost)
		{
			cost = tmp;
			lwst_cst.n = val;
			lwst_cst.ix = i;
		}
		i++;
	}
	return (lwst_cst);
}	

void	ft_rrr_case(t_stack *a, t_stack *b, t_nix lwst_cst, t_nix target)
{
	int	move_a;
	int	move_b;
	int common;
	int	i;

	move_a = a->end - lwst_cst.ix;
	move_b = b->end - target.ix;
	common = MIN(move_a, move_b);
	move_a -= common;
	move_b -= common;
	i = 0;
	while (i < common)
	{
		ft_rrr(a, b);
		i++;
	}
	i = 0;
	while (i < move_a)
	{
		ft_rra(a);
		i++;
	}
	i = 0;
	while (i < move_b)
	{
		ft_rrb(b);
		i++;
	}
	ft_pb(a, b);
}

void	ft_rr_case(t_stack *a, t_stack *b, t_nix lwst_cst, t_nix target)
{
	int	move_a;
	int	move_b;
	int common;
	int	i;

	move_a = lwst_cst.ix;
	move_b = target.ix;
	common = MIN(move_a, move_b);
	move_a -= common;
	move_b -= common;
	i = 0;
	while (i < common)
	{
		ft_rr(a, b);
		i++;
	}
	i = 0;
	while (i < move_a)
	{
		ft_ra(a);
		i++;
	}
	i = 0;
	while (i < move_b)
	{
		ft_rb(b);
		i++;
	}
	ft_pb(a, b);
}

void	ft_rra_rb_case(t_stack *a, t_stack *b, t_nix lwst_cst, t_nix target)
{
	int	move_a;
	int	move_b;
	int	i;

	move_a = a->end - lwst_cst.ix;
	move_b = target.ix;
	i = 0;
	while (i < move_a)
	{
		ft_rra(a);
		i++;
	}
	i = 0;
	while (i < move_b)
	{
		ft_rb(b);
		i++;
	}
	ft_pb(a, b);
}

void	ft_ra_rrb_case(t_stack *a, t_stack *b, t_nix lwst_cst, t_nix target)
{
	int	move_a;
	int	move_b;
	int	i;

	move_a = lwst_cst.ix;
	move_b = b->end - target.ix;
	i = 0;
	while (i < move_a)
	{
		ft_ra(a);
		i++;
	}
	i = 0;
	while (i < move_b)
	{
		ft_rrb(b);
		i++;
	}
	ft_pb(a, b);
}

void	ft_perform_optimal_move(t_stack *a, t_stack *b, t_nix lwst_cst, t_nix target)
{
	int	plpl;
	int	mimi;
	int plmi;
	int mipl;
	
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
	ft_perform_optimal_move(a, b,lwst_cst, target);
}

void	ft_move_to_b(t_stack *a, t_stack *b)
{
	t_nix lwst_cst;

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
