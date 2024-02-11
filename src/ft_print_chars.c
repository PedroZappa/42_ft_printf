/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:00 by passunca          #+#    #+#             */
/*   Updated: 2024/02/11 11:58:33 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_format p, va_list ap)
{
	char	c;
	int		len;

	len = 0;
	if (p.specifier == 'c')
		c = va_arg(ap, int);
	else
		c = '%';
	len += ft_putchar_fd(c, 1);
	return (len);
}

int	ft_print_str(t_format prsd, va_list ap)
{
	char	*str;
	int		len;

	(void) prsd;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len);
}
