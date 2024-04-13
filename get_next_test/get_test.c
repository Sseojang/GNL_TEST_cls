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

#include "get_next_test.h"

char	*ft_line_check(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = ft_strchr(str, '\n') + 1;
	j = ft_strlen(str);
	ret = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!ret)
		return (NULL);
	ret = ft_strncpy(ret, str + i, j - i);
	str = ret;
	free(ret);
	ret = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	ssize_t	read_bytes;
	static char	*backup;
	char	*buf;
	char	*result;
	char	*tmp;

	read_bytes = 0;
	if (!backup)
		backup = ft_strdup("");
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE)+1);
	buf[0] = '\0';
	if (fd < 0 || !BUFFER_SIZE || !buf)
		return (NULL);
	while ((read_bytes = read(fd, buf, BUFFER_SIZE)))
	{
		if (read_bytes > 0)
			buf[read_bytes] = '\0';
		backup = ft_strjoin(backup, buf);
		if (ft_strchr(backup, '\n'))
		{
			result = (char *)malloc(sizeof(char) * ft_strchr(backup, '\n'));
			if (!result)
				return (0);
			result = ft_strncpy(result, backup, ft_strchr(backup, '\n'));
			backup = ft_line_check(backup);
			return (result);
		}
	}
	if (!read_bytes)
	{
		free(buf);
		buf = NULL;
		free(backup);
		backup =NULL;
		return (NULL);
	}
	return (NULL);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char	*p;

	while ((p = get_next_line(fd)))
	{
		printf("%s", p);
		free(p);
	}
	close(fd);
	return 0;
}
