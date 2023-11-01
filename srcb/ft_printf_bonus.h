/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:41:49 by passunca          #+#    #+#             */
/*   Updated: 2023/11/01 18:58:22 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../libft/libft.h"
# include <stdarg.h>

/* Constants */
# define SPECIFIERS "cspdiuxX%"
# define FLAGS		"0# +-"
# define HEX_LOWER	"0123456789abcdef"
# define HEX_UPPER	"0123456789ABCDEF"
# define INT_MIN	-2147483648

/* Struct to track format parameters */
typedef struct s_format
{
	char	*str;
	char	specifier;
	char	flag;
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
/* Check & Convert */
int			ft_check_flag_spec(char c, char *spec);
int			ft_num_specs(const char *format, t_format parsed, va_list ap);
int			ft_char_specs(const char *format, t_format parsed, va_list ap);
/* Printing */
int			ft_print_specifier(const char *format, t_format parsed, va_list ap);
int			ft_print_c(t_format parsed, va_list ap);
int			ft_print_s(t_format parsed, va_list ap);
int			ft_print_di(t_format parsed, va_list ap);
int			ft_print_u(t_format parsed, va_list ap);
int			ft_print_p(t_format parsed, va_list ap);
int			ft_print_hex(t_format parsed, va_list ap);
int			ft_print_x(t_format parsed, va_list ap);
int			ft_flags(t_format prsd, int nbr);

#endif
