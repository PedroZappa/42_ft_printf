/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:38:09 by passunca          #+#    #+#             */
/*   Updated: 2023/11/05 20:31:49 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_format	ft_newformat(void)
{
	t_format	new_format;

	new_format.c = 0;
	new_format.len = 0;
	new_format.specifier = 0;
	new_format.flag = 0;
	new_format.minus = 0;
	new_format.plus = 0;
	new_format.width = 0;
	new_format.precision = -1;
	new_format.zero = 0;
	new_format.dot = 0;
	new_format.space = 0;
	new_format.sharp = 0;
	return (new_format);
}

t_format	ft_flag_left(t_format prsd)
{
	prsd.minus = 1;
	prsd.zero = 0;
	return (prsd);
}

t_format	ft_flag_width(t_format prsd)
{
	if (prsd.width < 0)
	{
		prsd.minus = 1;
		prsd.width *= -1;
	}
	return (prsd);
}

int	ft_flag_prec(const char *str, int pos, t_format *prsd)
{
	int	i;

	i = (pos + 1);
	while (ft_isdigit(str[i]))
	{
		prsd->precision = (prsd->precision * 10) + (str[i] - '0');
		++i;
	}
	return (i);
}
