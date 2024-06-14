/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:57:21 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/14 12:09:17 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_rrr_case(t_stack *a, t_stack *b, t_nix lwst_cst, t_nix target)
{
	int	move_a;
	int	move_b;
	int	common;

	move_a = a->end - lwst_cst.ix;
	move_b = b->end - target.ix;
	common = MIN(move_a, move_b);
	move_a -= common;
	move_b -= common;
	n_double_moves(common, a, b, &ft_rrr);
	n_single_moves(move_a, a, &ft_rra);
	n_single_moves(move_b, b, &ft_rrb);
	ft_pb(a, b);
}

void	ft_rr_case(t_stack *a, t_stack *b, t_nix lwst_cst, t_nix target)
{
	int	move_a;
	int	move_b;
	int	common;

	move_a = lwst_cst.ix;
	move_b = target.ix;
	common = MIN(move_a, move_b);
	move_a -= common;
	move_b -= common;
	n_double_moves(common, a, b, &ft_rr);
	n_single_moves(move_a, a, &ft_ra);
	n_single_moves(move_b, b, &ft_rb);
	ft_pb(a, b);
}

void	ft_rra_rb_case(t_stack *a, t_stack *b, t_nix lwst_cst, t_nix target)
{
	int	move_a;
	int	move_b;

	move_a = a->end - lwst_cst.ix;
	move_b = target.ix;
	n_single_moves(move_a, a, &ft_rra);
	n_single_moves(move_b, b, &ft_rb);
	ft_pb(a, b);
}

void	ft_ra_rrb_case(t_stack *a, t_stack *b, t_nix lwst_cst, t_nix target)
{
	int	move_a;
	int	move_b;

	move_a = lwst_cst.ix;
	move_b = b->end - target.ix;
	n_single_moves(move_a, a, &ft_ra);
	n_single_moves(move_b, b, &ft_rrb);
	ft_pb(a, b);
}
