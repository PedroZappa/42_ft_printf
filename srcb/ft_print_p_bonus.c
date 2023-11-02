/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:35:25 by passunca          #+#    #+#             */
/*   Updated: 2023/11/02 17:12:34 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int ft_print_ptr(unsigned long int n);
void ft_print_address(unsigned long int n);
int ft_ptrlen(unsigned long int n);

int	ft_print_p(unsigned long int n, t_format p)
{
	int count;

	count = 0;
	if (n == 0)
		p.width -= ft_strlen("(nil)") - 1;
	else 
		p.width -= 2;
	if (p.minus)
		count += ft_print_ptr(n);
	count += ft_pad_width(p.width, ft_ptrlen(n), 0);
	if (!p.minus)
		count += ft_print_ptr(n);
}

int ft_print_ptr(unsigned long int n)
{
	int count;

	count = 0;
	if (n == 0)
	{
		count += ft_print_str("(nil)");
		return (count);
	}
	count += ft_print_str("0x");
	ft_print_address(n);
	count += ft_ptrlen(n);
	return (count);
}

void ft_print_address(unsigned long int n)
{
	if (n >= 16)
	{
		ft_print_address(n / 16);
		ft_print_address(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd((n + '0'), 1);
		else if (n >= 10)
			ft_putchar_fd(((n - 10) + 'a'), 1);
	}
}

int ft_ptrlen(unsigned long int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n = n / 16;
		++len;
	}
	return (len);
}
