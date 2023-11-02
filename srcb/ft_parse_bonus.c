/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:24:58 by passunca          #+#    #+#             */
/*   Updated: 2023/11/02 13:04:53 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static t_format	ft_parse_width(const char *format, t_format parsed);
static t_format	ft_parse_prec(const char *format, t_format parsed);
static t_format	ft_parse_bonus(const char *format, t_format parsed);
// static void		ft_print_format(t_format p);

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
		parsed.precision = 0;
		parsed.zero = 0;
		parsed = ft_parse_prec(format++, parsed);
		while (!ft_strchr(SPECIFIERS, *format))
			++format;
	}
	parsed.specifier = *format;
	return (ft_print_specifier(format, parsed, ap));
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
	if (parsed.plus)
		parsed.space = 0;
	if (parsed.minus)
		parsed.zero = 0;
	return (parsed);
}

// static void	ft_print_format(t_format p)
// {
// 	printf("\nparsed from format :\n");
// 	printf("char\t*c\t: %c\n", p.c);
// 	printf("char\t*str\t: %s\n", p.str);
// 	printf("char\tspecifier\t: %c\n", p.specifier);
// 	printf("char\tflag\t: %c\n", p.flag);
// 	printf("int\tminus\t: %d\n", p.minus);
// 	printf("int\tplus\t: %d\n", p.plus);
// 	printf("int\twidth\t: %d\n", p.width);
// 	printf("int\tprecision\t: %d\n", p.precision);
// 	printf("int\tzero\t: %d\n", p.zero);
// 	printf("int\tdot\t: %d\n", p.dot);
// 	printf("int\tspace\t: %d\n", p.space);
// 	printf("int\tsharp\t: %d\n", p.sharp);
// }
