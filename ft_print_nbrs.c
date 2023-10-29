/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:30 by passunca          #+#    #+#             */
/*   Updated: 2023/10/29 21:14:26 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

// static char	ft_sign(t_format prsd);

int	ft_print_diu(t_format prsd, va_list ap)
{
	char	*nbr;
	int		len;

	if (prsd.specifier == 'd' || prsd.specifier == 'i')
		nbr = ft_itoa(va_arg(ap, int));
	else
		nbr = ft_itoa(va_arg(ap, int));
	len = ft_putstrn_fd(nbr, 1, ft_strlen(nbr));
	free(nbr);
	return (len);
}

// static char	ft_sign(t_format prsd)
// {
// 	if (prsd.plus)
// 		return ('+');
// 	return ('-');
// }
