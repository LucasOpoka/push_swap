/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:05:25 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/13 16:06:14 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	ft_rot_ind(int curr_ind, int offset, int size)
{
	return ((curr_ind + offset + size) % size);
}

void	ft_sa(t_stack *a)
{
	int	next_ind;
	int	tmp;

	if (a->end > 1)
	{
		tmp = a->arr[a->start];
		next_ind = ft_rot_ind(a->start, 1, a->size);
		a->arr[a->start] = a->arr[next_ind];
		a->arr[next_ind] = tmp;
	}
	ft_printf("sa\n");
}

void	ft_sb(t_stack *b)
{
	int	next_ind;
	int	tmp;

	if (b->end > 1)
	{
		tmp = b->arr[b->start];
		next_ind = ft_rot_ind(b->start, 1, b->size);
		b->arr[b->start] = b->arr[next_ind];
		b->arr[next_ind] = tmp;
	}
	ft_printf("sb\n");
}

void	ft_ss(t_stack *a, t_stack *b)
{
	int	next_ind;
	int	tmp;

	if (a->end > 1)
	{
		tmp = a->arr[a->start];
		next_ind = ft_rot_ind(a->start, 1, a->size);
		a->arr[a->start] = a->arr[next_ind];
		a->arr[next_ind] = tmp;
	}
	if (b->end > 1)
	{
		tmp = b->arr[b->start];
		next_ind = ft_rot_ind(b->start, 1, b->size);
		b->arr[b->start] = b->arr[next_ind];
		b->arr[next_ind] = tmp;
	}
	ft_printf("ss\n");
}
