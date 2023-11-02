/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:28:29 by passunca          #+#    #+#             */
/*   Updated: 2023/11/02 13:35:56 by passunca         ###   ########.fr       */
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
