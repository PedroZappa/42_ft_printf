/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:18 by passunca          #+#    #+#             */
/*   Updated: 2023/11/03 17:58:22 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_print_format(t_format p);

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
	ft_print_format(p);
	ft_parse_bonus(ap, &p);
	ft_print_format(p);
	va_end(ap);
	free(p.str);
	return (p.len);
}

static void	ft_print_format(t_format p)
{
	printf("\nparsed from format :\n");	
	printf("char\tc\t: %c\n", p.c);
	printf("char\t*str\t: %s\n", p.str);
	printf("int\tlen\t: %d\n", p.len);
	printf("char\tspcfr\t: %d\n", p.specifier);
	printf("int\tminus\t: %d\n", p.minus);
	printf("int\tplus\t: %d\n", p.plus);
	printf("int\twidth\t: %d\n", p.width);
	printf("int\tprec\t: %d\n", p.precision);
	printf("int\tzero\t: %d\n", p.zero);
	printf("int\tdot\t: %d\n", p.dot);
	printf("int\tspace\t: %d\n", p.space);
	printf("int\tsharp\t: %d\n", p.sharp);
}
