/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:22:21 by bmayer            #+#    #+#             */
/*   Updated: 2021/04/21 23:21:29 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

int 		ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_read(int fd, void *buf, size_t count);
char		*ft_strcpy(char * dst, const char * src);
char *		ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
ssize_t		ft_write(int fd, const void *buf, size_t count);
int			ft_atoi_base(char *str, char *base);
void		ft_list_push_front(t_list **begin_list, void *data);
int			ft_list_size(t_list *begin_list);
void		ft_list_sort(t_list **begin_list, int (*cmp)());
void		ft_list_remove_if(t_list **begin_list, void *data_ref,
				int (*cmp)(), void (*free_fct)(void *));

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
	int err1;
	int err2;

	errno = 0;
	ft_read(-1, buffer, 1);
	printf("ft_read :	fd = -1, errno = %i\n", errno);
	err1 = errno;
	errno = 0;
	read(-1, buffer, 1);
	printf("read :		fd = -1, errno = %i\n", errno);
	err2 = errno;
	if (err1 != err2)
		printf("ft_read test FAILURE\n");
	else
		printf("ft_read test SUCCESS\n");
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

void	ft_atoi_base_diff(char *str, char *base, int expected)
{
	int	result;

	result = ft_atoi_base(str, base);
	printf("str = |%s|\nbase = |%s|\nft_atoi_base = %i, expected = %i\n", str,
		base, result, expected);
	if (result != expected)
		printf("ft_atoi_base FAILURE\n");
	else
		printf("ft_atoi_base SUCCESS\n");
}

void	ft_atoi_base_test(void)
{
	printf("\n --->>> Test 1 <<<--- \n");
	ft_atoi_base_diff("101010", "01", 42);
	printf("\n --->>> Test 2 <<<--- \n");
	ft_atoi_base_diff("7FFFFFFF", "0123456789ABCDEF", 2147483647);
	printf("\n --->>> Test 3 <<<--- \n");
	ft_atoi_base_diff("-2147483648", "0123456789", -2147483648);
	printf("\n --->>> Test 4 <<<--- \n");
	ft_atoi_base_diff("-fion", "poneyvif", -3978);
	printf("\n++++++++++++++++++++++++++++++++\n");
	printf("\n --->>> Test 5 <<<--- \n");
	ft_atoi_base_diff("     \t\n\v\f\r-+--fiona_shrek", "poneyvif", -3978);
	printf("\n++++++++++++++++++++++++++++++++\n");

}

void	ft_list_push_front_test(void)
{
	char str[4][6] = {"Hello", "Salut", "Nihao", "Salam"};
	t_list	**t;
	t_list	*temp;
	t_list	*temp2;
	char	*temp3;
	int		i;
	int		fail;

	i = 0;
	fail = 0;
	temp = 0;
	t = &temp;
	ft_list_push_front(t, str[0]);
	ft_list_push_front(t, str[1]);
	ft_list_push_front(t, str[2]);;
	ft_list_push_front(t, str[3]);;
	while (*t)
	{
		temp2 = *t;
		*t = (*t)->next;
		temp3 = (char *)temp2->data;
		if (str[3-i] != temp3)
			fail = 1;
		printf("%s", temp3);
		if (i < 3)
			printf("->");
		else
			printf("\n");
		free(temp2);
		i++;
	}
	if (fail)
		printf("ft_list_push_front FAILURE\n");
	else
		printf("ft_list_push_front SUCCESS\n");
}

void	ft_list_size_test(void)
{
	char	str[4][6] = {"Hello", "Salut", "Nihao", "Salam"};
	int		i = 0;
	t_list	lst[4];
	t_list	*temp = 0;
	int		test;
	int		fail = 0;

	if ((test = ft_list_size(temp)))
		fail = 1;
	printf("Null list size: %i (expected:0)\n", test);
	while (i < 4)
	{
		lst[i].next = temp;
		lst[i].data = str[i];
		temp = &lst[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		printf("%s", (char*)lst[i].data);
		if (i < 3)
			printf("->");
		else
			printf("\n");
		i++;
	}
	if((test = ft_list_size(temp)) != 4)
		fail = 1;
	printf("Example list size: %i (expected:4)\n", test);
	if (fail)
		printf("ft_list_size FAILURE\n");
	else
		printf("ft_list_size SUCCESS\n");
}

int		ft_intcmp(int *a, int *b)
{
	int a_val = *a;
	int b_val = *b;
	if (a_val > b_val)
		return (1);
	if (a_val < b_val)
		return (-1);
	return (0);
}

void	ft_list_sort_test(void)
{
	int		nb[10] = {5, 0, 7, 4, 2, 6, 1, 8, 3, 9};
	int		i = 0;
	t_list	lst[10];
	t_list	**begin_list;
	t_list	*temp = 0;
	t_list	*temp2 = 0;
	int		prev = -1;
	int		curr;
	int		fail = 0;

	while (i < 10)
	{
		lst[i].next = temp;
		lst[i].data = &nb[i];
		temp = &lst[i];
		i++;
	}
	temp2 = temp;
	while (temp2)
	{
		printf("%i", *((int *)temp2->data));
		temp2 = temp2->next;
		if (temp2)
			printf("->");
		else
			printf("\n");
	}
	begin_list = &temp;
	ft_list_sort(begin_list, ft_intcmp);
	temp = *begin_list;
	while (temp)
	{
		curr = *(int *)temp->data;
		printf("%i", curr);
		temp = temp->next;
		if (temp)
			printf("->");
		else
			printf("\n");
		if (curr < prev)
			fail = 1;
		prev = curr;
	}
	if (fail)
		printf("ft_list_sort FAILURE\n");
	else
		printf("ft_list_sort SUCCESS\n");
}

void	ft_list_remove_if_test(void)
{
	int		i = 0;
	int		j = 0;
	t_list	lst[10];
	int		*nb_temp;
	void	*nxt_temp = 0;
	t_list	*temp;
	int		*data;
	t_list	**begin_list;
	int		fail = 0;
	int		ref = 1;

	while (i < 10)
	{
		if (!(nb_temp = (int *)malloc(sizeof(int))))
		{
			while (j < i)
			{
				free(lst[j].data);
				j++;
			}
			return;
		}
		if ((i != 3) & (i != 5) & (i != 8) & (i != 9))
			*nb_temp = 0;
		else
			*nb_temp = 1;
		lst[i].next = nxt_temp;
		lst[i].data = nb_temp;
		nxt_temp = &lst[i];
		i++;
	}
	temp = nxt_temp;
	while (temp)
	{
		printf("%i", *((int *)temp->data));
		temp = temp->next;
		if (temp)
			printf("->");
		else
			printf("\n");
	}
	begin_list = (t_list **)&nxt_temp;
	ft_list_remove_if(begin_list, &ref, ft_intcmp, free);
	temp = *begin_list;
	while (temp)
	{
		data = temp->data;
		printf("%i", *data);
		if (*data)
			fail = 1;
		free (data);
		temp = temp->next;
		if (temp)
			printf("->");
		else
			printf("\n");
	}
	if (fail)
		printf("ft_list_remove_if FAILURE\n");
	else
		printf("ft_list_remove_if SUCCESS\n");
}



int		main(void)
{
	ft_title("ft_read");
	ft_read_test();
	ft_title("ft_strcmp");
	ft_strcmp_test();
	ft_title("ft_strcpy");
	ft_strcpy_test();
	ft_title("ft_strdup");
	ft_strdup_test();
	ft_title("ft_strlen");
	ft_strlen_test();
	ft_title("ft_write");
	ft_write_test();
	ft_title("ft_atoi_base");
	ft_atoi_base_test();
	ft_title("ft_list_push_front");
	ft_list_push_front_test();
	ft_title("ft_list_size");
	ft_list_size_test();
	ft_title("ft_list_sort");
	ft_list_sort_test();
	ft_title("ft_list_remove_if");
	ft_list_remove_if_test();
}
