/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:30 by passunca          #+#    #+#             */
/*   Updated: 2023/10/30 16:01:22 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_diu(t_format prsd, va_list ap)
{
	unsigned int	u_nbr;
	int				len;
	int				n;

	n = 0;
	len = 0;
	if (prsd.specifier == 'd' || prsd.specifier == 'i')
	{
		n = va_arg(ap, int);
		len += ft_putnbr(n);
	}
	else
	{
		u_nbr = va_arg(ap, size_t);
		len += ft_uputnbr(u_nbr);
	}
	return ((int)len);
}
