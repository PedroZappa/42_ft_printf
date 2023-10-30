/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:48:32 by passunca          #+#    #+#             */
/*   Updated: 2023/10/30 19:54:00 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(t_format prsd, va_list ap)
{
	unsigned int	nbr;
	int				len;
	
	(void) prsd;
	nbr = va_arg(ap, unsigned int);
	len = ft_putnbr(nbr);
	return (len);
}
