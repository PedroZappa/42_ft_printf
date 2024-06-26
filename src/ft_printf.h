/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:34:01 by passunca          #+#    #+#             */
/*   Updated: 2024/02/11 19:19:52 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../inc/libft/libft/libft.h"
# include <stdarg.h>

/* Constants */
# define SPECIFIERS "cspdiuxX%"
# define HEX_LOWER	"0123456789abcdef"
# define HEX_UPPER	"0123456789ABCDEF"

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

/* Function Prototypes */
/* Formats and prints input 'format' data */
int			ft_printf(const char *format, ...);
/* Initializes a t_format struct with all members set to 0 */
t_format	ft_newformat(void);
/* Parsing */
int			ft_parse(const char *format, va_list ap);
/* Printing */
int			ft_print_specifier(t_format parsed, va_list ap);
int			ft_print_char(t_format parsed, va_list ap);
int			ft_print_str(t_format parsed, va_list ap);
int			ft_print_diu(t_format parsed, va_list ap);
int			ft_print_ptr(t_format parsed, va_list ap);
int			ft_print_hex(t_format parsed, va_list ap);
int			ft_print_x(t_format parsed, va_list ap);

#endif
