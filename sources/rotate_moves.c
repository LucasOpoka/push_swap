/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:13:25 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/13 16:14:27 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_ra(t_stack *a)
{
	int	new_last_ind;
	int	tmp;

	if (a->end > 1)
	{
		tmp = a->arr[a->start];
		a->start = ft_rot_ind(a->start, 1, a->size);
		new_last_ind = ft_rot_ind(a->start, a->end - 1, a->size);
		a->arr[new_last_ind] = tmp;
	}
	ft_printf("ra\n");
}

void	ft_rb(t_stack *b)
{
	int	new_last_ind;
	int	tmp;

	if (b->end > 1)
	{
		tmp = b->arr[b->start];
		b->start = ft_rot_ind(b->start, 1, b->size);
		new_last_ind = ft_rot_ind(b->start, b->end - 1, b->size);
		b->arr[new_last_ind] = tmp;
	}
	ft_printf("rb\n");
}

void	ft_rr(t_stack *a, t_stack *b)
{
	int	new_last_ind;
	int	tmp;

	if (a->end > 1)
	{
		tmp = a->arr[a->start];
		a->start = ft_rot_ind(a->start, 1, a->size);
		new_last_ind = ft_rot_ind(a->start, a->end - 1, a->size);
		a->arr[new_last_ind] = tmp;
	}
	if (b->end > 1)
	{
		tmp = b->arr[b->start];
		b->start = ft_rot_ind(b->start, 1, b->size);
		new_last_ind = ft_rot_ind(b->start, b->end - 1, b->size);
		b->arr[new_last_ind] = tmp;
	}
	ft_printf("rr\n");
}
