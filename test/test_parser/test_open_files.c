#include "../h_test.h"
#include <fcntl.h>

void	check_open_infile(void)
{
	int infd;
	t_bool error;

	error = FALSE;
	infd = 10;
	open_infile("files/file1", O_RDONLY, &infd);
	TEST_ASSERT_NOT_EQUAL_INT(-1, infd);
}

void	check_open_append_file(void)
{
	int infd;
	char buff[14];
	t_bool error;

	error = FALSE;
	infd = open("files/file2", O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (infd == -1)
		perror("1");
	close(infd);
	infd = 10;
	open_infile("files/file2", O_CREAT | O_WRONLY | O_APPEND, &infd);
	if (infd == -1)
		perror("2");
	write(infd, "cavalinho", 9);
	close(infd);
	open_infile("files/file2", O_CREAT | O_WRONLY | O_APPEND, &infd);
	if (infd == -1)
		perror("3");
	write(infd, "outra", 5);
	close(infd);
	infd = open("files/file2", O_RDONLY);
	read(infd, &buff, 14);
	TEST_ASSERT_EQUAL_STRING("cavalinhooutra", buff);
	TEST_ASSERT_NOT_EQUAL_INT(-1, infd);
	close(infd);
}

void	check_open_outfile(void)
{
	int infd;
	char buff[1];
	t_bool error;

	error = FALSE;
	infd = 10;
	open_outfile("files/file3", O_CREAT | O_WRONLY | O_TRUNC, &infd);
	if (infd == -1)
		perror("1");
	close(infd);
	infd = 10;
	open_infile("files/file3", O_CREAT | O_WRONLY | O_TRUNC, &infd);
	if (infd == -1)
		perror("2");
	write(infd, "a", 9);
	infd = open("files/file3", O_RDONLY);
	read(infd, &buff, 1);
	TEST_ASSERT_EQUAL_STRING("a", buff);
	close(infd);
	open_infile("files/file3", O_CREAT | O_WRONLY | O_TRUNC, &infd);
	if (infd == -1)
		perror("3");
	write(infd, "b", 5);
	close(infd);
	infd = open("files/file3", O_RDONLY);
	read(infd, &buff, 1);
	TEST_ASSERT_EQUAL_STRING("b", buff);
	TEST_ASSERT_NOT_EQUAL_INT(-1, infd);
	close(infd);
}

void	test_open_files(void)
{
	RUN_TEST(check_open_infile);
	RUN_TEST(check_open_append_file);
	RUN_TEST(check_open_outfile);
}
