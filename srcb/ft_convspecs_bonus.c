/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convspecs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:59:41 by passunca          #+#    #+#             */
/*   Updated: 2023/11/01 12:06:29 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int ft_check_spec(char c, char *spec);
int ft_num_specs(const char *format, t_format prsd, va_list ap);
int ft_other_specs(const char *format, t_format prsd, va_list ap);

int	ft_print_specifier(const char *format, t_format parsed, va_list ap)
{
	int	len;

	len = 0;
	if (ft_check_spec(*format, "diuxX+ #"))
		len += ft_num_specs(format, parsed, ap);
	else
		len += ft_other_specs(format, parsed, ap);
	if (ft_check_spec(*format, "+ #"))
		++format;
	return (len);
}

int ft_check_spec(char c, char *spec)
{
	int	i;
	
	i = 0;
	while (spec[i])
		if (c == spec[i++])
			return (1);
	return (0);
}

int ft_num_specs(const char *format, t_format prsd, va_list ap)
{
	int len;

	len = 0;
	if (ft_check_spec(*format, "# +"))
		++format;
	if (*format == 'd' || *format == 'i')
		len += ft_print_di(prsd, ap);
	else if (*format == 'x' || *format == 'X')
	{
		if (*format == 'u')
			len += ft_print_u(prsd, ap);
		else
			len += ft_print_x(prsd, ap);
	}
	return (len);
}

int ft_other_specs(const char *format, t_format prsd, va_list ap)
{
	int len;

	(void)format;
	len = 0;
	if (prsd.specifier == 'c' || prsd.specifier == '%')
		len += ft_print_c(prsd, ap);
	else if (prsd.specifier == 's')
		len += ft_print_s(prsd, ap);
	else if (prsd.specifier == 'p')
		len += ft_print_p(prsd, ap);
	return (len);
}
