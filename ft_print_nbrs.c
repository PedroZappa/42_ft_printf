/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:10:55 by zedr0             #+#    #+#             */
/*   Updated: 2023/10/21 16:21:57 by zedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_nbr(t_format parsed, char *nbr, int len, int neg);
static char plus(t_format parsed);

int	ft_print_diu(t_format parsed, va_list ap)
{
	char	*nbr;
	int	n;
	int	numlen;
	int	len;
	int	neg;
	
	numlen = 0;
	n = va_arg(ap, int);
	neg = ((n < 0) && (n != INT_MIN) && (parsed.specifier != 'u'));
	if (neg)
		parsed.plus  = 0;
	if (n < 0 && parsed.specifier != 'u')
		n *= -1;
	if (n < 0 && parsed.specifier == 'u')
		nbr = ft_uitoa((unsigned)n);
	else 
		nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	if (*nbr == '0' && !parsed.precision && parsed.dot)
		len = 0;
	if (parsed.precision < len || !parsed.dot)
		parsed.precision = len;
	numlen += ft_print_nbr(parsed, nbr, len, neg);
	free(nbr);
	return (numlen);
}

static int	ft_print_nbr(t_format parsed, char *nbr, int len, int neg)
{
	int count;
	int n;

	count = 0;
	n = (parsed.width - parsed.precision - neg - parsed.plus);
	parsed.width -= (parsed.space && !neg && !parsed.plus && parsed.width);
	if (neg || parsed.plus)
		count += ft_putnchar_fd(plus(parsed), 1, 
			(parsed.zero && (parsed.dot && !parsed.neg_precision)));
	else if (parsed.space)
		count += ft_putnchar_fd(' ', 1, (parsed.zero && !parsed.dot));
	if (!parsed.minus && (parsed.width > parsed.precision) 
		&& (!parsed.dot || parsed.neg_precision) && parsed.zero)
		count += ft_putnchar_fd('0', 1, n);
	else if (!parsed.minus && (parsed.width > parsed.precision))
		count += ft_putnchar_fd(' ', 1, n);
	if (neg || parsed.plus)
		count += ft_putnchar_fd(plus(parsed), 1, 
			(!parsed.zero || (parsed.dot && !parsed.neg_precision)));
	else if (parsed.space)
		count += ft_putnchar_fd(' ', 1, (!parsed.zero || parsed.dot));
	count += ft_putnchar_fd('0', 1, (parsed.precision - len));
	count += write(1, nbr, len); 
	return (count);
}

static char plus(t_format parsed)
{
	if (parsed.plus)
		return ('+');
	return ('-');
}
