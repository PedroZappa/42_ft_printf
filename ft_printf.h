/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:37:28 by zedr0             #+#    #+#             */
/*   Updated: 2023/10/19 12:05:01 by zedr0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

/* Struct to track format parameters */
typedef struct s_format
{
	char	specifier;
	int		minus;
	int		plus;
	int		width;
	int		precision;
	int		neg_precision;
	int		zero;
	int		dot;
	int		space;
	int		sharp;
}	t_format;

#endif
