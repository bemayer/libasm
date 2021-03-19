#include "libasm.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

void	ft_title(char *str)
{
	size_t len;
	size_t i;

	printf("\n+------------------------------+\n");
	printf("|");
	len = strlen(str);
	i = 0;
	while (i < (30 - len) / 2)
	{
		printf(" ");
		i++;
	}
	printf("%s", str);
	i += len;
	while (i++ < 30)
		printf(" ");
	printf("|");
	printf("\n+------------------------------+\n");
}

void	ft_strlen_diff(char *str)
{
	int len1;
	int len2;

	len1 = ft_strlen(str);
	len2 = strlen(str);
	printf("str = |%s|\nft_strlen = %i, strlen = %i\n", str, len1, len2);
	if (len1 != len2)
		printf("ft_strlen FAILURE\n");
	else
		printf("ft_strlen SUCCESS\n");
}

void	ft_strlen_test(void)
{
	printf("\n --->>> Test 1 <<<--- \n");
	ft_strlen_diff("Hello World!");
	printf("\n --->>> Test 2 <<<--- \n");
	ft_strlen_diff("");
	printf("\n --->>> Test 3 <<<--- \n");
	ft_strlen_diff("This string was made in the only purpose of being absurdly long, so you may have guessed it's going to be absurdly boring as well. I recommend not bothering too much reading it, but of course, do whatever you think is good for you. I assume that if life has brought you to the point where you are still reading this, then maybe you should consult a doctor, but again you're a mature and grown person. At least I hope so, because if you're not, then maybe I should call the police. I wouldn't want this text to take too much space in this file, so I'm going to stop here as I think this is long enough for a testing purpose. Thank you so much for reading.");
	printf("\n++++++++++++++++++++++++++++++++\n");
}

void	ft_strcmp_diff(char *s1, char *s2)
{
	int cmp1;
	int cmp2;

	cmp1 = ft_strcmp(s1, s2);
	cmp2 = strcmp(s1, s2);
	printf("s1 = |%s|, s2 = |%s|\nft_strcmp = %i, strcmp = %i\n", s1, s2, cmp1, cmp2);
	if (cmp1 != cmp2)
		printf("ft_strcmp FAILURE\n");
	else
		printf("ft_strcmp SUCCESS\n");
}

void	ft_strcmp_test(void)
{
	printf("\n --->>> Test 1 <<<--- \n");
	ft_strcmp_diff("Hello World!", "Hello World!");
	printf("\n --->>> Test 2 <<<--- \n");
	ft_strcmp_diff("", "");
	printf("\n --->>> Test 3 <<<--- \n");
	ft_strcmp_diff("", "\0A");
	printf("\n --->>> Test 4 <<<--- \n");
	ft_strcmp_diff("12345", "12354");
	printf("\n --->>> Test 5 <<<--- \n");
	ft_strcmp_diff(";)(*&^%$#@!)", ";)(*&^%$#@!)");
	printf("\n --->>> Test 6 <<<--- \n");
	ft_strcmp_diff("Hello World!", "Hello ");
	printf("\n --->>> Test 7 <<<--- \n");
	ft_strcmp_diff("Hello ", "Hello World!");
	printf("\n++++++++++++++++++++++++++++++++\n");
}

void	ft_strcpy_diff(char *src)
{
	char *cpy1;
	char *cpy2;

	errno = 0;
	if (!(cpy1 = malloc(sizeof(char) * (ft_strlen(src) + 1))))
	{
		perror("error : ");
		exit(1);
	}
	if (!(cpy2 = malloc(sizeof(char) * (strlen(src) + 1))))
	{
		perror("error : ");
		exit(1);
	}
	ft_strcpy(cpy1, src);
	strcpy(cpy2, src);
	printf("src = |%s|\nft_strcpy = |%s|, strcpy = |%s|\n", src, cpy1, cpy2);
	if (strcmp(cpy1, cpy2))
		printf("ft_strcpy test FAILURE\n");
	else
		printf("ft_strcpy test SUCCESS\n");
	free(cpy1);
	free(cpy2);
}

void	ft_strcpy_test(void)
{
	printf("\n --->>> Test 1 <<<--- \n");
	ft_strcpy_diff("Hello World!");
	printf("\n --->>> Test 2 <<<--- \n");
	ft_strcpy_diff("");
	printf("\n++++++++++++++++++++++++++++++++\n");
}

void	ft_strdup_diff(char *str)
{
	char *dup1;
	char *dup2;

	if (!(dup1 = ft_strdup(str)))
	{
		printf("error\n");
		exit(1);
	}
	if (!(dup2 = strdup(str)))
	{
		printf("error\n");
		exit(1);
	}
	printf("str = |%s|, dup1 = |%s|, dup2 = |%s|\n", str, dup1, dup2);
	if (strcmp(dup1, dup2))
		printf("ft_strdup test FAILURE\n");
	else
		printf("ft_strdup test SUCCESS\n");
	free(dup1);
	free(dup2);
}

void	ft_strdup_test(void)
{
	printf("\n --->>> Test 1 <<<--- \n");
	ft_strdup_diff("Hello World!");
	printf("\n --->>> Test 2 <<<--- \n");
	ft_strdup_diff("");
	printf("\n++++++++++++++++++++++++++++++++\n");
}

void	ft_write_diff(int fd, char *str, int len)
{
	int ret1;
	int ret2;
	int err1;
	int err2;

	errno = 0;
	ret1 = ft_write(fd, str, len);
	if (fd == 1)
		write(1, "\n", 1);
	err1 = errno;
	errno = 0;
	ret2 = write(fd, str, len);
	if (fd == 1)
		write(1, "\n", 1);
	err2 = errno;
	printf("str = |%s|, fd = %i, len = %i\n", str, fd, len);
	printf("ft_write_ret = |%i|, write_ret = |%i|\n", ret1, ret2);
	printf("ft_write_err = |%i|, write_err = |%i|\n", err1, err2);
	if (ret1 == ret2 && err1 == err2)
		printf("ft_write test SUCCESS\n");
	else
		printf("ft_write test FAILURE\n");

}

void	ft_write_test(void)
{
	int fd;

	printf("\n --->>> Test 1 <<<--- \n");
	ft_write_diff(1, "Hello World!", 13);
	printf("\n --->>> Test 2 <<<--- \n");
	ft_write_diff(1, "", 0);
	printf("\n --->>> Test 3 <<<--- \n");
	fd = open("./hello.txt", O_WRONLY | O_CREAT, 777);
	ft_write_diff(fd, "Hello World!", 12);
	close(fd);
	printf("\n --->>> Test 4 <<<--- \n");
	fd = open("./empty.txt", O_WRONLY | O_CREAT, 777);
	ft_write_diff(fd, "", 1);
	close(fd);
	printf("\n --->>> Test 5 <<<--- \n");
	ft_write_diff(-1, "Hello World!", 12);
	printf("\n --->>> Test 6 <<<--- \n");
	ft_write_diff(1, "Hello World!", -1);
	printf("\n++++++++++++++++++++++++++++++++\n");
}

void	ft_read_diff(int buffersize)
{
	char	*buffer1;
	char	*buffer2;
	int		ret1;
	int		ret2;
	int		fd;

	if (!(buffer1 = malloc(sizeof(char) * (buffersize + 1))))
	{
		printf("error : couldn't allocate %i BYTES\n", buffersize);
		exit(1);
	}
	bzero(buffer1, buffersize + 1);
	if (!(buffer2 = malloc(sizeof(char) * (buffersize + 1))))
	{
		printf("error : couldn't allocate %i BYTES\n", buffersize);
		exit(1);
	}
	bzero(buffer2, buffersize + 1);
	fd = open("main.c", O_RDONLY);
	printf("fd = %i, buffersize = %i\n", fd, buffersize);
	errno = 0;
	ret1 = ft_read(fd, buffer1, buffersize);
	printf("ft_read : 	|%s|, return = %i, errno = %i\n", buffer1, ret1, errno);
	close(fd);
	fd = open("main.c", O_RDONLY);
	errno = 0;
	ret2 = read(fd, buffer2, buffersize);
	close(fd);
	printf("read :		|%s|, return = %i, errno = %i\n", buffer2, ret2, errno);
	if (strcmp(buffer1, buffer2) || ret1 != ret2)
		printf("ft_read test FAILURE\n");
	else
		printf("ft_read test SUCCESS\n");
	free(buffer1);
	free(buffer2);
}

void	ft_read_wrong(void)
{
	char buffer[1];

	errno = 0;
	ft_read(-1, buffer, 1);
	printf("ft_read :	fd = -1, errno = %i\n", errno);
	errno = 0;
	read(-1, buffer, 1);
	printf("read :		fd = -1, errno = %i\n", errno);
}

void	ft_read_test(void)
{
	printf("\n --->>> Test 1 <<<--- \n");
	ft_read_diff(1);
	printf("\n --->>> Test 2 <<<--- \n");
	ft_read_diff(100);
	printf("\n --->>> Test 3 <<<--- \n");
	ft_read_diff(0);
	printf("\n --->>> Test 4 <<<--- \n");
	ft_read_diff(10);
	printf("\n --->>> Test 5 <<<--- \n");
	ft_read_wrong();
	printf("\n++++++++++++++++++++++++++++++++\n");
}

int		main(void)
{
	ft_title("ft_strlen");
	ft_strlen_test();
	ft_title("ft_strcmp");
	ft_strcmp_test();
	ft_title("ft_strcpy");
	ft_strcpy_test();
	ft_title("ft_strdup");
	ft_strdup_test();
	ft_title("ft_write");
	ft_write_test();
	ft_title("ft_read");
	ft_read_test();
}
