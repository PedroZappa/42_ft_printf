/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:12:41 by zedr0             #+#    #+#             */
/*   Updated: 2023/10/20 19:48:02 by zedr0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define MUNIT_ENABLE_ASSERT_ALIASES	// Define alias without 'munit_' prefix
#include "munit/munit.h"
#include <stdlib.h>					// EXIT_SUCCESS & EXIT_FAILURE
#include "../ft_printf.h"
#include "../libft/libft.h"

/* ft_printf() Test Assertions */
void test_ft_printf(int ft, int og)
{
	assert_int(ft, ==, og);
}

static MunitResult ft_printf_edge(const MunitParameter params[], void* user_data)
{
	(void) params;
	(void) user_data;

	test_ft_printf(ft_printf("\x07\x03\a\v\b\f\r\n"), printf("\x01\x02\a\v\b\f\r\n"));

	return MUNIT_OK;
}
static MunitResult ft_printf_percent(const MunitParameter params[], void* user_data)
{
	(void) params;
	(void) user_data;

	test_ft_printf(ft_printf("%%"), printf("%%"));
	test_ft_printf(ft_printf(" %%"), printf(" %%"));
	test_ft_printf(ft_printf("%%c"), printf("%%c"));
	test_ft_printf(ft_printf("%%%%%%"), printf("%%%%%%"));
	test_ft_printf(ft_printf("%%%c", 'z'), printf("%%%c", 'z'));

	return MUNIT_OK;
}
static MunitResult ft_printf_c(const MunitParameter params[], void* user_data)
{
	(void) params;
	(void) user_data;

	test_ft_printf(ft_printf("%c", 'z'), printf("%c", 'z'));
	test_ft_printf(ft_printf(" %c", 'z'), printf(" %c", 'z'));
	test_ft_printf(ft_printf("%c ", 'z'), printf("%c ", 'z'));
	test_ft_printf(ft_printf("%c%c%c", '\t', 'Z'), printf("%c%c%c", 'z', '\t', 'Z'));
	test_ft_printf(ft_printf("%cc%cc%c", '\t', 'Z'), printf("%cc%cc%c", 'z', '\t', 'Z'));
	test_ft_printf(ft_printf("%c%c%c", 'B', 'Z'), printf("%cs%cs%c", 'z', 'B', 'Z'));

	return MUNIT_OK;
}

/* Array of tests for ft_printf() Test Suite */
static MunitTest ft_printf_chars_tests[] = {
	{ 
		(char*) "/ft_printf edge tests",
		ft_printf_edge,			// Test			
		NULL,					// Setup function
		NULL,					// Teardown function
		MUNIT_TEST_OPTION_NONE, // Options
		NULL					// Parameters
	},
	{ 
		(char*) "/ft_printf % tests",
		ft_printf_percent,		
		NULL,			
		NULL,				
		MUNIT_TEST_OPTION_NONE,
		NULL				
	},
	{ 
		(char*) "/ft_printf %c tests",
		ft_printf_c,
		NULL,	
		NULL,
		MUNIT_TEST_OPTION_NONE,
		NULL
	},
	/* Add More tests here */

	/* Mark the end of the array with an entry where the test
	* function is NULL */
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

/* ft_printf() Test Suite */
static const MunitSuite ft_printf_suite = {
	(char*) "",					// Str to prepend to all test names
	ft_printf_chars_tests,		// Test cases
	NULL,						// No sub-suites
	1,							// Iteration number
	MUNIT_SUITE_OPTION_NONE		// Options
};


int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
	/* Call munit_suite_main to parse arguments and run suite */
	return munit_suite_main(&ft_printf_suite, (void*) "µnit", argc, argv);
}
