/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:44 by passunca          #+#    #+#             */
/*   Updated: 2023/10/31 10:11:43 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

// p = parsed
// static char	*ft_sharp(t_format p);
static void	ft_puthex(long hex);
static int 	ft_hexlen(long nb);

int	ft_print_ptr(t_format p, va_list ap)
{
	long	nb;
	int		len;

	(void)p;
	nb = (unsigned long)va_arg(ap, void *);
	if (!nb)
		return (ft_putstrn_fd("(nil)", 1, 5));
	len = ft_hexlen(nb);
	ft_putstr_fd("0x", 1);
	ft_puthex(nb);
	return (len);
}

static void	ft_puthex(long nb)
{
	if (nb < 0)
		nb *= -1;
	if (nb < 16)
		ft_putchar(HEX_LOWER[nb]);
	if (nb >= 16)
	{
		ft_puthex(nb / 16);
		ft_puthex(nb % 16);
	}
}

static int 	ft_hexlen(long nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		nb /= 16;
		++len;
	}
	return (len + 2);
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
