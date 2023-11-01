/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diu_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:30 by passunca          #+#    #+#             */
/*   Updated: 2023/10/31 22:21:28 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"

int		ft_putunbr(unsigned int n);
char	*ft_uitoa(unsigned int nb);

int	ft_print_diu(t_format prsd, va_list ap)
{
	char			*nbr;
	unsigned int	un;
	int				len;

	if (prsd.specifier == 'd' || prsd.specifier == 'i')
	{
		nbr = ft_itoa(va_arg(ap, int));
		len = ft_putstrn_fd(nbr, 1, ft_strlen(nbr));
		free(nbr);
	}
	else
	{
		un = va_arg(ap, unsigned int);
		len = ft_putunbr(un);
	}
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