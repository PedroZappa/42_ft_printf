/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:44 by passunca          #+#    #+#             */
/*   Updated: 2023/10/27 12:45:24 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

// p = parsed
static int	ft_recurhex(t_format p, size_t n, size_t i);
static char	*ft_sharp(t_format p);

int	ft_print_x(t_format p, va_list ap)
{
	int				count;
	unsigned int	n;
	int				len;

	count = 0;
	n = va_arg(ap, unsigned int);
	len = ft_numlen(n, 16);
	if (!n && p.dot && !p.precision)
		len = 0;
	if ((p.precision < 0) || (!p.dot && (p.precision < len)))
		p.precision = len;
	if (p.sharp && n)
		p.width -= 2;
	count += ft_putstrn_fd(ft_sharp(p), 1, (2 * p.sharp));
	if (!p.minus && (p.width > p.precision) 
		&& ((!p.dot || p.neg_precision) && p.zero))
		count += ft_putnchar_fd('0', 1, (p.width - p.precision));
	else if (!p.minus && (p.width > p.precision))
		count += ft_putnchar_fd(' ', 1, (p.width - p.precision));
	count += ft_putstrn_fd(ft_sharp(p), 1, (2 * p.sharp));
	count += ft_putnchar_fd('0', 1, (p.precision - len));
	if (len)
		count += ft_recurhex(p, n, n);
	if (p.minus && (p.width > p.precision))
		count += ft_putnchar_fd(' ', 1, (p.width - p.precision));
	return (count);
}

int	ft_print_ptr(t_format p, va_list ap)
{
	int		count;
	size_t	n;
	int		len;

	count = 0;
	n = va_arg(ap, size_t);
	len = ft_numlen(n, 16);
	len *= !(!n && !p.precision && p.dot);
	if (p.precision < len)
		p.precision = len;
	count += write(1, "0x", (2 * p.zero));
	p.width -= 2;
	if (!p.minus && (p.width > p.precision) && !p.dot && p.zero)
		count += ft_putnchar_fd('0', 1, (p.width - p.precision));
	else if (!p.minus && (p.width > p.precision))
		count += ft_putnchar_fd('0', 1, (p.width - p.precision));
	count += write(1, "0x", (2 * !p.zero));
	count += ft_putnchar_fd('0', 1, ((p.precision - len) * (n != 0)));
	count += ft_putnchar_fd('0', 1, (p.precision * (p.dot && !n)));
	if (len)
		count += ft_recurhex(p, n, n);
	if (p.minus && (p.width > p.precision))
		count += ft_putnchar_fd(' ', 1, (p.width - p.precision));
	return (count);
}

static int	ft_recurhex(t_format p, size_t n, size_t i)
{
	int		count;
	int		rem;
	char	c;

	count = 0;
	if ((n > 0) || (!i && ((p.specifier != 'p') || !p.dot)))
	{
		rem = n % 16;
		if (p.specifier != 'X')
			c = HEX_LOWER[rem];
		else
			c = HEX_UPPER[rem];
		n /= 16;
		i = 1;
		count += ft_recurhex(p, n, i);
		count += ft_putchar_fd(c, 1);
	}
	return (count);
}

static char	*ft_sharp(t_format p)
{
	if (p.specifier == 'X')
		return ("0X");
	return ("0x");
}
