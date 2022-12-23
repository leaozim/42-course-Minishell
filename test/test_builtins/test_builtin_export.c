# include "../h_test.h"

void    test_builtin_export()
{
    int	value;

	value = builtin_export("OLA=");
	TEST_ASSERT_EQUAL_INT(0, value);

	value = builtin_export("OLA");
	TEST_ASSERT_EQUAL_INT(0, value);

	value = builtin_export("\"OLA\"");
	TEST_ASSERT_EQUAL_INT(0, value);

	value = builtin_export("OLA=PESSOAL");
	TEST_ASSERT_EQUAL_INT(0, value);

	value = builtin_export("OLA%");
	TEST_ASSERT_EQUAL_INT(1, value);

	value = builtin_export("OLA=%PESSOAL");
	TEST_ASSERT_EQUAL_INT(0, value);

	// value = builtin_export("\"OLA\"=%PESSOAL"); fazer uma função que tira as aspas da
	// TEST_ASSERT_EQUAL_INT(0, value);            string antes do sinal de igual

	value = builtin_export("%=PESSOAL");
	TEST_ASSERT_EQUAL_INT(1, value);

	value = builtin_export("\"%\"=PESSOAL");
	TEST_ASSERT_EQUAL_INT(1, value);

	value = builtin_export("\"%=PESSOAL\"");
	TEST_ASSERT_EQUAL_INT(1, value);

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



	// value = builtin_export("OLA%");
	// TEST_ASSERT_EQUAL_INT(1, value);

	// value = builtin_export("=");
	// TEST_ASSERT_EQUAL_INT(1, value);

	// value = builtin_export("=OLA");
	// TEST_ASSERT_EQUAL_INT(1, value);
	
	// value = builtin_export("_23=OLA");
	// TEST_ASSERT_EQUAL_INT(1, value);

	// value = builtin_export("23=OLA");
	// TEST_ASSERT_EQUAL_INT(1, value);
}