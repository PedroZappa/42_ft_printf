/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:24:58 by passunca          #+#    #+#             */
/*   Updated: 2023/11/02 20:18:52 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdarg.h>

static int	ft_print_arg(t_format p, char type, va_list ap);
static int	ft_parse_flags(t_format *p, int i, const char *str);

int	ft_parse_bonus(char *str, va_list ap)
{
	int			i;
	// int			speclen;
	int			len;
	t_format	p;

	i = 0;
	len = 0;
	while (str[i])
	{
		p = ft_newformat();
		if (str[i] == '%' && str[i + 1] == '\0')
		{
			// speclen = ft_parse_flags(&p, i, str);
			// if (p.specifier > 0)
			// 	i = speclen;
			i = ft_parse_flags(&p, i, str);
			if ((str[i] != '\0') && (p.specifier > 0) && ft_isflagtype(str[i]))
				len += ft_print_arg(p, str[i], ap);
			else if (str[i] != '\0')
				len += ft_putchar_fd(str[i], 1);
		}
		else
			len += ft_putchar_fd(str[i], 1);
		++i;
	}
	return (len);
}

static int	ft_parse_flags(t_format *p, int i, const char *str)
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
			*p = ft_flag_width(*p);
		else if (str[i] == '.')
			i = ft_flag_prec(i, p);
		else if (ft_isdigit(str[i]))
			*p = ft_flag_digit(*p);
		if (ft_isflagtype(str[i]))
		{
			p->specifier = str[i];
			break ;
		}
	}
	return (i);
}

static int	ft_print_arg(t_format p, char type, va_list ap)
{
	int count;

	count = 0;
	if (type == '%')
		count += ft_print_c('%', p);
	else if (type == 'c')
		count += ft_print_c(va_arg(ap, int), p);
	else if (type == 's')
		count += ft_print_s(va_arg(ap, const char *), p);
	else if (type == 'd' || type == 'i')
		count += ft_print_di(va_arg(ap, int), p);
	else if (type == 'u')
		count += ft_print_u(va_arg(ap, unsigned int), p);
	else if (type == 'x')
		count += ft_print_x(va_arg(ap, unsigned int), 0, p);
	else if (type == 'X')
		count += ft_print_x(va_arg(ap, unsigned int), 1, p);
	else if (type == 'p')
		count += ft_print_p((unsigned long int)va_arg(ap, void *), p);
	return (count);
}
