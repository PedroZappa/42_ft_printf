	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:34:14 by zedr0             #+#    #+#             */
/*   Updated: 2023/10/27 11:17:35 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#define SEP "~~~~~~~~~~~~~~~~~~~~\n"

static void ft_test(int n, char *frmt, char *specif);

void test_c(void);
void test_s(void);

int main(int argc, char *argv[])
{
	(void) argv;
	(void) argc;

	test_c();
	test_s();



	unsigned int nbr0 = 42;
	printf("Test %u\n", nbr0);
	ft_printf("Test %u\n", nbr0);
	ft_putstr_fd(SEP, 1);

	return (0);
}

void test_c(void)
{
	ft_putstr_fd(SEP, 1);
	printf("TESTING %%c\n");

	ft_putstr_fd(SEP, 1);
	printf("Test %c\n", 'z');
	ft_printf("Test %c\n", 'z');
}

void test_s(void)
{
	ft_putstr_fd(SEP, 1);
	printf("TESTING %%s\n");

	ft_putstr_fd(SEP, 1);
	ft_test(1, " %s ", "-");
	ft_putstr_fd(SEP, 1);
	ft_test(2, " %s ", "Z");
}

static void ft_test(int n, char *frmt, char *specif)
{
	printf("Test%d:\n", n);
	printf(frmt, specif);
	printf("\n");
	ft_printf(frmt, specif);
	printf("\n");
	ft_putstr_fd(SEP, 1);
		
}

	// TEST(1, print("%s", ""));
	// TEST(2, print(" %s", ""));
	// TEST(3, print("%s ", ""));
	// TEST(4, print(" %s ", ""));
	// TEST(5, print(" %s ", "-"));
	// TEST(6, print(" %s %s ", "", "-"));
	// TEST(7, print(" %s %s ", " - ", ""));
	// TEST(8, print(" %s %s %s %s %s", " - ", "", "4", "", s2));
	// TEST(9, print(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));
	// TEST(10, print(" NULL %s NULL ", NULL));
