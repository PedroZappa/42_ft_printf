/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:28:29 by passunca          #+#    #+#             */
/*   Updated: 2023/11/02 15:35:50 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_isflag(int c)
{
	return (ft_isdigit(c) || ft_isspecif(c) || ft_isflag(c));
}

int	ft_isspecif(int c)
{
	if (ft_strchr(SPECIFIERS, c))
		return (1);
	return (0);
}

int ft_isflagtype(int c)
{
	if (ft_strchr(FLAGS, c) || c == '.')
		return (1);
	return(0);
}

int	ft_pad_width(int total_width, int size, int zero)
{
	int	count;

	count = 0;
	while (total_width - size > 0)
	{
		if (zero)
			count += ft_putchar_fd('0', 1);
		else
			count += ft_putchar_fd(' ', 1);
		--total_width;
	}
	return (count);
}
