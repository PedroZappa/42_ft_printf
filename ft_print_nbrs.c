/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:30 by passunca          #+#    #+#             */
/*   Updated: 2023/10/30 13:06:55 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

// static char	ft_sign(t_format prsd);

int	ft_print_diu(t_format prsd, va_list ap)
{
	char			*nbr;
	unsigned int	i_nbr;
	unsigned int	u_nbr;
	int				len;
	int				n;

	n = 0;
	nbr = NULL;
	len = 0;
	if (prsd.specifier == 'd' || prsd.specifier == 'i')
	{
		i_nbr = va_arg(ap, int);
		len = ft_numlen(i_nbr, 10);
		nbr = ft_itoa(i_nbr);
	}
	else
	{
		u_nbr = va_arg(ap, unsigned int);
		len = ft_numlen(u_nbr, 10);
		ft_uputnbr(u_nbr, &len);
	}
	if (nbr != NULL)
		free(nbr);
	return ((int)len);
}

// static char	ft_sign(t_format prsd)
// {
// 	if (prsd.plus)
// 		return ('+');
// 	return ('-');
// }
