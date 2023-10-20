/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:34:14 by zedr0             #+#    #+#             */
/*   Updated: 2023/10/20 21:11:25 by zedr0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#define SEP "~~~~~~~~~~~~~~~~~~~~\n"

int main(int argc, char *argv[])
{
	(void) argv;
	(void) argc;

	ft_putstr_fd(SEP, 1);
	printf("Test %c\n", 'z');
	ft_printf("Test %c\n", 'z');
	ft_putstr_fd(SEP, 1);

	char *str0 = "Zedr0";
	printf("Test %s\n", str0);
	ft_printf("Test %s\n", str0);
	ft_putstr_fd(SEP, 1);

	unsigned int nbr0 = 42;
	printf("Test %u\n", nbr0);
	ft_printf("Test %u\n", nbr0);
	ft_putstr_fd(SEP, 1);

	return (0);
}
