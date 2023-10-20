#define MUNIT_ENABLE_ASSERT_ALIASES	// Define alias without 'munit_' prefix
#include "munit/munit.h"
#include <stdlib.h>					// EXIT_SUCCESS & EXIT_FAILURE
#include "../ft_printf.h"


/* ft_printf() Assertions */
static MunitResult ft_printf_char_tests(const MunitParameter params[], void* user_data)
{
	(void) params;
	(void) user_data;

	assert_char('z', ==, 'z');

	return MUNIT_OK;
}

/* Array of tests for ft_printf() Test Suite */
static MunitTest ft_printf_tests[] = {
	{ 
		(char*) "/printf",		// Name
		ft_printf_char_tests,	// Tests 
		NULL,					// Setup function
		NULL,					// Teardown function
		MUNIT_TEST_OPTION_NONE, // Options
		NULL					// Parameters
	}
	/* Add More tests here */
};

/* ft_printf() Test Suite */
static const MunitSuite ft_printf_suite = {
	(char*) "",					// Str to prepend to all test names
	ft_printf_tests,			// Test cases
	NULL,						// No sub-suites
	1,							// Iteration number
	MUNIT_SUITE_OPTION_NONE		// Options
};


int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
	/* Call munit_suite_main to parse arguments and run suite */
	return munit_suite_main(&ft_printf_suite, (void*) "µnit", argc, argv);
}
