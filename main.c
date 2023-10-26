/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:34:14 by zedr0             #+#    #+#             */
/*   Updated: 2023/10/26 16:01:36 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#define SEP "~~~~~~~~~~~~~~~~~~~~\n"

void test_c(void);
void test_s(void);

int main(int argc, char *argv[])
{
	(void) argv;
	(void) argc;

	test_c();
	test_s();



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

void test_c(void)
{
	ft_putstr_fd(SEP, 1);
	printf("Test %c\n", 'z');
	ft_printf("Test %c\n", 'z');
	ft_putstr_fd(SEP, 1);
}

void test_s(void)
{
	ft_putstr_fd(SEP, 1);
	printf("TESTING %%s\n");

}

