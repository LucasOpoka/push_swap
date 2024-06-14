/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:01:57 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/14 13:17:41 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_free(t_stack *a, t_stack *b)
{
	if (a->arr)
		free(a->arr);
	if (b->arr)
		free(b->arr);
}

void	ft_exit(void)
{
	ft_printf_fd(2, "Error\n");
	exit (1);
}
