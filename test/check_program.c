# include <test.h>

void    check_arg_erro(void)
{
    TEST_ASSERT_EQUAL(0, check_program(2));
}

void    test_check_program(void)
{
    RUN_TEST(check_arg_erro);
}
