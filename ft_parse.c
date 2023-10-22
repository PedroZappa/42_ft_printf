/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:56:53 by zedr0             #+#    #+#             */
/*   Updated: 2023/10/22 10:50:46 by zedr0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_format	ft_parse_width(const char *format, t_format fmtd);
static t_format	ft_parse_prec(const char *format, t_format fmtd);
static t_format	ft_parse_bonus(const char *format, t_format fmtd);

int	ft_parse(const char *format, va_list ap)
{
	t_format	fmtd;

	fmtd = ft_parse_width(format, ft_newformat());
	fmtd = ft_parse_bonus(format, fmtd);
	while (*format != '.' && !ft_strchr(SPECIFIERS, *format))
		++format;
	if (*format == '.' && !fmtd.specifier)
	{
		fmtd.dot = 1;
		fmtd = ft_parse_prec(format++, fmtd);
		while (!ft_strchr(SPECIFIERS, *format))
			++format;
	}
	if (fmtd.width < 0)
	{
		fmtd.minus = 1;
		fmtd.width *= -1;
	}
	fmtd.specifier = *format;
	fmtd.neg_precision = fmtd.precision < 0;
	return (ft_print_specifier(fmtd, ap));
}

static t_format	ft_parse_width(const char *format, t_format fmtd)
{
	int		width_set;

	width_set = 0;
	while (*format != '.' && !ft_strchr(SPECIFIERS, *format))
	{
		if (*format == '-')
			fmtd.minus = 1;
		if (*format == '0' && !ft_isdigit(*(format + 1)))
			fmtd.zero = 1;
		else if (ft_isdigit(*format) && !width_set)
		{
			fmtd.width = ft_atoi(format);
			width_set = 1;
		}
		++format;
	}
	return (fmtd);
}

static t_format	ft_parse_prec(const char *format, t_format fmtd)
{
	int		precision_set;

	precision_set = 0;
	while (!ft_strchr(SPECIFIERS, *format))
	{
		if (ft_isdigit(*format) && !precision_set)
		{
			fmtd.precision = ft_atoi(format);
			precision_set = 1;
		}
		++format;
	}
	return (fmtd);
}

static t_format	ft_parse_bonus(const char *format, t_format fmtd)
{
	while (*format != '.' && !ft_strchr(SPECIFIERS, *format))
	{
		if (*format == '#')
			fmtd.sharp = 1;
		if (*format == ' ')
			fmtd.space = 1;
		if (*format == '+')
			fmtd.plus = 1;
		++format;
	}
	return (fmtd);
}
