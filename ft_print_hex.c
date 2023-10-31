/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:44 by passunca          #+#    #+#             */
/*   Updated: 2023/10/31 10:01:27 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

// p = parsed
// static char	*ft_sharp(t_format p);
static int	ft_puthex(long hex, int *len);

int	ft_print_ptr(t_format p, va_list ap)
{
	long	nb;
	int		len;

	(void)p;
	nb = (unsigned long)va_arg(ap, void *);
	len = ft_puthex(nb, &len);
	return (len);
}

static int	ft_puthex(long nb, int *len)
{
	if (nb < 0)
		nb *= -1;
	if (nb < 16)
		len += ft_putchar(HEX_LOWER[nb]);
	if (nb >= 16)
	{
		ft_puthex(nb / 16, len);
		ft_puthex(nb % 16, len);
	}
	return (*(len));
}

// int	ft_print_x(t_format p, va_list ap)
// {
//
// }
//

// static char	*ft_sharp(t_format p)
// {
// 	if (p.specifier == 'X')
// 		return ("0X");
// 	return ("0x");
// }
