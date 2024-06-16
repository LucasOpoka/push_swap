/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:50:11 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/16 20:51:22 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_init_stack_a(int count, t_stack *a)
{
	a->start = count;
	a->end = 0;
	a->size = count;
	a->arr = (int *) malloc(count * sizeof(int));
	a->cmnd_count = 0;
	a->cmnd.i = 0;
	a->cmnd.index = 0;
	a->cmnd.size = 100;
	a->cmnd.toadd = 100;
	a->cmnd.err = 0;
	a->cmnd.res = (char *) malloc(a->cmnd.size);
}

void	ft_init_stack_b(int count, t_stack *b)
{
	b->start = count;
	b->end = 0;
	b->size = count;
	b->arr = (int *) malloc(count * sizeof(int));
	b->cmnd_count = 0;
}

void	ft_init_both_stacks(t_stack *a, t_stack *b, int ac, char **av)
{
	int			count;

	count = ft_validate_av(ac, av, 0);
	ft_init_stack_a(count, a);
	ft_init_stack_b(count, b);
	if (!a->arr || !b->arr || !a->cmnd.res)
	{
		ft_free(a, b);
		ft_exit();
	}
	ft_validate_av(ac, av, a);
	ft_check_dups(a, b);
}
