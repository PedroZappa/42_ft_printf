/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:10:55 by zedr0             #+#    #+#             */
/*   Updated: 2023/10/22 17:21:54 by zedr0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_nbr(t_format prsd, char *nbr, int len, int neg);
static char plus(t_format prsd);

int	ft_print_diu(t_format prsd, va_list ap)
{
	char	*nbr;
	int	n;
	int	numlen;
	int	len;
	int	neg;
	
	numlen = 0;
	n = va_arg(ap, int);
	neg = ((n < 0) && (n != INT_MIN) && (prsd.specifier != 'u'));
	if (neg)
		prsd.plus  = 0;
	if (n < 0 && prsd.specifier != 'u')
		n *= -1;
	if (n < 0 && prsd.specifier == 'u')
		nbr = ft_uitoa((unsigned)n);
	else 
		nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	if (*nbr == '0' && !prsd.precision && prsd.dot)
		len = 0;
	if (prsd.precision < len || !prsd.dot)
		prsd.precision = len;
	numlen += ft_print_nbr(prsd, nbr, len, neg);
	free(nbr);
	return (numlen);
}

static int	ft_print_nbr(t_format prsd, char *nbr, int len, int neg)
{
	int count;
	int n;

	count = 0;
	n = (prsd.width - prsd.precision - neg - prsd.plus);
	prsd.width -= (prsd.space && !neg && !prsd.plus && prsd.width);
	if (neg || prsd.plus)
		count += ft_putnchar_fd(plus(prsd), 1, 
			(prsd.zero && (prsd.dot && !prsd.neg_precision)));
	else if (prsd.space)
		count += ft_putnchar_fd(' ', 1, (prsd.zero && !prsd.dot));
	if (!prsd.minus && (prsd.width > prsd.precision) 
		&& (!prsd.dot || prsd.neg_precision) && prsd.zero)
		count += ft_putnchar_fd('0', 1, n);
	else if (!prsd.minus && (prsd.width > prsd.precision))
		count += ft_putnchar_fd(' ', 1, n);
	if (neg || prsd.plus)
		count += ft_putnchar_fd(plus(prsd), 1, 
			(!prsd.zero || (prsd.dot && !prsd.neg_precision)));
	else if (prsd.space)
		count += ft_putnchar_fd(' ', 1, (!prsd.zero || prsd.dot));
	count += ft_putnchar_fd('0', 1, (prsd.precision - len));
	count += write(1, nbr, len); 
	return (count);
}

static char plus(t_format prsd)
{
	if (prsd.plus)
		return ('+');
	return ('-');
}
