/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:56:53 by zedr0             #+#    #+#             */
/*   Updated: 2023/10/19 15:10:02 by zedr0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	ft_parse_width(const char *format, va_list ap, t_format formatted);

int	ft_parse(const char *format, va_list ap)
{
	t_format	formatted;

	formatted = ft_parse_width(format, ap, ft_newformat());
	formatted = ft_parse_bonus(format, formatted);
	while (*format != '.' && !ft_strchr(SPECIFIERS, *format))
		++format;
	if (*format == '.' && !formatted.specifier)
	{
		formatted.dot = 1;
		formatted = ft_parse_precision(++format, ap, formatted);
		while (!ft_strchr(SPECIFIERS, *format))
			++format;
	}
	if (formatted.width < 0)
	{
		formatted.minus = 1;
		formatted.width *= -1;
	}
	formatted.specifier = *format;
	formatted.neg_precision = formatted.precision < 0;
	return (ft_print_format(formatted, ap));
}

t_format	ft_parse_width(const char *format, va_list ap, t_format formatted)
{
	int		width_set;
	
	width_set = 0;
	while (*format == '.' && !ft_strchr(SPECIFIERS, *format))
	{
		if (*format == '-')
			formatted.minus = 1;
		if (*format == '0' && !ft_isdigit(*(format + 1)))
			formatted.zero = 1;
		else if (ft_isdigit(*format) && !width_set)
		{
			formatted.width = ft_atoi(format);
			width_set = 1;
		}
		++format;
	}
	return (formatted);
}
