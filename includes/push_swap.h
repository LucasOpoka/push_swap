/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:00:53 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/10 14:20:38 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../sources/libft/libft.h"

typedef struct s_node
{
	int				n;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

#endif
