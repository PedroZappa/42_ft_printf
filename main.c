/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:01:44 by passunca          #+#    #+#             */
/*   Updated: 2023/11/01 16:50:21 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcb/ft_printf_bonus.h"
#include "libft/libft.h"

#define SEP "~~~~~~~~~~~~~~~~~~~~\n"

static void ft_test(int n, char *frmt, char *specif);

void test_c(void);
void test_s(void);
void test_di(void);
void test_u(void);

int main(int argc, char *argv[])
{
	(void) argv;
	(void) argc;

	test_c();
	// test_s();
	// test_di();
	// test_u();

	return (0);
}

void test_c(void)
{
	ft_putstr_fd(SEP, 1);
	printf("TESTING %%c\n");
	ft_putstr_fd(SEP, 1);

	ft_putstr_fd(SEP, 1);
	printf("'%10c'\n", 'z');
	ft_printf("'%#10.7c'\n", 'z');

	// ft_putstr_fd(SEP, 1);
	// printf("'%-3c'\n", 'z');
	// ft_printf("'%-3c'\n", 'z');

	// ft_putstr_fd(SEP, 1);
	// printf("%-05%\n");
	// ft_printf("%-05%\n");
}

void test_s(void)
{
	ft_putstr_fd(SEP, 1);
	ft_printf("TESTING %%s\n");

	ft_putstr_fd(SEP, 1);
	ft_test(1, " %s ", "-");
	ft_putstr_fd(SEP, 1);
	ft_test(2, " %s ", "Z");
}

void test_di(void)
{
	ft_putstr_fd(SEP, 1);
	ft_printf("TESTING %%d\n");

	int len;
	ft_putstr_fd(SEP, 1);
	len = printf("'%7d'", -10);
	printf("\nlen: %d\n", len);
	len = ft_printf("'%7d'", -10);
	printf("\nlen: %d\n", len);
}

void test_u(void)
{
	ft_putstr_fd(SEP, 1);
	ft_printf("TESTING %%u\n");

	int len;
	ft_putstr_fd(SEP, 1);
	len = printf(" %u ", 42);
	printf("\nlen: %d", len);
	printf("\n");
	len = ft_printf(" %u ", 42);
	printf("\nlen: %d", len);
	printf("\n");
	
	ft_putstr_fd(SEP, 1);
	len = printf(" %u ", -7);
	printf("\nlen: %d", len);
	printf("\n");
	len = ft_printf(" %u ", -7);
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
