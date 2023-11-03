/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:24:58 by passunca          #+#    #+#             */
/*   Updated: 2023/11/03 20:11:58 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void		ft_print_arg(t_format *p, char type, va_list ap);
static int		ft_parse_specif(t_format *p, int i);
static int		ft_parse_width(t_format *parsed, int i);
static int		ft_parse_prec(t_format *parsed, int i);

void	ft_parse_bonus(va_list ap, t_format *p)
{
	int			i;
	// int			spec_end;

	i = -1;
	while (p->str[++i])
	{
		if (p->str[i] == '%' && p->str[i + 1] != '\0')
		{
			// spec_end = ft_parse_specif(p, i, p->str);
			// if (p->specifier)
			// 	i = spec_end;
			i = ft_parse_specif(p, i);
			if ((p->str[++i] != '\0') && (p->specifier > 0))
				ft_print_arg(p, p->str[i], ap);
			else if (p->str[i])
				p->len += ft_putchar_fd(p->str[i], 1);
		}
		else
			p->len += ft_putchar_fd(p->str[i], 1);
	}
}

static int	ft_parse_specif(t_format *p, int i)
{
	while (p->str[++i] && ft_isflag(p->str[i]))
	{
		if (p->str[i] == '-')
			*p = ft_flag_left(*p);
		else if (p->str[i] == '#')
			p->sharp = 1;
		else if (p->str[i] == ' ')
			p->space = 1;
		else if (p->str[i] == '+')
			p->plus = 1;
		else if (p->str[i] == '0' && p->minus == 0 && p->width == 0)
			p->zero = 1;
		if (p->str[i] == '.')
			i += ft_parse_prec(p, i);
		if (ft_isdigit(p->str[i]))
			i += ft_parse_width(p, i);
		// else if (ft_isdigit(str[i]))
		// 	*p = ft_flag_digit(*p);
		else if (ft_isspecif(p->str[i]))
		{
			p->specifier = p->str[i];
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

static int	ft_parse_width(t_format *p, int i)
{
	int		width_set;

	width_set = 0;
	while (p->str[i] != '.' && !ft_strchr(SPECIFIERS, p->str[i]))
	{
		if (p->str[i] == '0' && !ft_isdigit(p->str[i + 1]))
			p->zero = 1;
		else if (ft_isdigit(p->str[i]) && !width_set)
		{
			p->width = ft_atoi(p->str + i);
			width_set = 1;
		}
		++i;
	}
	return (i);
}

static int	ft_parse_prec(t_format *p, int i)
{
	int	j;

	j = 0;
	p->dot = 1;
	if (p->str[i++] == '.')
	{
		while (ft_isdigit(p->str[i + j]))
			++j;
		p->precision = ft_atoi(&p->str[i]);
	}
	return (j);
}
