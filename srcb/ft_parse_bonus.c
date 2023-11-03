/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:24:58 by passunca          #+#    #+#             */
/*   Updated: 2023/11/03 10:29:55 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_print_arg(t_format p, char type, va_list ap);
static int	ft_parse_flags(t_format *p, int i, const char *str);

void	ft_parse_bonus(char *str, va_list ap, int *fmt_len, t_format *p)
{
	int			i;

	i = -1;
	while (str[++i])
	{
		if (!p->str)
			p->str = str;
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i = ft_parse_flags(p, i, str);
			if ((str[++i] != '\0') && (p->specifier > 0))
				fmt_len += ft_print_arg(*p, str[i], ap);
			else if (!str[i])
				fmt_len += ft_putchar_fd(str[i], 1);
		}
		else
			fmt_len += ft_putchar_fd(str[i], 1);
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
			*p = ft_flag_width(*p);
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

static int	ft_print_arg(t_format p, char type, va_list ap)
{
	int	count;

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
