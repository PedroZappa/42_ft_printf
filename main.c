/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:50:37 by passunca          #+#    #+#             */
/*   Updated: 2023/10/30 12:59:54 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#define SEP "~~~~~~~~~~~~~~~~~~~~\n"

static void ft_test(int n, char *frmt, char *specif);

void test_c(void);
void test_s(void);
void test_u(void);

int main(int argc, char *argv[])
{
	(void) argv;
	(void) argc;

	// test_c();
	// test_s();
	test_u();

	return (0);
}

void test_c(void)
{
	ft_putstr_fd(SEP, 1);
	printf("TESTING %%c\n");

	ft_putstr_fd(SEP, 1);
	printf("Test %c\n", 'z');
	ft_printf("Test %c\n", 'z');

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

void test_u(void)
{
	ft_putstr_fd(SEP, 1);
	printf("TESTING %%u\n");

	int len;
	ft_putstr_fd(SEP, 1);
	len = printf(" %u ", 42);
	printf("\nlen: %d", len);
	printf("\n");
	len = ft_printf(" %u ", 42);
	printf("\nlen: %d", len);
	printf("\n");

	ft_putstr_fd(SEP, 1);
	len = printf(" %u ", -1);
	printf("\nlen: %d", len);
	printf("\n");
	len = ft_printf(" %u ", -1);
	printf("\nlen: %d", len);
	printf("\n");

	ft_putstr_fd(SEP, 1);
	len = printf(" %u ", -99);
	printf("\nlen: %d", len);
	printf("\n");
	len = ft_printf(" %u ", -99);
	printf("\nlen: %d", len);
	printf("\n");
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
