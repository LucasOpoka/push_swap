/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:00:53 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/12 16:48:01 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "../sources/libft/libft.h"
# define MIN(a,b) (((a)<(b))?(a):(b))
# define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct s_stack
{
	int		*arr;
	int		size;
	int		start;
	int		end;
}	t_stack;

typedef struct s_nix
{
	int		n;
	int		ix;
}	t_nix;

int	ft_validate_av(int ac, char **av, t_stack *a);

int		ft_sorted(t_stack *stack);
void	ft_print_circ_arr(t_stack *stack);

//Min max bgst_lwr
t_nix	ft_stack_min(t_stack *stack);
t_nix	ft_stack_max(t_stack *stack);
t_nix	ft_bgst_lwr(int target, t_stack *stack);

//A to B cost
t_nix	ft_min_cost(t_stack *a, t_stack *b);
int		ft_find_optimal_moves(t_stack *a, t_stack *b, int i, t_nix target);

//Move from A to B
void	ft_move_to_b(t_stack *a, t_stack *b);

//Moves
int		ft_rot_ind(int curr_ind, int offset, int size);

void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);

void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);

void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);

void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);

#endif
