/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:14:35 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/16 10:16:28 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_sort_three(t_stack *a, t_stack *b)
{
	t_nix	max;

	max = ft_stack_max(a);
	if (a->arr[a->start] == max.n)
		ft_ra(a, b);
	else if (a->arr[ft_rot_ind(a->start, 1, a->size)] == max.n)
		ft_rra(a, b);
	if (a->arr[a->start] > a->arr[ft_rot_ind(a->start, 1, a->size)])
		ft_sa(a, b);
}
