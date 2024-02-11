/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:44 by passunca          #+#    #+#             */
/*   Updated: 2024/02/11 12:00:33 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_print_hexa(char *nbrstr, size_t n, int is_upper, t_format *p);
static int	ft_puthex(char *nbrstr, size_t n, int is_upper, t_format p);
static int	ft_putx_prefix(int is_upper);

int	ft_print_x(size_t n, int is_upper, t_format p)
{
	char	*nbrstr;
	int		count;

	count = 0;
	if (p.precision == 0 && n == 0)
	{
		count += ft_pad_width(p.width, 0, 0);
		return (count);
	}
	nbrstr = ft_xtoa(n, is_upper);
	if (!nbrstr)
		return (0);
	count += ft_print_hexa(nbrstr, n, is_upper, &p);
	free(nbrstr);
	return (count);
}

static int	ft_print_hexa(char *nbrstr, size_t n, int is_upper, t_format *p)
{
	int		count;

	count = 0;
	if (p->zero && p->sharp && n != 0)
	{
		count += ft_putx_prefix(is_upper);
		p->width -= 2;
	}
	if (p->minus)
		count += ft_puthex(nbrstr, n, is_upper, *p);
	if ((p->precision >= 0) && ((size_t)p->precision < ft_strlen(nbrstr)))
		p->precision = ft_strlen(nbrstr);
	if (p->precision >= 0)
	{
		p->width -= p->precision;
		count += ft_pad_width(p->width, 0, 0);
	}
	else
		count += ft_pad_width(p->width,
				(ft_strlen(nbrstr) + (p->sharp * 2)), p->zero);
	if (!p->minus)
		count += ft_puthex(nbrstr, n, is_upper, *p);
	return (count);
}

static int	ft_puthex(char *nbrstr, size_t n, int is_upper, t_format p)
{
	int	count;

	count = 0;
	if (!p.zero && p.sharp && (n != 0))
		count += ft_putx_prefix(is_upper);
	if (p.precision >= 0)
		count += ft_pad_width((p.precision - 1), (ft_strlen(nbrstr) - 1), 1);
	count += ft_print_str(nbrstr);
	return (count);
}

static int	ft_putx_prefix(int is_upper)
{
	if (is_upper)
		return (write(1, "0X", 2));
	return (write(1, "0x", 2));
}
