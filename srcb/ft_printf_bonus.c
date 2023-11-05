/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:18 by passunca          #+#    #+#             */
/*   Updated: 2023/11/05 18:22:25 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	// char		*str;
	// int			len;
	t_format	p;

	if (!format || *format == '\0')
		return (0);
	p = ft_newformat();
	// str = ft_strdup(format);
	// if (!str || *str == '\0')
	// 	return (0);
	va_start(ap, format);
	// ft_parse_bonus(str, ap, &p);
	ft_parse_bonus(format, ap, &p);
	// len = ft_parse_bonus(str, ap);
	va_end(ap);
	// free(str);
	return (p.len);
	// return (len);
}

