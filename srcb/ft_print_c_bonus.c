/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:00 by passunca          #+#    #+#             */
/*   Updated: 2023/11/01 20:21:08 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"

static int	ft_putwidth(t_format p, int *len);

int	ft_print_c(t_format p, va_list ap)
{
	int		len;

	len = 0;
	if (p.specifier == 'c')
		p.c = va_arg(ap, int);
	else
		p.c = '%';
	if (!p.minus && p.c != '%')
		p.width -= ft_putwidth(p, &len);
	len += ft_putchar_fd(p.c, 1);
	if (p.minus && p.c != '%')
		ft_putwidth(p, &len);
	return (len);
}

static int	ft_putwidth(t_format p, int *len)
{
	int	i;

	i = 0;
	if (p.width > p.precision)
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
