/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:34:14 by zedr0             #+#    #+#             */
/*   Updated: 2023/10/20 19:12:08 by zedr0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#define SEP "~~~~~~~~~~~~~~~~~~~~"

int main(int argc, char *argv[])
{
	(void) argv;
	(void) argc;

	ft_putstr_fd(SEP, 1);
	printf("Test %c\n", 'z');
	ft_printf("Test %c\n", 'z');
	ft_putstr_fd(SEP, 1);

	// printf("");
	// ft_printf("");


	return (0);
}
