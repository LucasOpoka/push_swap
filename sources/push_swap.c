/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:36:37 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/16 12:43:29 by lopoka           ###   ########.fr       */
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

void	ft_init_one_stack(int count, t_stack *stack)
{
	stack->start = count;
	stack->end = 0;
	stack->size = count;
	stack->arr = (int *) malloc(count * sizeof(int));
	stack->cmnd_count = 0;
	stack->cmnd.i = 0;
	stack->cmnd.index = 0;
	stack->cmnd.size = 100;
	stack->cmnd.toadd = 100;
	stack->cmnd.err = 0;
	stack->cmnd.res = (char *) malloc(stack->cmnd.size);
}

void	ft_init_both_stacks(t_stack *a, t_stack *b, int ac, char **av)
{
	int			count;

	count = ft_validate_av(ac, av, 0);
	ft_init_one_stack(count, a);
	ft_init_one_stack(count, b);
	if (!a->arr || !b->arr || !a->cmnd.res || !b->cmnd.res)
	{
		ft_free(a, b);
		ft_exit();
	}
	ft_validate_av(ac, av, a);
	ft_check_dups(a, b);
}

static inline void	ft_sort_a(int i, int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		j;

	j = i;
	ft_init_both_stacks(&a, &b, ac, av);
	while (j--)
		ft_ra(&a, &b);
	ft_push_to_b(&a, &b);
	if (a.end == 3)
		ft_sort_three(&a, &b);
	ft_min_to_top(&a, &b);
	ft_push_to_a(&a, &b);
	ft_min_to_top(&a, &b);
	if (a.size != 500 || (a.size == 500 && a.cmnd_count <= 5500)
		|| (i + 1 == a.size))
	{
		ft_print_cmnd(&a);
		ft_free(&a, &b);
	}
	else
	{
		ft_free(&a, &b);
		ft_sort_a(i + 1, ac, av);
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
		exit(1);
	ft_sort_a(0, ac, av);
	return (0);
}

/*ft_init_both_stacks(&a, &b, ac, av);
//while (i)
//{
//	ft_ra(&a, &b);
//	i--;
//}
ft_push_to_b(&a, &b);
if (a.end == 3)
ft_sort_three(&a, &b);
ft_min_to_top(&a, &b);
ft_push_to_a(&a, &b);
ft_min_to_top(&a, &b);
ft_print_cmnd(&a);
ft_free(&a, &b);*/
