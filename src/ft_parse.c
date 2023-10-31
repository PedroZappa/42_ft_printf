/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:24:58 by passunca          #+#    #+#             */
/*   Updated: 2023/10/31 20:20:54 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_format	ft_parse_width(const char *format, t_format parsed);
static t_format	ft_parse_prec(const char *format, t_format parsed);
static t_format	ft_parse_bonus(const char *format, t_format parsed);

int	ft_parse(const char *format, va_list ap)
{
	t_format	parsed;

	parsed = ft_parse_width(format, ft_newformat());
	parsed = ft_parse_bonus(format, parsed);
	while (*format != '.' && !ft_strchr(SPECIFIERS, *format))
		++format;
	if (*format == '.' && !parsed.specifier)
	{
		parsed.dot = 1;
		parsed = ft_parse_prec(format++, parsed);
		while (!ft_strchr(SPECIFIERS, *format))
			++format;
	}
	if (parsed.width < 0)
	{
		parsed.minus = 1;
		parsed.width *= -1;
	}
	parsed.specifier = *format;
	parsed.neg_precision = parsed.precision < 0;
	return (ft_print_specifier(parsed, ap));
}

static t_format	ft_parse_width(const char *format, t_format parsed)
{
	int		width_set;

	width_set = 0;
	while (*format != '.' && !ft_strchr(SPECIFIERS, *format))
	{
		if (*format == '-')
			parsed.minus = 1;
		if (*format == '0' && !ft_isdigit(*(format + 1)))
			parsed.zero = 1;
		else if (ft_isdigit(*format) && !width_set)
		{
			parsed.width = ft_atoi(format);
			width_set = 1;
		}
		++format;
	}
	return (parsed);
}

static t_format	ft_parse_prec(const char *format, t_format parsed)
{
	int		precision_set;

	precision_set = 0;
	while (!ft_strchr(SPECIFIERS, *format))
	{
		if (ft_isdigit(*format) && !precision_set)
		{
			parsed.precision = ft_atoi(format);
			precision_set = 1;
		}
		++format;
	}
	return (parsed);
}

static t_format	ft_parse_bonus(const char *format, t_format parsed)
{
	while (*format != '.' && !ft_strchr(SPECIFIERS, *format))
	{
		if (*format == '#')
			parsed.sharp = 1;
		if (*format == ' ')
			parsed.space = 1;
		if (*format == '+')
			parsed.plus = 1;
		++format;
	}
	return (parsed);
}
