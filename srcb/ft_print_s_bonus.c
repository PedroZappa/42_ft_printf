/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:00 by passunca          #+#    #+#             */
/*   Updated: 2023/11/02 11:31:04 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"

// static int	ft_putwidth(t_format p, int *len);
static void	ft_putwithminus(t_format p, int *len);
static void	ft_putwoutminus(t_format p, int *len);

int	ft_print_s(t_format p, va_list ap)
{
	int		len;

	p.str = va_arg(ap, char *);
	if (!p.str)
	{
		if (p.dot && (p.precision < 6))
			p.str = "";
		else
			p.str = "(null)";
	}
	len = ft_strlen(p.str);
	if ((p.precision > len) || !p.dot)
		p.precision = len;
	else if (!p.precision)
		return (0);
	// if (!p.minus)
	// 	p.width -= ft_putwidth(p, &len);
	// if (p.precision)
	// 	ft_putstrn_fd(p.str, 1, p.precision);
	// else
	// 	ft_putstrn_fd(p.str, 1, len);
	// len += p.precision;
	// if (p.minus && p.width)
	// ft_putwidth(p, &len);
	if (p.minus)
		ft_putwithminus(p, &len);
	else
		ft_putwoutminus(p, &len);
	return (len);
}

// static int	ft_putwidth(t_format p, int *len)
// {
// 	int strlen;
// 	int	i;
//
// 	i = 0;
// 	strlen = ft_strlen(p.str);
// 	if (p.precision < strlen)
// 		strlen = p.precision;
// 	if (p.width > p.precision)
// 	{
// 		while (p.width > strlen)
// 		{
// 			len += ft_putchar_fd(' ', 1);
// 			--p.width;
// 			++i;
// 		}
// 	}
// 	return (i);
// }

static void ft_putwithminus(t_format p, int *len)
{
	while ((p.precision > 0) && *p.str)
	{
		len += ft_putchar_fd(*p.str++, 1);
		--p.precision;
		--p.width;
	}
	while (p.width > 0)
	{
		len += ft_putchar_fd(' ', 1);
		--p.width;
	}
}

static void ft_putwoutminus(t_format p, int *len)
{
	while (p.width > p.precision)
	{
		len += ft_putchar_fd(' ', 1);
		--p.width;
	}
	while ((p.precision > 0) && *p.str)
	{
		len += ft_putchar_fd(*p.str++, 1);
		--p.precision;
	}
}
