/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:17:08 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/16 12:34:18 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_rra(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->end > 1)
	{
		tmp = a->arr[ft_rot_ind(a->start, a->end - 1, a->size)];
		a->start = ft_rot_ind(a->start, -1, a->size);
		a->arr[a->start] = tmp;
	}
	ft_add_cmnd(a, b, "rra\n");
}

void	ft_rrb(t_stack *a, t_stack *b)
{
	int	tmp;

	if (b->end > 1)
	{
		tmp = b->arr[ft_rot_ind(b->start, b->end - 1, b->size)];
		b->start = ft_rot_ind(b->start, -1, b->size);
		b->arr[b->start] = tmp;
	}
	ft_add_cmnd(a, b, "rrb\n");
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->end > 1)
	{
		tmp = a->arr[ft_rot_ind(a->start, a->end - 1, a->size)];
		a->start = ft_rot_ind(a->start, -1, a->size);
		a->arr[a->start] = tmp;
	}
	if (b->end > 1)
	{
		tmp = b->arr[ft_rot_ind(b->start, b->end - 1, b->size)];
		b->start = ft_rot_ind(b->start, -1, b->size);
		b->arr[b->start] = tmp;
	}
	ft_add_cmnd(a, b, "rrr\n");
}
