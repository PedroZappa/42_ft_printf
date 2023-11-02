/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:00 by passunca          #+#    #+#             */
/*   Updated: 2023/11/02 15:38:17 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"

// static int	ft_putwidth(t_format p, int *count);

int	ft_print_c(char c, t_format p)
{
	int		count;

	count = 0;
	if (p.minus)
		count += ft_putchar_fd(c, 1);
	count += ft_pad_width(p.width, 1, p.zero);
	if (!p.minus)
		count += ft_putchar_fd(c, 1);
	return (count);
}

// static int	ft_putwidth(t_format p, int *count)
// {
// 	int	i;
//
// 	i = 0;
// 	if (p.width > p.precision)
// 	{
// 		while (p.width > 1)
// 		{
// 			count += ft_putchar_fd(' ', 1);
// 			--p.width;
// 			++i;
// 		}
// 	}
// 	return (i);
// }
