/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lopoka@student.hive.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:40:36 by lucas             #+#    #+#             */
/*   Updated: 2024/06/03 13:50:53 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

double	ft_atof(const char *str)
{
	double	int_prt;
	double	flt_prt;
	char	*c;
	int		len;

	c = (char *)str;
	int_prt = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	flt_prt = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		flt_prt /= 10;
	if (int_prt >= 0)
		return (int_prt + flt_prt);
	else
		return (int_prt - flt_prt);
}
