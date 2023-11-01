/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:00 by passunca          #+#    #+#             */
/*   Updated: 2023/11/01 09:49:29 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"

int ft_putwidth(t_format p, int *len);

int	ft_print_char(t_format p, va_list ap)
{
	char	c;
	int		len;

	len = 0;
	if (p.specifier == 'c')
		c = va_arg(ap, int);
	else
		c = '%';
	if (!p.minus)
		p.width -= ft_putwidth(p, &len);
	len += ft_putchar_fd(c, 1);
	if (p.minus)
		ft_putwidth(p, &len);
	return (len);
}

int ft_putwidth(t_format p, int *len)
{
	int i;

	i = 0;
	if (p.width > 1)
	{
		while (p.width > 1)
		{
			len += ft_putchar_fd(' ', 1);
			--p.width;
			++i;
		}
	}
	return (i);
}
