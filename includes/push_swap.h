/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:00:53 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/11 15:02:03 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../sources/libft/libft.h"

typedef struct s_stack
{
	int		*arr;
	int		size;
	int		start;
	int		end;
}	t_stack;


int	ft_validate_av(int ac, char **av, t_stack *a);
void ft_print_circ_arr(t_stack *stack);
void ft_sa(t_stack *a);

#endif
