/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:54:04 by zedr0             #+#    #+#             */
/*   Updated: 2023/10/19 14:04:46 by zedr0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	char	*format_start;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format_start = (char *)format;
			if (*(++format))
				len += ft_parse(format, ap);
			while (*format && !ft_strchr(SPECIFIERS, *format))
				++format;
			if (*format)
				len += ft_parse(format_start, ap);
		}
		else
			len += ft_putchar_fd(*format, 1);
		if (*format)
			++format;
	}
	va_end(ap);
	return (len);
}

t_format	ft_newformat(void)
{
	t_format	new_format;

	new_format.specifier = 0;
	new_format.minus = 0;
	new_format.plus = 0;
	new_format.width = 0;
	new_format.precision = 0;
	new_format.neg_precision = 0;
	new_format.zero = 0;
	new_format.dot = 0;
	new_format.space = 0;
	new_format.sharp = 0;
	return (new_format);
}
