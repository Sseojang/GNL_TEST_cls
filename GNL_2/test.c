/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:30:45 by seojang           #+#    #+#             */
/*   Updated: 2024/04/12 10:30:49 by seojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUFFER_SIZE 3

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s2 && !s1)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		ret[i++] = s2[j++];
	ret[i] = '\0';
	return (ret);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	static char	*buf;
	int	tmp = 0;
	int	p = 0;
	int	i = 1;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (1)
	{
		if (tmp)
		{
			buf = ft_strjoin(buf, buf + tmp);
		}
		printf("%d 번째 버퍼 값\n", i++);
		printf("%d\n", (p = read(fd, buf + tmp, BUFFER_SIZE)));
		tmp += p;
		buf[tmp] = '\0';
		if (!p)
			break ;
		printf("%s\n", buf);
		if (p < BUFFER_SIZE)
			break ;
	}
	free(buf);
	close(fd);
	return 0;
}
