/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:44 by passunca          #+#    #+#             */
/*   Updated: 2023/10/31 20:19:59 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static int	ft_puthex(unsigned long nb, t_format p);
static int	ft_hexlen(unsigned long nb);
static char	*ft_hexseq(t_format p);

int	ft_print_x(t_format p, va_list ap)
{
	unsigned int	nb;
	int				len;

	(void)p;
	nb = va_arg(ap, unsigned int);
	len = ft_hexlen(nb);
	ft_puthex(nb, p);
	return (len);
}

static int	ft_puthex(unsigned long nb, t_format p)
{
	char	*hexseq;
	int		count;

	count = 0;
	hexseq = ft_hexseq(p);
	if (nb < 16)
		ft_putchar(hexseq[nb]);
	if (nb >= 16)
	{
		ft_puthex((nb / 16), p);
		count += ft_putchar(hexseq[nb % 16]);
	}
	return (count);
}

static int	ft_hexlen(unsigned long nb)
{
	int	len;

	len = 0;
	if (!nb)
		return (1);
	while (nb)
	{
		nb /= 16;
		++len;
	}
	return (len);
}

static char	*ft_hexseq(t_format p)
{
	if (p.specifier == 'x')
		return ("0123456789abcdef");
	return ("0123456789ABCDEF");
}
