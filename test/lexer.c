# include <test.h>

// char **lexer_line(char *line)
// {
//     char **tokens;

//     tokens = ft_split(line, ' ');
//     return (tokens);
// }

// void test_str(void)
// {
//     char string[] = "ls -l -a ..";
//     char **expected = {"ls", "-l", "-a", ".."};

//     char **tokens = lexer(string);

//     TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tokens, 4);
// }

// void    test_lexer(void)
// {
//     RUN_TEST(test_str);
//     RUN_TEST(lexer_line);
// }