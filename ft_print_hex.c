/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:32:05 by zedr0             #+#    #+#             */
/*   Updated: 2023/10/21 11:28:48 by zedr0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_recur_hex(t_format parsed, size_t n, size_t iter);
static char	*ft_sharp(t_format parsed);

int ft_print_x(t_format parsed, va_list ap)
{
	int				count;
	unsigned int	n;
	int				len;

	count = 0;
	n = va_arg(ap, unsigned int);
	len = ft_numlen(n, 16);
	if (!n && !parsed.precision && parsed.dot)
		len = 0;
	if ((parsed.precision < 0) || (parsed.precision < len) && !parsed.dot)
		parsed.precision = len;
	if (parsed.sharp && n)
		parsed.width -= 2;
	count += ft_putstrn_fd(ft_sharp(parsed), 1, (2 * (parsed.sharp && parsed.zero && n)));
	if (!parsed.minus && (parsed.width > parsed.precision) 
		&& ((!parsed.dot || parsed.neg_precision) && parsed.zero))
		count += ft_putnchar_fd('0', 1, (parsed.width - parsed.precision));
	else if (!parsed.minus && (parsed.width > parsed.precision))
		count += ft_putnchar_fd(' ', 1, (parsed.width - parsed.precision));
	count += ft_putstrn_fd(ft_sharp(parsed), 1, (2 * (parsed.sharp && !parsed.zero && n)));
	count += ft_putnchar_fd('0', 1, (parsed.precision - len));
	if (len)
		count += ft_recur_hex(parsed, n, n);
	if (parsed.minus && (parsed.width > parsed.precision))
		count += ft_putnchar_fd(' ', 1, (parsed.width - parsed.precision));
	return (count);
}

int ft_print_ptr(t_format parsed, va_list ap)
{
	int		count;
	size_t	n;
	int		len;

	count = 0;
	n = va_arg(ap, size_t);
	len = ft_numlen(n, 16);
	len *= !(!n && !parsed.precision && parsed.dot);
	if ((parsed.precision < len) || !parsed.dot)
		parsed.precision = len;
	count += write(1, "0x",(2 * parsed.zero));
	parsed.width -= 2;
	if (!parsed.minus && (parsed.width > parsed.precision) && !parsed.dot && parsed.zero)
		count += ft_putnchar_fd('0', 1, (parsed.width - parsed.precision));
	else if (!parsed.minus && (parsed.width > parsed.precision))
		count += ft_putnchar_fd('0', 1, (parsed.width - parsed.precision));
	count += write(1, "0x", (2 * !parsed.zero));
	count += ft_putnchar_fd('0', 1, ((parsed.precision - len) * (n != 0)));
	count += ft_putnchar_fd('0', 1, (parsed.precision * (parsed.dot && !n)));
	if (len)
		count += ft_recur_hex(parsed, n, n);
	if (parsed.minus && (parsed.width > parsed.precision))
		count += ft_putnchar_fd(' ', 1, (parsed.width - parsed.precision));
	return (count);
}

static int	ft_recur_hex(t_format parsed, size_t n, size_t iter)
{
	int count;
	int remainder;
	char character;

	count = 0;
	if ((n > 0) || (!iter && ((parsed.specifier != 'p') || !parsed.dot)))
	{
		remainder = n % 16;
		if (parsed.specifier != 'X')
			character = HEX_LOWER[remainder];
		else
			character = HEX_UPPER[remainder];
		n /= 16;
		iter = 1;
		count += ft_recur_hex(parsed, n, iter);
		count += ft_putchar_fd(character, 1);
	}
	return (count);
}

static char *ft_sharp(t_format parsed)
{
	if (parsed.specifier == 'X')
		return ("0X");
	return ("0x");
}
