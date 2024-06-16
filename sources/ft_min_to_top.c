/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:13:44 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/16 10:16:53 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_min_to_top(t_stack *a, t_stack *b)
{
	t_nix	min;
	int		moves;

	min = ft_stack_min(a);
	if (min.ix < (a->end - min.ix))
	{
		moves = min.ix;
		while (moves > 0)
		{
			ft_ra(a, b);
			moves--;
		}
	}
	else
	{
		moves = a->end - min.ix;
		while (moves > 0)
		{
			ft_rra(a, b);
			moves--;
		}
	}
}
