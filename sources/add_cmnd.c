/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmnd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:36:58 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/16 11:59:52 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_add_cmnd(t_stack *a, t_stack *b, char *str)
{
	ft_prnt_s(&a->cmnd, str);
	a->cmnd_count++;
	if (a->cmnd.err)
	{
		ft_free(a, b);
		ft_exit();
	}
}

void	ft_print_cmnd(t_stack *a)
{
	write(1, a->cmnd.res, a->cmnd.index);
}
