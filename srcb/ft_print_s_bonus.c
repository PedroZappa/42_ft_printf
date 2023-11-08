/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:00 by passunca          #+#    #+#             */
/*   Updated: 2023/11/08 20:54:23 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_putstr(const char *str, t_format p);
static int	ft_print_s_precision(const char *str, int precision);

int	ft_print_s(const char *str, t_format p)
{
	int		count;

	count = 0;
	if ((str == NULL) && (p.precision >= 0) && (p.precision < 6))
		str = "";
	if (!str)
		str = "(null)";
	if ((p.precision >= 0) && ((size_t)p.precision > ft_strlen(str)))
		p.precision = ft_strlen(str);
	if (p.minus)
		count += ft_putstr(str, p);
	if (p.precision >= 0)
		count += ft_pad_width(p.width, p.precision, 0);
	else
		count += ft_pad_width(p.width, ft_strlen(str), 0);
	if (!p.minus)
		count += ft_putstr(str, p);
	return (count);
}

static int	ft_putstr(const char *str, t_format p)
{
	int		count;

	count = 0;
	if (p.precision >= 0)
	{
		count += ft_pad_width(p.precision, ft_strlen(str), 0);
		count += ft_print_s_precision(str, p.precision);
	}
	else
		count += ft_print_s_precision(str, ft_strlen(str));
	return (count);
}

static int	ft_print_s_precision(const char *str, int precision)
{
	int	count;

	count = 0;
	while (str[count] && count < precision)
		ft_putchar_fd(str[count++], 1);
	return (count);
}

int	ft_print_str(const char *str)
{
	int	len;

	if (str == NULL)
		return (ft_putstrn_fd("(null)", 1, 6));
	len = ft_strlen(str);
	return (ft_putstrn_fd((char *)str, 1, len));
}
