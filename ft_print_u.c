/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:48:32 by passunca          #+#    #+#             */
/*   Updated: 2023/10/30 20:55:45 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_putunbr(unsigned int n);
char	*ft_uitoa(unsigned int nb);

int	ft_print_u(t_format prsd, va_list ap)
{
	unsigned int	nbr;
	int				len;
	
	(void) prsd;
	nbr = va_arg(ap, unsigned int);
	len = ft_putunbr(nbr);
	return (len);
}

int ft_putunbr(unsigned int n)
{
	char	*str;
	int		len;
	
	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		str = ft_uitoa((unsigned int)n);
		len = ft_putstr_fd(str, 1);
		free(str);
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_unumlen(n, 10);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
