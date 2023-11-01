/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diu_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:30 by passunca          #+#    #+#             */
/*   Updated: 2023/11/01 19:21:37 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"

int			ft_putunbr(unsigned int n);
static int	ft_putprefix(t_format p);

int	ft_print_di(t_format prsd, va_list ap)
{
	char			*nbr;
	int				len;
	int				n;

	len = 0;
	(void)prsd;
	n = va_arg(ap, int);
	nbr = ft_itoa(n);
	if (prsd.plus || prsd.space)
		len += ft_putprefix(prsd);
	len = ft_putstrn_fd(nbr, 1, ft_strlen(nbr));
	free(nbr);
	return (len);
}

int	ft_print_u(t_format prsd, va_list ap)
{
	unsigned int	un;
	int				len;

	(void)prsd;
	un = va_arg(ap, unsigned int);
	len = ft_putunbr(un);
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	char	*str;
	int		len;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		str = ft_uitoa((unsigned int)n);
		len = ft_putstr_fd(str, 1);
		free(str);
	}
	return (len);
}

static int	ft_putprefix(t_format p)
{
	if (p.specifier == ' ')
		return (write(1, " ", 1));
	else if (p.specifier == '0')
		return (write(1, "0", 1));
	else if (p.plus)
		return (write(1, "+", 1));
	else
		return (write(1, "-", 1));
}
