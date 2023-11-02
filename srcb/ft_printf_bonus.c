/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:18 by passunca          #+#    #+#             */
/*   Updated: 2023/11/02 19:44:03 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		fmt_len;
	char	*str;

	if (!format || *format == '\0')
		return (0);
	str = ft_strdup(format);
	if (!str || *str == '\0')
		return (0);
	fmt_len = 0;
	va_start(ap, format);
	fmt_len = ft_parse_bonus(str, ap);
	va_end(ap);
	free(str);
	return (fmt_len);
}
