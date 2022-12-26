# include "../h_test.h"

void    test_builtin_export()
{
    int	value;

	//fazer o teste com o valor atual da lista encadeada
	//teste integrado

	value = builtin_export("OLA=");
	TEST_ASSERT_EQUAL_INT(0, value);

	value = builtin_export("OLA====PESSOAL");
	TEST_ASSERT_EQUAL_INT(0, value);

	value = builtin_export("OLA");
	TEST_ASSERT_EQUAL_INT(0, value);

	// value = builtin_export("\"OLA\"");
	// TEST_ASSERT_EQUAL_INT(0, value);

	value = builtin_export("OLA=PESSOAL");
	TEST_ASSERT_EQUAL_INT(0, value);

	value = builtin_export("OLA%");
	TEST_ASSERT_EQUAL_INT(1, value);

	value = builtin_export("OLA=%PESSOAL");
	TEST_ASSERT_EQUAL_INT(0, value);

	value = builtin_export("%=PESSOAL");
	TEST_ASSERT_EQUAL_INT(1, value);

	// value = builtin_export("\"%\"=PESSOAL");
	// TEST_ASSERT_EQUAL_INT(1, value);

	// value = builtin_export("\"%=PESSOAL\"");
	// TEST_ASSERT_EQUAL_INT(1, value);

	value = builtin_export("2=PESSOAL");
	TEST_ASSERT_EQUAL_INT(1, value);

	value = builtin_export("%A=PESSOAL");
	TEST_ASSERT_EQUAL_INT(1, value);

	value = builtin_export("_2=PESSOAL");
	TEST_ASSERT_EQUAL_INT(0, value);

	value = builtin_export("2_=PESSOAL");
	TEST_ASSERT_EQUAL_INT(1, value);

	value = builtin_export("=PESSOAL");
	TEST_ASSERT_EQUAL_INT(1, value);

	value = builtin_export("OLA=2PESSOAL");
	TEST_ASSERT_EQUAL_INT(0, value);

	value = builtin_export("OLA=2");
	TEST_ASSERT_EQUAL_INT(0, value);

	value = builtin_export("OLA=|");
	TEST_ASSERT_EQUAL_INT(0, value);

	value = builtin_export("OLA=%");
	TEST_ASSERT_EQUAL_INT(0, value);

	// value = builtin_export("\"OLA\"=%PESSOAL");
	// TEST_ASSERT_EQUAL_INT(0, value);

	// value = builtin_export("\'OLA\'=%PESSOAL");
	// TEST_ASSERT_EQUAL_INT(0, value);

	// value = builtin_export("\'OLA\'=\'%PESSOAL\'");
	// TEST_ASSERT_EQUAL_INT(0, value);

	// value = builtin_export("\'%OLA\'=\'%PESSOAL\'");
	// TEST_ASSERT_EQUAL_INT(1, value);

	// value = builtin_export("\"\'OLA\'\"=\'\"%PESSOAL\"\'");
	// TEST_ASSERT_EQUAL_INT(1, value);

	// value = builtin_export("\'\"OLA\"\'=\"\'%PESSOAL\'\"");
	// TEST_ASSERT_EQUAL_INT(1, value);

	// value = builtin_export("\"OLA\"=\'\"%PESSOAL\"\'");
	// TEST_ASSERT_EQUAL_INT(0, value);

	// value = builtin_export("\"OLA\"=\"\'%PESSOAL\'\"");
	// TEST_ASSERT_EQUAL_INT(0, value);

	// value = builtin_export("\"OLA\"=\"\"%PESSOAL\"\"");
	// TEST_ASSERT_EQUAL_INT(0, value);

	// value = builtin_export("\"OLA\"=\'\"%PESSOAL\"\'");
	// TEST_ASSERT_EQUAL_INT(0, value);

	// value = builtin_export("OLA=\"%PESSOAL\"");
	// TEST_ASSERT_EQUAL_INT(0, value);

	// value = builtin_export("OLA=\'%PESSOAL\'");
	// TEST_ASSERT_EQUAL_INT(0, value);

	// value = builtin_export("OLA=\"PESSOAL\"");
	// TEST_ASSERT_EQUAL_INT(0, value);

	// value = builtin_export("OLA=\'PESSOAL\'");
	// TEST_ASSERT_EQUAL_INT(0, value);

	value = builtin_export("OLA=PESSOAL");
	TEST_ASSERT_EQUAL_INT(0, value);
}