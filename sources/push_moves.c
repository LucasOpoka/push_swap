/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:51:15 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/13 16:20:52 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_pa(t_stack *a, t_stack *b)
{
	if (b->end > 0)
	{
		b->start = ft_rot_ind(b->start, 1, b->size);
		b->end--;
		a->start = ft_rot_ind(a->start, -1, a->size);
		a->arr[a->start] = b->arr[ft_rot_ind(b->start, -1, b->size)];
		a->end++;
	}
	ft_printf("pa\n");
}

void	ft_pb(t_stack *a, t_stack *b)
{
	if (a->end > 0)
	{
		a->start = ft_rot_ind(a->start, 1, a->size);
		a->end--;
		b->start = ft_rot_ind(b->start, -1, b->size);
		b->arr[b->start] = a->arr[ft_rot_ind(a->start, -1, a->size)];
		b->end++;
	}
	ft_printf("pb\n");
}
