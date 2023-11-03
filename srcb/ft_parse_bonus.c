/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:24:58 by passunca          #+#    #+#             */
/*   Updated: 2023/11/03 13:07:51 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void		ft_print_arg(t_format *p, char type, va_list ap);
static int		ft_parse_flags(t_format *p, int i, const char *str);
static int		ft_parse_width(t_format parsed);

void	ft_parse_bonus(va_list ap, t_format *p)
{
	int			i;

	i = -1;
	while (p->str[++i])
	{
		if (p->str[i] == '%' && p->str[i + 1] != '\0')
		{
			i = ft_parse_flags(p, i, p->str);
			if ((p->str[++i] != '\0') && (p->specifier > 0))
				ft_print_arg(p, p->str[i], ap);
			else if (!p->str[i])
				p->len += ft_putchar_fd(p->str[i], 1);
		}
		else
			p->len += ft_putchar_fd(p->str[i], 1);
	}
}

static int	ft_parse_flags(t_format *p, int i, const char *str)
{
	while (str[i] && ft_isflag(str[i]))
	{
		if (str[i] == '-')
			*p = ft_flag_left(*p);
		if (str[i] == '#')
			p->sharp = 1;
		if (str[i] == ' ')
			p->space = 1;
		if (str[i] == '+')
			p->plus = 1;
		if (str[i] == '0' && p->minus == 0 && p->width == 0)
			p->zero = 1;
		if (ft_isdigit(str[i]))
			p->width = ft_parse_width(*p);
		if (str[i] == '.')
			i = ft_flag_prec(i, p);
		if (ft_isdigit(str[i]))
			*p = ft_flag_digit(*p);
		if (ft_isspecif(str[i]))
		{
			p->specifier = str[i];
			break ;
		}
	}
	return (i);
}

static void	ft_print_arg(t_format *p, char type, va_list ap)
{
	if (type == '%')
		p->len += ft_print_c('%', *p);
	else if (type == 'c')
		p->len += ft_print_c(va_arg(ap, int), *p);
	else if (type == 's')
		p->len += ft_print_s(va_arg(ap, const char *), *p);
	else if (type == 'd' || type == 'i')
		p->len += ft_print_di(va_arg(ap, int), *p);
	else if (type == 'u')
		p->len += ft_print_u(va_arg(ap, unsigned int), *p);
	else if (type == 'x')
		p->len += ft_print_x(va_arg(ap, unsigned int), 0, *p);
	else if (type == 'X')
		p->len += ft_print_x(va_arg(ap, unsigned int), 1, *p);
	else if (type == 'p')
		p->len += ft_print_p((unsigned long int)va_arg(ap, void *), *p);
}

static int	ft_parse_width(t_format p)
{
	int		width_set;

	width_set = 0;
	while (*p.str != '.' && !ft_strchr(SPECIFIERS, *p.str))
	{
		if (*p.str == '-')
			p.minus = 1;
		if (*p.str == '0' && !ft_isdigit(*(p.str + 1)))
			p.zero = 1;
		else if (ft_isdigit(*p.str) && !width_set)
		{
			p.width = ft_atoi(p.str);
			width_set = 1;
		}
		++p.str;
	}
	return (*p.str);
}
//
// static t_format	ft_parse_prec(const char *format, t_format parsed)
// {
// 	int		precision_set;
//
// 	precision_set = 0;
// 	while (!ft_strchr(SPECIFIERS, *format))
// 	{
// 		if (ft_isdigit(*format) && !precision_set)
// 		{
// 			parsed.precision = ft_atoi(format);
// 			precision_set = 1;
// 		}
// 		++format;
// 	}
// 	return (parsed);
// }
