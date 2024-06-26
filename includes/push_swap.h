/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:00:53 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/18 18:45:47 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../sources/libft/libft.h"

typedef struct s_stack
{
	int			*arr;
	int			size;
	int			start;
	int			end;
	int			cmnd_count;
	t_printf	cmnd;
}	t_stack;

typedef struct s_nix
{
	int		n;
	int		ix;
}	t_nix;

typedef struct s_cst
{
	t_nix	lwst_cst;
	t_nix	min;
	t_nix	max;
	int		i;
	int		val;
	int		cost;
	int		tmp;
}	t_cst;

//Init stacks
void	ft_init_both_stacks(t_stack *a, t_stack *b, int ac, char **av);
void	ft_init_stack_a(int count, t_stack *a);
void	ft_init_stack_b(int count, t_stack *b);

//Validate args
int		ft_validate_av(int ac, char **av, t_stack *a);
void	ft_check_dups(t_stack *a, t_stack *b);

//Top level operations
void	ft_push_to_a(t_stack *a, t_stack *b);
void	ft_push_to_b(t_stack *a, t_stack *b);
void	ft_sort_three(t_stack *a, t_stack *b);
void	ft_min_to_top(t_stack *a, t_stack *b);

//Stack min max bgst_lwr lwst_bgr sorted
t_nix	ft_stack_min(t_stack *stack);
t_nix	ft_stack_max(t_stack *stack);
t_nix	ft_bgst_lwr(int target, t_stack *stack);
t_nix	ft_lwst_bgr(int target, t_stack *stack);
int		ft_circ_sorted(t_stack *stack);

//Cost of pushing to B
t_nix	ft_min_cost(t_stack *a, t_stack *b);
int		ft_find_optimal_moves(t_stack *a, t_stack *b, int i, t_nix target);

//Move cases
void	ft_rrr_case(t_stack *a, t_stack *b, t_nix lwst_cst, t_nix target);
void	ft_rr_case(t_stack *a, t_stack *b, t_nix lwst_cst, t_nix target);
void	ft_rra_rb_case(t_stack *a, t_stack *b, t_nix lwst_cst, t_nix target);
void	ft_ra_rrb_case(t_stack *a, t_stack *b, t_nix lwst_cst, t_nix target);

//Perform moves
void	ft_n_single_moves(int n, t_stack *a, t_stack *b,
			void (*f)(t_stack *a, t_stack *b));
void	ft_n_double_moves(int n, t_stack *a, t_stack *b,
			void (*f)(t_stack *a, t_stack *b));

//Moves
int		ft_rot_ind(int curr_ind, int offset, int size);
void	ft_sa(t_stack *a, t_stack *b);
void	ft_sb(t_stack *a, t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
void	ft_ra(t_stack *a, t_stack *b);
void	ft_rb(t_stack *a, t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rra(t_stack *a, t_stack *b);
void	ft_rrb(t_stack *a, t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);

//Free and close
void	ft_free(t_stack *a, t_stack *b);
void	ft_exit(void);

//Swap atoi
int		ft_swap_atoi(const char *str);

//Min max
int		ft_min(int a, int b);
int		ft_max(int a, int b);

//Handle commands
void	ft_add_cmnd(t_stack *a, t_stack *b, char *str);
void	ft_print_cmnd(t_stack *a);

#endif
