/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:43:30 by bmayer            #+#    #+#             */
/*   Updated: 2021/03/16 22:43:32 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int 		ft_strcmp(const char *s1, const char *s2);
size_t		ft_read(int fd, void *buf, size_t count);
char		*ft_strcpy(char * dst, const char * src);
char *		ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
size_t		ft_write(int fd, const void *buf, size_t count);

#endif
