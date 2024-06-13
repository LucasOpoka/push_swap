/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_arr_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:11:24 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/13 15:30:19 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_print_circ_arr(t_stack *stack)
{
	int	ind;

	ind = 0;
	while (ind < stack->end)
	{
		ft_printf("Arr %d\n", stack->arr[(stack->start + ind) % stack->size]);
		ind++;
	}
}
