/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:41:49 by passunca          #+#    #+#             */
/*   Updated: 2023/11/08 13:50:34 by passunca         ###   ########.fr       */
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
	int		len;
	char	specifier;
	char	flag;
	int		minus;
	int		plus;
	int		width;
	int		precision;
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
void		ft_resetformat(t_format *prsd);
/* Parsing */
int			ft_parse(char *str, va_list ap);
// int			ft_parse_bonus(const char *str, va_list ap);
int			ft_parse_bonus(const char *str, va_list ap, t_format *p);
/* Check & Convert */
int			ft_isflag(int c);
int			ft_isspecif(int c);
int			ft_isflag(int c);
int			ft_isflagtype(int c);
t_format	ft_flag_left(t_format prsd);
t_format	ft_flag_width(t_format prsd);
int			ft_flag_prec(const char *str, int pos, t_format *prsd);
int			ft_pad_width(int total_width, int size, int zero);
char		*ft_xtoa(unsigned long int nb, int isupper);

int			ft_check_flag_spec(char c, char *spec);
int			ft_num_specs(const char *format, t_format prsd, va_list ap);
int			ft_char_specs(const char *format, t_format prsd, va_list ap);
/* Printing */
int			ft_print_specifier(const char *format, t_format prsd, va_list ap);
int			ft_print_c(char c, t_format *prsd);
int			ft_print_s(const char *str, t_format prsd);
int			ft_print_str(const char *str);
int			ft_print_di(int n, t_format prsd);
int			ft_print_u(unsigned n, t_format prsd);
int			ft_print_p(unsigned long int n, t_format prsd);
int			ft_print_hex(t_format prsd, va_list ap);
int			ft_print_x(size_t n, int isupper, t_format p);
int			ft_flags(t_format prsd, int nbr);

#endif
