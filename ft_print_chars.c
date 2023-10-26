/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:00 by passunca          #+#    #+#             */
/*   Updated: 2023/10/26 19:33:05 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_format prsd, va_list ap)
{
	char	c;
	int		len;
	int		n;

	len = 0;
	n = (prsd.width - prsd.precision);
	if (prsd.specifier == 'c')
		c = va_arg(ap, int);
	else
		c = '%';
	prsd.precision = 0;
	if (!prsd.minus && prsd.zero)
		len += ft_putnchar_fd('0', 1, n);
	else if (!prsd.minus && (prsd.width > prsd.precision))
		len += ft_putnchar_fd(' ', 1, n);
	len += ft_putchar_fd(c, 1);
	if (prsd.minus && (n > 0))
		len += ft_putnchar_fd(' ', 1, n);
	return (len);
}

int	ft_print_str(t_format prsd, va_list ap)
{
	char	*str;
	int		len;
	int		n;

	len = 0;
	n = (prsd.width - prsd.precision);
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (prsd.dot || (prsd.precision > (int)ft_strlen(str))
		|| prsd.precision < 0)
		prsd.precision = (int)ft_strlen(str);
	if (!prsd.minus && (prsd.width > prsd.precision) && prsd.zero
		&& (!prsd.dot || prsd.neg_precision))
		len += ft_putnchar_fd('0', 1, n);
	else if (!prsd.minus && (n > 0))
		len += ft_putnchar_fd(' ', 1, n);
	len += ft_putstrn_fd(str, 1, prsd.precision);
	if (prsd.minus && (n > 0))
		len += ft_putnchar_fd(' ', 1, n);
	return (len);
}
