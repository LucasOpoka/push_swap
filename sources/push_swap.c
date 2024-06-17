/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:36:37 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/17 11:59:20 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static inline void	ft_sort_a_sub(int i, t_stack *a, t_stack *b)
{
	while (i--)
		ft_ra(a, b);
	ft_push_to_b(a, b);
	if (a->end == 3)
		ft_sort_three(a, b);
	ft_min_to_top(a, b);
	ft_push_to_a(a, b);
	ft_min_to_top(a, b);
}

static inline void	ft_sort_a(int i, int target, int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	ft_init_both_stacks(&a, &b, ac, av);
	ft_sort_a_sub(i, &a, &b);
	if (a.size != 500 || (a.size == 500 && a.cmnd_count <= target))
	{
		ft_print_cmnd(&a);
		ft_free(&a, &b);
	}
	else
	{
		ft_free(&a, &b);
		if (i + 1 < a.size)
			ft_sort_a(i + 1, target, ac, av);
		else
			ft_sort_a(0, target + 500, ac, av);
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
		exit(1);
	ft_sort_a(0, 5500, ac, av);
	return (0);
}
