/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:18 by passunca          #+#    #+#             */
/*   Updated: 2023/11/01 17:02:16 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	char	*specifier_start;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			specifier_start = (char *)format;
			if (*(++format))
				len += ft_parse((char *)format, ap);
			while (*format && !ft_strchr(SPECIFIERS, *format))
				++format;
			if (!(*format))
				format = specifier_start;
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

	new_format.str = 0;
	new_format.specifier = 0;
	new_format.minus = 0;
	new_format.plus = 0;
	new_format.width = 0;
	new_format.precision = 0;
	new_format.zero = 0;
	new_format.dot = 0;
	new_format.space = 0;
	new_format.sharp = 0;
	return (new_format);
}
