/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:55:55 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/16 20:56:05 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_check_dups(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->end)
	{
		j = i + 1;
		while (j < a->end)
		{
			if (a->arr[ft_rot_ind(a->start, i, a->size)]
				== a->arr[ft_rot_ind(a->start, j, a->size)])
			{
				ft_free(a, b);
				ft_exit();
			}
			j++;
		}
		i++;
	}
}
