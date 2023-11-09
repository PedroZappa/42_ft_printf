/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:30 by passunca          #+#    #+#             */
/*   Updated: 2023/11/09 08:09:21 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"

int	ft_print_integer(char *numstr, int n, t_format p);
int	ft_print_sign_precision(int n, t_format *p);
int	ft_print_i(char *nbrstr, int n, t_format p);

int	ft_print_di(int n, t_format *p)
{
	char		*numstr;
	long		nbr;
	int			count;

	nbr = (long)n;
	count = 0;
	if (nbr < 0)
	{
		if (nbr == -2147483648)
			return (ft_putstr_fd("-2147483648", 1));
		nbr = -nbr;
		if (!p->zero)
			--p->width;
	}
	if (p->precision == 0 && n == 0)
	{
		count += ft_pad_width(p->width, 0, 0);
		return (count);
	}
	numstr = ft_itoa(nbr);
	if (!numstr)
		return (0);
	count += ft_print_integer(numstr, n, *p);
	free(numstr);
	return (count);
}

int	ft_print_integer(char *numstr, int n, t_format p)
{
	int		count;

	count = 0;
	if (p.zero)
		count += ft_print_sign_precision(n, &p);
	if (p.minus)
		count += ft_print_i(numstr, n, p);
	if ((p.precision >= 0) && ((size_t)p.precision < ft_strlen(numstr)))
		p.precision = ft_strlen(numstr);
	if (p.precision >= 0)
	{
		p.width -= p.precision;
		if ((n < 0) && !p.minus)
			--p.width;
		count += ft_pad_width(p.width, 0, 0);
	}
	else
		count += ft_pad_width((p.width - p.plus - p.space),
				ft_strlen(numstr), p.zero);
	if (!p.minus)
		count += ft_print_i(numstr, n, p);
	return (count);
}

int	ft_print_sign_precision(int n, t_format *p)
{
	int	count;

	count = 0;
	if ((n < 0) && p->precision == -1)
	{
		count += ft_putchar_fd('-', 1);
		--p->width;
	}
	else if (p->plus == 1)
		count += ft_putchar_fd('+', 1);
	else if (p->space == 1)
	{
		count += ft_putchar_fd(' ', 1);
		--p->width;
	}
	return (count);
}

int	ft_print_i(char *nbrstr, int n, t_format p)
{
	int	count;
	
	count = 0;
	if (n < 0)
	{
		if (!p.zero || p.precision >= 0)
			count += ft_putchar_fd('-', 1);
	}
	else if (p.plus && !p.zero)
		count += ft_putchar_fd('+', 1);
	else if (p.space && !p.zero)
		count += ft_putchar_fd(' ', 1);
	if (p.precision >= 0)
		count += ft_pad_width((p.precision - 1), (ft_strlen(nbrstr) - 1), 1);
	count += ft_print_str(nbrstr);
	return (count);
}
