/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:36:37 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/11 20:50:06 by lopoka           ###   ########.fr       */
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

int main(int ac, char **av)
{
	t_stack	a;
	t_stack b;
	t_stack c;

	ft_init_stacks(&a, &b, ac, av);
	ft_print_circ_arr(&a);
	ft_printf("Size = %d, start = %d, end %d\n", a.size, a.start, a.end);


	c.arr = malloc(10 * sizeof(int));
 	c.start = 9;
	c.end = 3;
	c.arr[9] = 1;
	c.arr[0] = 2;
	c.arr[1] = 3;
	c.size = 10;
	
	ft_printf("Test\n");
	ft_print_circ_arr(&a);

	ft_printf("Push B twice Test\n");
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_print_circ_arr(&b);
	ft_rb(&b);
	ft_rb(&b);
	ft_rb(&b);
	ft_print_circ_arr(&b);	
	ft_rra(&b);
	ft_rra(&b);
	ft_print_circ_arr(&b);
	return (0);
}
