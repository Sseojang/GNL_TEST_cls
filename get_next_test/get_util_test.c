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

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int	i;
	int	j;

	i = 0;
	j = 0;
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