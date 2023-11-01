/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:00 by passunca          #+#    #+#             */
/*   Updated: 2023/11/01 17:04:45 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"

static int	ft_putwidth(t_format p, int *len);

int	ft_print_s(t_format p, va_list ap)
{
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if ((p.precision > len) || !p.dot)
		p.precision = len;
	if (!p.minus)
		p.width -= ft_putwidth(p, &len);
	ft_putstr_fd(str, 1);
	if (p.minus)
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
