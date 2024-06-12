/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:36:37 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/12 16:48:51 by lopoka           ###   ########.fr       */
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
	//t_nix	num;

	ft_init_stacks(&a, &b, ac, av);
	ft_print_circ_arr(&a);
	/*
	ft_printf("Size = %d, start = %d, end %d\n", a.size, a.start, a.end);
	ft_printf("Is A sorted: %d\n", ft_sorted(&a));
	num = ft_stack_min(&a);
	ft_printf("Min is %d at index %d\n", num.n, num.ix);
	num = ft_bgst_lwr(5, &a);
	ft_printf("Biggest lower than 5 is %d at index %d\n", num.n, num.ix);
	num = ft_stack_max(&a);
	ft_printf("Max is %d at index %d\n", num.n, num.ix);
	
	t_stack c;
	c.arr = malloc(10 * sizeof(int));
 	c.start = 9;
	c.end = 3;
	c.arr[9] = 1;
	c.arr[0] = 2;
	c.arr[1] = 3;
	c.size = 10;
	
	ft_printf("Test\n");
	ft_print_circ_arr(&a);
	
	ft_printf("2 x PB\n");
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);


	num = ft_min_cost(&a, &b);
	ft_printf("Min cost: %d at index %d\n", num.n, num.ix);

	ft_print_circ_arr(&b);
	ft_rb(&b);
	ft_rb(&b);
	ft_rb(&b);
	ft_print_circ_arr(&b);	
	ft_rra(&b);
	ft_rra(&b);
	ft_print_circ_arr(&b);
	*/
	ft_print_circ_arr(&a);
	ft_printf("\n");
	ft_print_circ_arr(&b);

	ft_move_to_b(&a, &b);
	
	ft_print_circ_arr(&a);
	ft_printf("\n");
	ft_print_circ_arr(&b);

	return (0);
}
