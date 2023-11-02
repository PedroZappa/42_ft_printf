/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:40:21 by passunca          #+#    #+#             */
/*   Updated: 2023/11/02 16:52:26 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stddef.h>

int ft_print_uint(char *nbrstr, t_format p);
int ft_print_unsigned(char *nbrstr, t_format p);

int	ft_print_u(unsigned n, t_format p)
{
	int		count;
	char	*nbrstr;

	count = 0;
	if (!p.precision && n == 0)
	{
		count += ft_pad_width(p.width, 0, 0);
		return (count);
	}
	nbrstr = ft_uitoa(n);
	if (!nbrstr)
		return (0);
	count += ft_print_uint(nbrstr, p);
	free(nbrstr);
	return (count);
}

int ft_print_uint(char *nbrstr, t_format p)
{
	int		count;

	count = 0;
	if (p.minus)
		count += ft_print_unsigned(nbrstr, p);
	if ((p.precision >= 0) && (size_t)p.precision < ft_strlen(nbrstr))
		p.precision = ft_strlen(nbrstr);
	if (p.precision >= 0)
	{
		p.width -= p.precision;
		count += ft_pad_width(p.width, 0, 0);
	}
	else
		count += ft_pad_width(p.width, ft_strlen(nbrstr), p.zero);
	if (!p.minus)
		count += ft_print_unsigned(nbrstr, p);
	return (count);
}

int ft_print_unsigned(char *nbrstr, t_format p)
{
	int count;

	count = 0;
	if (p.precision >= 0)
		count += ft_pad_width((p.precision - 1), (ft_strlen(nbrstr) - 1), 1);
	count += ft_print_str(nbrstr);
	return (count);
}
