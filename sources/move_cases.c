/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:57:21 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/16 11:11:14 by lopoka           ###   ########.fr       */
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
	common = ft_min(move_a, move_b);
	move_a -= common;
	move_b -= common;
	ft_n_double_moves(common, a, b, &ft_rrr);
	ft_n_single_moves(move_a, a, b, &ft_rra);
	ft_n_single_moves(move_b, a, b, &ft_rrb);
	ft_pb(a, b);
}

void	ft_rr_case(t_stack *a, t_stack *b, t_nix lwst_cst, t_nix target)
{
	int	move_a;
	int	move_b;
	int	common;

	move_a = lwst_cst.ix;
	move_b = target.ix;
	common = ft_min(move_a, move_b);
	move_a -= common;
	move_b -= common;
	ft_n_double_moves(common, a, b, &ft_rr);
	ft_n_single_moves(move_a, a, b, &ft_ra);
	ft_n_single_moves(move_b, a, b, &ft_rb);
	ft_pb(a, b);
}

void	ft_rra_rb_case(t_stack *a, t_stack *b, t_nix lwst_cst, t_nix target)
{
	int	move_a;
	int	move_b;

	move_a = a->end - lwst_cst.ix;
	move_b = target.ix;
	ft_n_single_moves(move_a, a, b, &ft_rra);
	ft_n_single_moves(move_b, a, b, &ft_rb);
	ft_pb(a, b);
}

void	ft_ra_rrb_case(t_stack *a, t_stack *b, t_nix lwst_cst, t_nix target)
{
	int	move_a;
	int	move_b;

	move_a = lwst_cst.ix;
	move_b = b->end - target.ix;
	ft_n_single_moves(move_a, a, b, &ft_ra);
	ft_n_single_moves(move_b, a, b, &ft_rrb);
	ft_pb(a, b);
}
