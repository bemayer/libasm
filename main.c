/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 18:46:10 by bmayer            #+#    #+#             */
/*   Updated: 2021/03/16 22:43:27 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	ok(void)
{
	printf("\033[1;32m");
	printf("OK\n");
	printf("\033[0m");
}

void	nok(void)
{
	printf("\033[1;31m");
	printf("NOK\n");
	printf("\033[0m");
}

int		check_read()
{
	char	dest[6];
	int		fd;
	int		ret;

	ret = 1;
	fd = open("testread.txt", O_RDONLY);
	ft_read(fd, dest, 35);
	if (ft_strcmp(dest, "hello"))
		ret = 0;
	close (fd);
	return (ret);
}

int		check_strcmp()
{
	char *test[6];
	int i = 0;
	int j = 0;

	test[0] = "hello !";
	test[1] = "a";
	test[2] = "lorem\tipsum\tdolor\nsit\namet\n";
	test[3] = "";
	test[4] = "\n\n\f\r\t";
	test[5] = "   ";

	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			int ft_cmp = ft_strcmp(test[i], test[j]);
			int	cmp = strcmp(test[i], test[j]);
			if ((ft_cmp == 0 && cmp != 0) ||
				(ft_cmp > 0 && cmp <= 0) ||
				(ft_cmp < 0 && cmp >= 0))
			{
				printf("test[%i]:%s\n", i, test[i]);
				printf("test[%i]:%s\n", j, test[j]);
				printf("ft_strcmp: %i\n", ft_cmp);
				printf("strcmp: %i\n", cmp);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		check_strcpy()
{
	char src[10] = "Hello";
	char dest[10];
	char dest2[10];
	char *test = ft_strcpy(dest, src);
	char *test2 = strcpy(dest2, src);
	if(strncmp(dest, dest2, 6) | (test == test2))
		return (0);
	return (1);
}

int		check_strdup()
{
	char src[8] = "Hello !";
	char *dest = ft_strdup(src);
	if(strcmp(src, dest)){
		free(dest);
		return (0);
	}
	free(dest);
	return (1);
}

int		check_strlen()
{
	char *test[6];
	int i = 0;

	test[0] = "hello !";
	test[1] = "a";
	test[2] = "lorem\tipsum\tdolor\nsit\namet\n";
	test[3] = "";
	test[4] = "\n\n\f\r\t";
	test[5] = "   ";

	while (i < 6)
	{
		if (ft_strlen(test[i]) != strlen(test[i]))
			return (0);
		i++;
	}
	return (1);
}

int		check_write()
{
	write(1, "hello", 6);
}

int		main(void)
{
	printf("\nCheck read\n");
	check_read() ? ok() : nok();

	printf("\nCheck strcmp\n");
	check_strcmp() ? ok() : nok();

	printf("\nCheck strcpy\n");
	check_strcpy() ? ok() : nok();

	printf("\nCheck strdup\n");
	check_strdup() ? ok() : nok();

	printf("\nCheck strlen\n");
	check_strlen() ? ok() : nok();

	printf("\nCheck write\n");
	check_write() ? ok() : nok();
}
