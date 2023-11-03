/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:18 by passunca          #+#    #+#             */
/*   Updated: 2023/11/03 12:52:52 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	p;

	if (!format || *format == '\0')
		return (0);
	p = ft_newformat();
	p.len = -1;
	p.str = ft_strdup(format);
	if (!p.str || *p.str == '\0')
		return (0);
	va_start(ap, format);
	ft_parse_bonus(ap, &p);
	va_end(ap);
	free(p.str);
	return (p.len);
}
