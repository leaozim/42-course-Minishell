#include "../h_test.h"

void	check_arg_erro(void)
{
	int status;

	pid_t pid = fork();
	if (pid == 0)
	{
		check_arguments(2);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	TEST_ASSERT_EQUAL_INT(ARGUMENT_LIST_TOO_LONG, status);
}

void	test_check_program(void)
{
	RUN_TEST(check_arg_erro);
}
