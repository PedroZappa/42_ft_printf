/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:54:04 by zedr0             #+#    #+#             */
/*   Updated: 2023/10/19 13:55:34 by zedr0            ###   ########.fr       */
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
