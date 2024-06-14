/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:36:37 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/14 15:54:34 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_check_dups(t_stack *a)
{
	int	i;
	int j;

	i = 0;
	while (i < a->end)
	{
		j = i + 1;
		while (j < a->end)
		{
			if (a->arr[ft_rot_ind(a->start, i, a->size)]
					== a->arr[ft_rot_ind(a->start, j, a->size)])
			{
				free(a->arr);
				ft_exit();
			}
			j++;
		}
		i++;
	}
}

void	ft_init_one_stack(int count, t_stack *stack)
{
	stack->start = count;
	stack->end = 0;
	stack->size = count;
	stack->arr = (int *) malloc(count * sizeof(int));
}

void	ft_init_both_stacks(t_stack *a, t_stack *b, int ac, char **av)
{
	int	count;

	count = ft_validate_av(ac, av, 0);
	ft_init_one_stack(count, a);
	if (!a->arr)
		ft_exit();
	ft_validate_av(ac, av, a);
	ft_check_dups(a);
	ft_init_one_stack(count, b);
	if (!b->arr)
	{
		ft_free(a, b);
		ft_exit();
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	ft_init_both_stacks(&a, &b, ac, av);
	ft_push_to_b(&a, &b);
	if (a.end == 3)
		ft_sort_three(&a);
	ft_push_to_a(&a, &b);
	ft_min_to_top(&a);
	ft_free(&a, &b);
	return (0);
}
