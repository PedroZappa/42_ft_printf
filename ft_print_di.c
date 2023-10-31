/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:30 by passunca          #+#    #+#             */
/*   Updated: 2023/10/31 08:07:23 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_di(t_format prsd, va_list ap)
{
	char			*nbr;
	int				len;

	(void) prsd;
	nbr = ft_itoa(va_arg(ap, int));
	len = ft_putstrn_fd(nbr, 1, ft_strlen(nbr));
	free(nbr);
	return (len);
}
