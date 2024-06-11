/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:51:15 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/11 15:04:47 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void ft_sa(t_stack *a)
{
	int tmp;

	if (a->end > 1)
	{
		tmp = a->arr[a->start];
		a->arr[a->start] = a->arr[(a->start + 1) % a->size];
		a->arr[(a->start + 1) % a->size] = tmp;
	}
}
