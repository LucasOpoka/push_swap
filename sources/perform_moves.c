/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:03:33 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/16 11:12:41 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_n_single_moves(int n, t_stack *a, t_stack *b,
			void (*f)(t_stack *a, t_stack *b))
{
	while (n > 0)
	{
		f(a, b);
		n--;
	}
}

void	ft_n_double_moves(int n, t_stack *a, t_stack *b,
			void (*f)(t_stack *a, t_stack *b))
{
	while (n > 0)
	{
		f(a, b);
		n--;
	}
}
