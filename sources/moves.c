/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:51:15 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/13 15:43:11 by lopoka           ###   ########.fr       */
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

void	ft_rra(t_stack *a)
{
	int	tmp;

	if (a->end > 1)
	{
		tmp = a->arr[ft_rot_ind(a->start, a->end - 1, a->size)];
		a->start = ft_rot_ind(a->start, -1, a->size);
		a->arr[a->start] = tmp;
	}
	ft_printf("rra\n");
}

void	ft_rrb(t_stack *b)
{
	int	tmp;

	if (b->end > 1)
	{
		tmp = b->arr[ft_rot_ind(b->start, b->end - 1, b->size)];
		b->start = ft_rot_ind(b->start, -1, b->size);
		b->arr[b->start] = tmp;
	}
	ft_printf("rrb\n");
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
	ft_printf("rrr\n");
}
