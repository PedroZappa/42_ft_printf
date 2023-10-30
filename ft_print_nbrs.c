/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:30 by passunca          #+#    #+#             */
/*   Updated: 2023/10/30 15:07:16 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

// static char	ft_sign(t_format prsd);

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
		u_nbr = va_arg(ap, unsigned int);
		ft_uputnbr(u_nbr, &len);
	}
	return ((int)len);
}

// static char	ft_sign(t_format prsd)
// {
// 	if (prsd.plus)
// 		return ('+');
// 	return ('-');
// }
