/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:36:37 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/13 17:10:44 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_fill_a(t_stack *a, int ac, char **av)
{
	ft_validate_av(ac, av, a);
}

void	ft_init_stacks(t_stack *a, t_stack *b, int ac, char **av)
{
	int	count;

	count = ft_validate_av(ac, av, 0);
	a->start = count;
	a->end = 0;
	a->size = count;
	a->arr = (int *) malloc(count * sizeof(int));
	if (!a->arr)
	{
		ft_printf_fd(2, "Stack allocation failed\n");
		exit (1);
	}
	ft_fill_a(a, ac, av);
	b->start = count;
	b->end = 0;
	b->size = count;
	b->arr = (int *) malloc(count * sizeof(int));
	if (!b->arr)
	{
		ft_printf_fd(2, "Stack allocation failed\n");
		free(a->arr);
		exit (1);
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	ft_init_stacks(&a, &b, ac, av);
	ft_move_to_b(&a, &b);
	if (a.end == 3)
		ft_sort_three(&a);
	ft_move_to_a(&a, &b);
	ft_min_to_top(&a);
	return (0);
}
