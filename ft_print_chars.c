/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:00 by passunca          #+#    #+#             */
/*   Updated: 2023/10/31 09:23:11 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

// static int ft_wominus(t_format prsd, char *str, int len);
// static int ft_wminus(t_format prsd, char *str, int len);

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

	(void) prsd;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len);
}

// static int ft_wminus(t_format prsd, char *str, int len)
// {
// 	if (prsd.width == 0)
// 	{
// 		len += ft_putstrn_fd(str, 1, len);
// 		return (len);
// 	}
// 	while (prsd.precision > 0 && *str)
// 	{
// 		len += ft_putnchar_fd(*str++, 1, 1);
// 		prsd.precision--;
// 	}
// 	while (prsd.width > prsd.precision)
// 	{
// 		len += ft_putnchar_fd(' ', 1, 1);
// 		prsd.width--;
// 	}
// 	return (len);
// }
//
// static int ft_wominus(t_format prsd, char *str, int len)
// {
// 	if (prsd.width == 0)
// 	{
// 		len += ft_putstrn_fd(str, 1, len);
// 		return (len);
// 	}
// 	while (prsd.precision > 0 && *str)
// 	{
// 		len += ft_putnchar_fd(*str++, 1, 1);
// 		prsd.width--;
// 		prsd.precision--;
// 	}
// 	while (prsd.width > 0)
// 	{
// 		len += ft_putnchar_fd(' ', 1, 1);
// 		prsd.width--;
// 	}
// 	return (len);
// }
