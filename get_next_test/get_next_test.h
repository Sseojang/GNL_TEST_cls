/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:27:44 by seojang           #+#    #+#             */
/*   Updated: 2024/04/04 18:26:51 by seojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_TEST_H

# define GET_NEXT_TEST_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 3

int	ft_strlen(const char *str);
int	ft_strchr(char *str, char c);
char	*ft_strncpy(char *dest, const char *src, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_line_check(char *str);
char	*get_next_line(int fd);

#endif /* GET_NEXT_TEST_H*/