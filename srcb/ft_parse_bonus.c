/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:24:58 by passunca          #+#    #+#             */
/*   Updated: 2023/11/08 20:24:41 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void		ft_print_arg(t_format *p, char type, va_list ap);
static int		ft_parse_flag(const char *str, t_format *p, int i);
void			ft_parse_width(const char *str, t_format *p, int i);
void			ft_parse_prec(const char *str, t_format *p, int i);

int	ft_parse_bonus(const char *str, va_list ap, t_format *p)
{
	int		i;
	int		speclen;

	i = -1;
	while (str[++i] != '\0')
	{
		ft_resetformat(p);
		if (str[i] == '%')
		{
			speclen = ft_parse_flag(str, p, i);
			if (p->specifier)
				i = speclen;
			if (str[i] && (p->specifier > 0) && ft_isspecif(str[i]))
				ft_print_arg(p, str[i], ap);
			else if (str[i] != '\0')
				p->len += ft_putchar_fd(str[i], 1);
		}
		else
			p->len += ft_putchar_fd(str[i], 1);
	}
	return (p->len);
}

static int	ft_parse_flag(const char *str, t_format *p, int i)
{
	while (str[++i] && ft_isflag(str[i]))
	{
		if (str[i] == '-')
			*p = ft_flag_minus(*p);
		else if (str[i] == '#')
			p->sharp = 1;
		else if (str[i] == ' ')
			p->space = 1;
		else if (str[i] == '+')
			p->plus = 1;
		else if (str[i] == '0' && p->minus == 0 && p->width == 0)
			p->zero = 1;
		// if (ft_isdigit(str[i]) && !p->width && str[i - 1] != '.')
		if (ft_isdigit(str[i]) && !p->width && !p->dot)
			ft_parse_width(str, p, i);
		if (str[i] == '.')
			ft_parse_prec(str, p, i);
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
		p->len += ft_print_c('%', p);
	else if (type == 'c')
		p->len += ft_print_c(va_arg(ap, int), p);
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

void	ft_parse_width(const char *str, t_format *p, int i)
{
	while (str[i] != '.' && !ft_isspecif(str[i]))
	{
		if (ft_isdigit(str[i]) && !p->width)
			p->width = ft_atoi(str + i);
		++i;
	}
}

void	ft_parse_prec(const char *str, t_format *p, int i)
{
	p->dot = 1;
	if (str[i + 1] == '0')
		p->zero = 1;
	p->precision = ft_atoi(&str[i + 1]);
	if (p->dot && (p->precision < 0))
		p->precision = 0;
}
