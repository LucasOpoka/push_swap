/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_min_max_bl_lb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:46:04 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/17 16:48:37 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

t_nix	ft_stack_min(t_stack *stack)
{
	t_nix	min;
	int		val;
	int		i;

	i = 0;
	min.ix = -1;
	while (i < stack->end)
	{
		val = stack->arr[ft_rot_ind(stack->start, i, stack->size)];
		if (min.ix == -1 || val < min.n)
		{
			min.n = val;
			min.ix = i;
		}
		i++;
	}
	return (min);
}

t_nix	ft_stack_max(t_stack *stack)
{
	t_nix	max;
	int		val;
	int		i;

	i = 0;
	max.ix = -1;
	while (i < stack->end)
	{
		val = stack->arr[ft_rot_ind(stack->start, i, stack->size)];
		if (max.ix == -1 || val > max.n)
		{
			max.n = val;
			max.ix = i;
		}
		i++;
	}
	return (max);
}

t_nix	ft_bgst_lwr(int target, t_stack *stack)
{
	int		i;
	int		val;
	t_nix	bgst_lwr;

	i = 0;
	bgst_lwr.ix = -1;
	while (i < stack->end)
	{
		val = stack->arr[ft_rot_ind(stack->start, i, stack->size)];
		if (val < target && (bgst_lwr.ix == -1 || val > bgst_lwr.n))
		{
			bgst_lwr.n = val;
			bgst_lwr.ix = i;
		}
		i++;
	}
	return (bgst_lwr);
}

t_nix	ft_lwst_bgr(int target, t_stack *stack)
{
	int		i;
	int		val;
	t_nix	lwst_bgr;

	i = 0;
	lwst_bgr.ix = -1;
	while (i < stack->end)
	{
		val = stack->arr[ft_rot_ind(stack->start, i, stack->size)];
		if (val > target && (lwst_bgr.ix == -1 || val < lwst_bgr.n))
		{
			lwst_bgr.n = val;
			lwst_bgr.ix = i;
		}
		i++;
	}
	return (lwst_bgr);
}
