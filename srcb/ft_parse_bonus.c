/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:24:58 by passunca          #+#    #+#             */
/*   Updated: 2023/11/05 18:47:01 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void		ft_print_arg(t_format *p, char type, va_list ap);
static int		ft_parse_flag(const char *str, t_format *p, int i);
static int		ft_parse_widthprec(const char *str, t_format *parsed, int i);
static void		ft_print_format(t_format p);

int	ft_parse_bonus(const char *str, va_list ap, t_format *p)
{
	int		i;
	int		speclen;
	// t_format	p;

	i = -1;
	while (str[++i])
	{
		// p = ft_newformat();
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			// i = ft_parse_flag(str, &p, i);
			// i = ft_parse_flag(str, p, i);
			speclen = ft_parse_flag(str, p, i);
			if (p->specifier)
				i = speclen;
			if ((str[i] != '\0') && (p->specifier > 0)
				&& ft_isspecif(str[i]))
				ft_print_arg(p, str[i], ap);
			else if (str[i] != '\0')
				p->len += ft_putchar_fd(str[i], 1);
		}
		else
			p->len += ft_putchar_fd(str[i], 1);
	}
	ft_print_format(*p);
	return (p->len);
}

static int	ft_parse_flag(const char *str, t_format *p, int i)
{
	while (str[++i] && ft_isflag(str[i]))
	{
		if (str[i] == '-')
			*p = ft_flag_left(*p);
		else if (str[i] == '#')
			p->sharp = 1;
		else if (str[i] == ' ')
			p->space = 1;
		else if (str[i] == '+')
			p->plus = 1;
		else if (str[i] == '0' && p->minus == 0 && p->width == 0)
			p->zero = 1;
		else if (ft_isdigit(str[i]))
			i += ft_parse_widthprec(str, p, i);
		else if (ft_isspecif(str[i]))
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

static int	ft_parse_widthprec(const char *str, t_format *p, int i)
{
	int		width_set;
	int		numlen;
	
	numlen = 0;
	width_set = 0;
	while (str[i] != '.' && !ft_strchr(SPECIFIERS, str[i]))
	{
		if (str[i] == '0' && !ft_isdigit(str[i + 1]))
			p->zero = 1;
		else if (ft_isdigit(str[i]) && !width_set)
		{
			p->width = ft_atoi(str + i);
			width_set = 1;
		}
		++i;
		++numlen;
	}
	if (str[i] == '.')
	{
		p->dot = 1;
		p->precision = ft_atoi(&str[i + 1]);
		numlen += ft_numlen(p->precision, 10);
	}
	return (numlen);
}

static void	ft_print_format(t_format p)
{
	printf("\nparsed from format :\n");	
	printf("char\tc\t: %c\n", p.c);
	printf("int\tlen\t: %d\n", p.len);
	printf("char\tspcfr\t: %d\n", p.specifier);
	printf("int\tminus\t: %d\n", p.minus);
	printf("int\tplus\t: %d\n", p.plus);
	printf("int\twidth\t: %d\n", p.width);
	printf("int\tprec\t: %d\n", p.precision);
	printf("int\tzero\t: %d\n", p.zero);
	printf("int\tdot\t: %d\n", p.dot);
	printf("int\tspace\t: %d\n", p.space);
	printf("int\tsharp\t: %d\n", p.sharp);
}
